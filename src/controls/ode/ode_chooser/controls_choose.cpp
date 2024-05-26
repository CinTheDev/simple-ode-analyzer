#include "controls_choose.h"
#include "ode_oscillation_harmonic.h"

ControlsChoose::ControlsChoose(wxWindow* parent) : wxScrolledWindow(parent) {
    sizer_main = new wxStaticBoxSizer(wxVERTICAL, this, "Select ODEs");

    button_create_entry = new wxButton(this, wxID_ANY, "Add ODE");
    sizer_main->Add(button_create_entry, 0, wxEXPAND | wxALL & ~wxBOTTOM, 10);

    button_create_entry->Bind(wxEVT_BUTTON, &ControlsChoose::on_button_create, this);

    SetSizer(sizer_main);

    SetScrollRate(0, 5);
}

ControlsChoose::~ControlsChoose() { }

void ControlsChoose::add_entry() {
    OdeEntry* new_entry = new Ode_Oscillation_Harmonic(this);
    new_entry->button_remove->Bind(wxEVT_BUTTON, &ControlsChoose::on_child_remove, this);
    new_entry->button_up->Bind(wxEVT_BUTTON, &ControlsChoose::on_child_up, this);
    new_entry->button_down->Bind(wxEVT_BUTTON, &ControlsChoose::on_child_down, this);

    sizer_main->Add(new_entry, 0, wxEXPAND | wxLEFT | wxRIGHT, 10);

    update_entry_buttons();
    FitInside();
    Layout();
    GetParent()->Layout();
}

void ControlsChoose::on_button_create(wxCommandEvent& evt) {
    add_entry();
}

void ControlsChoose::on_child_up(wxCommandEvent& evt) {
    OdeEntry* entry = get_entry_from_event(evt);
    size_t index = get_entry_index(entry);

    if (index - 1 < 1) {
        std::cout << "WARNING: Cannot move entry up" << std::endl;
        return;
    }

    swap_entries(index, index - 1);
    update_entry_buttons();
    Layout();
}

void ControlsChoose::on_child_down(wxCommandEvent& evt) {
    OdeEntry* entry = get_entry_from_event(evt);
    size_t index = get_entry_index(entry);

    if (index + 1 >= sizer_main->GetItemCount()) {
        std::cout << "WARNING: Cannot move entry lower" << std::endl;
        return;
    }

    swap_entries(index, index + 1);
    update_entry_buttons();
    Layout();
}

void ControlsChoose::on_child_remove(wxCommandEvent& evt) {
    OdeEntry* entry = get_entry_from_event(evt);

    for (size_t i = 0; i < sizer_main->GetItemCount(); i++) {
        if ( (wxWindow*) sizer_main->GetItem(i)->GetWindow() == (wxWindow*) entry) {
            sizer_main->Remove(i);
            delete entry;
        }
    }
    
    update_entry_buttons();
    FitInside();
    Layout();
    GetParent()->Layout();
}

void ControlsChoose::on_calculate(wxCommandEvent& evt) {
    entries_calculate();
    SendResults();
}

void ControlsChoose::SendResults() {
    // Request settings
    Settings_Common settings_common;
    Settings_Approx settings_approx;

    request_ode_settings(&settings_common, &settings_approx);

    // ODE Data event
    OdeData ode_data;
    ode_data.amount_results = sizer_main->GetItemCount() - 1;

    if (ode_data.amount_results < 1) return;

    ode_data.results_x = get_all_results_x(ode_data.amount_results);
    ode_data.results_y = get_all_results_x(ode_data.amount_results);
    ode_data.result_lengths = get_all_lengths(ode_data.amount_results);
    ode_data.colours = get_all_colours(ode_data.amount_results);

    OdePointerEvent evt_ode_pointer(EVT_ODE_POINTER, GetId(), ode_data);
    evt_ode_pointer.SetEventObject(this);
    evt_ode_pointer.ResumePropagation(__INT_MAX__);
    ProcessEvent(evt_ode_pointer);

    // Step x
    SettingsCommonEvent evt_settings_common(SETTINGS_COMMON_UPDATE, GetId(), settings_common);
    evt_settings_common.SetEventObject(this);
    evt_settings_common.ResumePropagation(__INT_MAX__);
    ProcessEvent(evt_settings_common);
}

double** ControlsChoose::get_all_results_x(size_t amount_results) {
    double** results_x = new double*[amount_results];

    for (size_t i = 0; i < amount_results; i++) {
        OdeEntry* entry = (OdeEntry*) sizer_main->GetItem(i + 1)->GetWindow();

        size_t result_length = entry->get_result_length();
        double* entry_results = entry->get_result_x();

        double* copy_results = new double[result_length];
        memcpy(copy_results, entry_results, sizeof(double) * result_length);
        results_x[i] = copy_results;
    }
    
    return results_x;
}

double** ControlsChoose::get_all_results_y(size_t amount_results) {
    double** results_x = new double*[amount_results];

    for (size_t i = 0; i < amount_results; i++) {
        OdeEntry* entry = (OdeEntry*) sizer_main->GetItem(i + 1)->GetWindow();

        size_t result_length = entry->get_result_length();
        double* entry_results = entry->get_result_y();

        double* copy_results = new double[result_length];
        memcpy(copy_results, entry_results, sizeof(double) * result_length);
        results_x[i] = copy_results;
    }
    
    return results_x;
}

uint32_t* ControlsChoose::get_all_colours(size_t amount_results) {
    uint32_t* results = new uint32_t[amount_results];

    for (size_t i = 0; i < amount_results; i++) {
        OdeEntry* entry = (OdeEntry*) sizer_main->GetItem(i + 1)->GetWindow();
        results[i] = entry->get_colour();
    }

    return results;
}

size_t* ControlsChoose::get_all_lengths(size_t amount_results) {
    size_t* results = new size_t[amount_results];

    for (size_t i = 0; i < amount_results; i++) {
        OdeEntry* entry = (OdeEntry*) sizer_main->GetItem(i + 1)->GetWindow();
        results[i] = entry->get_result_length();
    }

    return results;
}

void ControlsChoose::request_ode_settings(Settings_Common* settings_common, Settings_Approx* settings_approx) {
    SettingsOdeRequest request = SettingsOdeRequest(SETTINGS_ODE_REQUEST, GetId(), settings_common, settings_approx);
    request.ResumePropagation(__INT_MAX__);
    request.SetEventObject(this);
    ProcessEvent(request);

    if (settings_common == nullptr || settings_approx == nullptr) {
        std::cout << "WARNING: Requested settings are null" << std::endl;
    }
}

OdeEntry* ControlsChoose::get_entry_from_event(wxCommandEvent& evt) {
    wxButton* evt_button = reinterpret_cast<wxButton*>(evt.GetEventObject());
    OdeEntry* entry = (OdeEntry*) evt_button->GetParent();
    return entry;
}

size_t ControlsChoose::get_entry_index(OdeEntry* entry) {
    for (size_t i = 0; i < sizer_main->GetItemCount(); i++) {
        if ( (wxWindow*) sizer_main->GetItem(i)->GetWindow() == (wxWindow*) entry) {
            return i;
        }
    }

    std::cout << "WARNING: Entry not found" << std::endl;
    return SIZE_MAX;
}

void ControlsChoose::update_entry_buttons() {
    for (size_t i = 1; i < sizer_main->GetItemCount(); i++) {
        bool button_up = (i - 1) >= 1;
        bool button_down = (i + 1) < sizer_main->GetItemCount();

        OdeEntry* entry = (OdeEntry*) sizer_main->GetItem(i)->GetWindow();
        entry->enable_buttons(button_up, button_down);
    }
}

void ControlsChoose::entries_calculate() {
    for (size_t i = 1; i < sizer_main->GetItemCount(); i++) {
        OdeEntry* entry = (OdeEntry*) sizer_main->GetItem(i)->GetWindow();
        entry->calculate();
    }
}

void ControlsChoose::swap_entries(size_t index_1, size_t index_2) {
    wxSizerItem* item_1 = sizer_main->GetItem(index_1);
    wxSizerItem* item_2 = sizer_main->GetItem(index_2);

    wxWindow* entry_1 = item_1->GetWindow();
    wxWindow* entry_2 = item_2->GetWindow();

    item_1->AssignWindow(entry_2);
    item_2->AssignWindow(entry_1);
}
