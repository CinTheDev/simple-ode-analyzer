#include "controls_choose.h"

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
    OdeEntry* new_entry = new OdeEntry(this);
    new_entry->button_remove->Bind(wxEVT_BUTTON, &ControlsChoose::on_child_remove, this);

    sizer_main->Add(new_entry, 0, wxEXPAND | wxLEFT | wxRIGHT, 10);

    FitInside();
    Layout();
    GetParent()->Layout();
}

void ControlsChoose::on_button_create(wxCommandEvent& evt) {
    add_entry();
}

void ControlsChoose::on_child_remove(wxCommandEvent& evt) {
    wxButton* evt_button = reinterpret_cast<wxButton*>(evt.GetEventObject());
    wxWindow* entry = evt_button->GetParent();

    for (size_t i = 0; i < sizer_main->GetItemCount(); i++) {
        if ( (wxWindow*) sizer_main->GetItem(i)->GetWindow() == entry) {
            sizer_main->Remove(i);
            delete entry;
        }
    }
    
    FitInside();
    Layout();
    GetParent()->Layout();
}

void ControlsChoose::on_calculate(wxCommandEvent& evt) {
    SendResults();
}

void ControlsChoose::SendResults() {
    // Request settings
    Settings_Common settings_common;
    Settings_Approximation settings_approx;

    request_ode_settings(&settings_common, &settings_approx);

    // ODE pointer
    size_t amount_results, result_length;
    double** ode_results = get_all_results(amount_results, result_length, settings_common, settings_approx);
    uint32_t* ode_colours = get_all_colours();

    OdePointerEvent evt_ode_pointer(EVT_ODE_POINTER, GetId(), ode_results, ode_colours, amount_results, result_length);
    evt_ode_pointer.SetEventObject(this);
    evt_ode_pointer.ResumePropagation(__INT_MAX__);
    ProcessEvent(evt_ode_pointer);

    // Step x
    SettingsCommonEvent evt_settings_common(SETTINGS_COMMON_UPDATE, GetId(), settings_common);
    evt_settings_common.SetEventObject(this);
    evt_settings_common.ResumePropagation(__INT_MAX__);
    ProcessEvent(evt_settings_common);
}

double** ControlsChoose::get_all_results(size_t& amount_results, size_t& result_length, Settings_Common settings_common, Settings_Approximation settings_approx) {
    amount_results = sizer_main->GetItemCount() - 1;

    if (amount_results < 1) return nullptr;

    double** results = new double*[amount_results];

    for (size_t i = 0; i < amount_results; i++) {
        OdeEntry* entry = (OdeEntry*) sizer_main->GetItem(i + 1)->GetWindow();
        double* entry_results = entry->get_ode_results(result_length, settings_common, settings_approx);
        double* copy_results = new double[result_length];
        memcpy(copy_results, entry_results, sizeof(double) * result_length);
        results[i] = copy_results;
    }

    return results;
}

uint32_t* ControlsChoose::get_all_colours() {
    size_t amount_results = sizer_main->GetItemCount() - 1;

    if (amount_results < 1) return nullptr;

    uint32_t* results = new uint32_t[amount_results];

    for (size_t i = 0; i < amount_results; i++) {
        OdeEntry* entry = (OdeEntry*) sizer_main->GetItem(i + 1)->GetWindow();
        results[i] = entry->get_colour();
    }

    return results;
}

void ControlsChoose::request_ode_settings(Settings_Common* settings_common, Settings_Approximation* settings_approx) {
    SettingsOdeRequest request = SettingsOdeRequest(SETTINGS_ODE_REQUEST, GetId(), settings_common, settings_approx);
    request.ResumePropagation(__INT_MAX__);
    request.SetEventObject(this);
    ProcessEvent(request);

    if (settings_common == nullptr || settings_approx == nullptr) {
        std::cout << "WARNING: Requested settings are null" << std::endl;
    }
}
