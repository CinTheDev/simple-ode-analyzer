#include "ode_entry.h"
#include "events.h"

const wxString ode_options[] = {
    "Harmonic Oscillation",
    "Gravitational Oscillation",
};

const wxString approx_options[] = {
    "Euler",
    "TODO",
};

OdeEntry::OdeEntry(wxWindow* parent) : wxPanel(parent) {
    init_elements();
    init_sizers();
}

OdeEntry::~OdeEntry() { }

void OdeEntry::init_elements() {
    size_t amount_ode_options = sizeof(ode_options) / sizeof(wxString);
    size_t amount_approx_options = sizeof(approx_options) / sizeof(wxString);

    dropdown_ode = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, amount_ode_options, ode_options);
    dropdown_approx = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, amount_approx_options, approx_options);

    colour_picker = new wxColourPickerCtrl(this, wxID_ANY, *wxRED);
    button_remove = new wxButton(this, wxID_ANY, "Remove");

    dropdown_ode->Bind(wxEVT_CHOICE, &OdeEntry::on_interaction, this);
    dropdown_approx->Bind(wxEVT_CHOICE, &OdeEntry::on_interaction, this);
    colour_picker->Bind(wxEVT_COLOURPICKER_CHANGED, &OdeEntry::on_interaction, this);
    button_remove->Bind(wxEVT_BUTTON, &OdeEntry::on_interaction, this);
}

void OdeEntry::init_sizers() {
    sizer_main = new wxBoxSizer(wxHORIZONTAL);

    sizer_main->Add(dropdown_ode, 0);
    sizer_main->Add(dropdown_approx, 0);
    sizer_main->Add(colour_picker, 0);
    sizer_main->Add(button_remove, 0);

    SetSizer(sizer_main);
}

void OdeEntry::on_interaction(wxEvent& evt) {
    OdeListUpdateEvent update_event(EVT_ODE_LIST, GetId(), construct_values());
    update_event.SetEventObject(this);
    ProcessEvent(update_event);
}

OdeListValues OdeEntry::construct_values() {
    OdeListValues values = OdeListValues();

    // TODO: Implement this
    values.ode_type = OdeTypes::HarmonicOscillation;
    values.approx_type = ApproxTypes::Euler;
    values.color = 0xff000000; // Red

    return values;
}
