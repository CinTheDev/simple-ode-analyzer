#include "ode_entry.h"
#include "events.h"
#include "ode_harmonic.h"
#include "ode_v_oscillation.h"

const wxString ode_options[] = {
    "Harmonic Oscillation",
    "Gravitational Oscillation",
};

const wxString approx_options[] = {
    "Euler",
    "TODO",
};

const OdeTypes ode_types[] = {
    OdeTypes::HarmonicOscillation,
    OdeTypes::GravitationalOscillation,
};

const ApproxTypes approx_types[] = {
    ApproxTypes::Euler,
    ApproxTypes::Test,
};

OdeEntry::OdeEntry(wxWindow* parent) : Controls(parent, "") {
    init_elements();
    init_sizers();

    wxString test_labels[] = { "First option", "Second option", "Yeah" };

    labels = new wxStaticText*[1];
    inputs = new wxTextCtrl*[1];
    ode = new ODE(Settings_Common(), Settings_Approximation());

    create_options(3, test_labels);
}

OdeEntry::~OdeEntry() {
    purge();
}

void OdeEntry::init_elements() {
    size_t amount_ode_options = sizeof(ode_options) / sizeof(wxString);
    size_t amount_approx_options = sizeof(approx_options) / sizeof(wxString);

    dropdown_ode = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, amount_ode_options, ode_options);
    dropdown_approx = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, amount_approx_options, approx_options);

    colour_picker = new wxColourPickerCtrl(this, wxID_ANY, *wxRED);
    button_remove = new wxButton(this, wxID_ANY, "Remove");

    // TODO: Add Buttons "down" and "up" for swapping an entry with the lower or upper neighbour

    // Default selection
    dropdown_ode->SetSelection(0);
    dropdown_approx->SetSelection(0);

    dropdown_ode->Bind(wxEVT_CHOICE, &OdeEntry::on_dropdown_ode, this);
}

void OdeEntry::init_sizers() {
    sizer_options_vertical = new wxBoxSizer(wxVERTICAL);
    sizer_options_horizontal = new wxBoxSizer(wxHORIZONTAL);

    sizer_options_horizontal->Add(dropdown_approx, 1);
    sizer_options_horizontal->Add(colour_picker, 1);
    sizer_options_horizontal->Add(button_remove, 1);

    sizer_options_vertical->Add(dropdown_ode, 0, wxEXPAND);
    sizer_options_vertical->Add(sizer_options_horizontal, 0, wxEXPAND);

    sizer_main->Prepend(sizer_options_vertical, 0, wxEXPAND | wxALL & ~wxBOTTOM, 10);

    SetSizer(sizer_main);
}

double* OdeEntry::get_ode_results(size_t& amount_results) {
    ode->calculate();

    amount_results = ode->get_length();
    return ode->get_result();
}

uint32_t OdeEntry::get_colour() {
    return colour_picker->GetColour().GetRGBA();
}

void OdeEntry::create_options(size_t number, wxString* labels) {
    purge();

    ode = instance_ode(ode_types[dropdown_ode->GetSelection()]);

    this->labels = new wxStaticText*[number];
    this->inputs = new wxTextCtrl*[number];

    for (int i = 0; i < number; i++) {
        this->labels[i] = new wxStaticText(this, wxID_ANY, labels[i]);
        this->inputs[i] = new wxTextCtrl(this, wxID_ANY, labels[i]);

        sizer_grid->Add(this->labels[i]);
        sizer_grid->Add(this->inputs[i]);
    }
}

OdeListValues OdeEntry::construct_values() {
    OdeListValues values = OdeListValues();

    int ode_type_selection = dropdown_ode->GetSelection();
    int approx_type_selection = dropdown_approx->GetSelection();

    values.ode_type = ode_types[ode_type_selection];
    values.approx_type = approx_types[approx_type_selection];
    values.colour = colour_picker->GetColour().GetRGBA();

    return values;
}

void OdeEntry::on_dropdown_ode(wxCommandEvent& evt) {
    // TODO: Get ODE variable names and use create_options()
    delete ode;
    ode = instance_ode(ode_types[dropdown_ode->GetSelection()]);
}

ODE* OdeEntry::instance_ode(OdeTypes ode_type) {
    // TODO: Request settings and instance with those instead of default settings
    switch (ode_type) {
        case OdeTypes::HarmonicOscillation:
            return new ODE_Harmonic(Settings_Common(), Settings_Approximation());

        case OdeTypes::GravitationalOscillation:
            return new ODE_V_Oscillation(Settings_Common(), Settings_Approximation());

        default:
            std::cout << "WARNING [ControlsODE::instance_ode()]: Unhandled OdeTypes enum" << std::endl;
            return nullptr;
    }
}

void OdeEntry::request_settings(Settings_Common* settings_common, Settings_Approximation* settings_approx) {
    SettingsOdeRequest request = SettingsOdeRequest(SETTINGS_ODE_REQUEST, GetId(), settings_common, settings_approx);
    request.ResumePropagation(__INT_MAX__);
    request.SetEventObject(this);
    ProcessEvent(request);

    if (settings_common == nullptr || settings_approx == nullptr) {
        std::cout << "WARNING: Requested settings are null" << std::endl;
    }
}

void OdeEntry::purge() {
    sizer_grid->Clear(true);

    delete[] labels;
    delete[] inputs;
    delete ode;
}
