#include "controls_choose.h"

ControlsChoose::ControlsChoose(wxWindow* parent) : wxScrolledWindow(parent) {
    sizer_main = new wxStaticBoxSizer(wxVERTICAL, this, "Select ODEs");

    button_create_entry = new wxButton(this, wxID_ANY, "Add ODE");
    sizer_main->Add(button_create_entry, 0, wxEXPAND | wxALL & ~wxBOTTOM, 10);

    button_create_entry->Bind(wxEVT_BUTTON, &ControlsChoose::on_button_create, this);

    SetSizer(sizer_main);

    SetScrollRate(0, 5);

    // ODE stuff
    //amount_odes = 0;
    //odes = new ODE*[1];
    //ode_colours = new uint32_t[1];
}

ControlsChoose::~ControlsChoose() {
    //purge_odes();
}

void ControlsChoose::add_entry() {
    OdeEntry* new_entry = new OdeEntry(this);
    new_entry->button_remove->Bind(wxEVT_BUTTON, &ControlsChoose::on_child_remove, this);

    sizer_main->Add(new_entry, 0, wxEXPAND | wxLEFT | wxRIGHT, 10);

    FitInside();
    Layout();
    GetParent()->Layout();
}

/*
OdeListValues* ControlsChoose::construct_list_values(size_t& list_length) {
    list_length = sizer_main->GetItemCount() - 1;

    if (list_length < 1) return nullptr;

    OdeListValues* list_values = new OdeListValues[list_length];

    for (size_t i = 0; i < list_length; i++) {
        OdeEntry* entry = static_cast<OdeEntry*>(sizer_main->GetItem(i + 1)->GetWindow());
        list_values[i] = entry->construct_values();
    }

    return list_values;
}
*/

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

void ControlsChoose::on_settings_update(SettingsOdeEvent& evt) {
    settings_common = evt.get_settings_common();
    settings_approx = evt.get_settings_approx();
}

void ControlsChoose::on_calculate(wxCommandEvent& evt) {
    //regenerate_odes();

    //update_ode_settings();

    //for (int i = 0; i < amount_odes; i++) {
    //    odes[i]->calculate();
    //}

    SendResults();
}

void ControlsChoose::SendResults() {
    // ODE pointer
    size_t amount_results, result_length;
    double** ode_results = get_all_results(amount_results, result_length);
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

double** ControlsChoose::get_all_results(size_t& amount_results, size_t& result_length) {
    /*
    amount_results = amount_odes;

    if (amount_results < 1) return nullptr;

    result_length = odes[0]->get_length();

    double** results = new double*[amount_results];

    for (size_t i = 0; i < amount_results; i++) {
        results[i] = odes[i]->get_result();
    }

    return results;
    */
    amount_results = sizer_main->GetItemCount() - 1;

    if (amount_results < 1) return nullptr;

    double** results = new double*[amount_results];

    for (size_t i = 0; i < amount_results; i++) {
        OdeEntry* entry = (OdeEntry*) sizer_main->GetItem(i + 1)->GetWindow();
        results[i] = entry->get_ode_results(result_length);
        // TODO: Copy results
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

/*
ODE* ControlsChoose::instance_ode(OdeTypes ode_type) {
    switch (ode_type) {
        case OdeTypes::HarmonicOscillation:
            return new ODE_Harmonic(settings_common, settings_approx);

        case OdeTypes::GravitationalOscillation:
            return new ODE_V_Oscillation(settings_common, settings_approx);

        default:
            std::cout << "WARNING [ControlsODE::instance_ode()]: Unhandled OdeTypes enum" << std::endl;
            return nullptr;
    }
}

void ControlsChoose::update_ode_settings() {
    for(int i = 0; i < amount_odes; i++) {
        odes[i]->apply_settings(settings_common);
        odes[i]->apply_settings(settings_approx);
    }
}

void ControlsChoose::regenerate_odes() {
    purge_odes();

    OdeListValues* new_ode_structure = construct_list_values(amount_odes);
    odes = new ODE*[amount_odes];
    ode_colours = new uint32_t[amount_odes];

    for (size_t i = 0; i < amount_odes; i++) {
        OdeListValues values = new_ode_structure[i];

        odes[i] = instance_ode(values.ode_type);

        ode_colours[i] = values.colour;
    }
}

void ControlsChoose::purge_odes() {
    for (int i = 0; i < amount_odes; i++) {
        delete odes[i];
    }

    delete[] odes;
    delete[] ode_colours;
}
*/
