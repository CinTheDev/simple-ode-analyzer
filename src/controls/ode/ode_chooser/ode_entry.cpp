#include "ode_entry.h"
#include "events.h"
#include "ode_oscillation_harmonic.h"
#include "ode_oscillation_gravitational.h"

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

    labels = new wxStaticText*[1];
    inputs = new wxTextCtrl*[1];
    ode = new ODE();

    create_options();
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

    sizer_main->Prepend(sizer_options_vertical, 0, wxEXPAND | wxALL & ~wxTOP, 10);
    sizer_main->GetItem(1)->SetFlag(wxEXPAND | wxALL & ~wxTOP); // Flags of sizer_grid

    SetSizer(sizer_main);
}

double* OdeEntry::get_ode_results(size_t& amount_results, Settings_Common settings_common, Settings_Approx settings_approx) {
    update_ode_variables();
    ode->apply_settings(settings_common);
    ode->apply_settings(settings_approx);
    ode->calculate();

    amount_results = ode->get_length();
    return ode->get_result();
}

uint32_t OdeEntry::get_colour() {
    return colour_picker->GetColour().GetRGBA();
}

void OdeEntry::create_options() {
    purge();

    ode = instance_ode(ode_types[dropdown_ode->GetSelection()]);

    size_t amount_options = ode->get_amount_variables();
    std::string* option_labels = ode->get_variable_names();
    double* option_values = ode->get_variable_values();

    this->labels = new wxStaticText*[amount_options];
    this->inputs = new wxTextCtrl*[amount_options];

    for (int i = 0; i < amount_options; i++) {
        this->labels[i] = new wxStaticText(this, wxID_ANY, option_labels[i]);
        this->inputs[i] = new wxTextCtrl(this, wxID_ANY, double_to_string(option_values[i]));

        sizer_grid->Add(this->labels[i]);
        sizer_grid->Add(this->inputs[i]);
    }

    GetParent()->GetParent()->Layout();
    sizer_main->GetStaticBox()->Update();
}

void OdeEntry::on_dropdown_ode(wxCommandEvent& evt) {
    create_options();
}

void OdeEntry::update_ode_variables() {
    size_t amount_options = ode->get_amount_variables();
    double* ode_variables = ode->get_variable_values();

    for (size_t i = 0; i < amount_options; i++) {
        double input_value = get_input_double(inputs[i], labels[i]);
        ode_variables[i] = input_value;
    }
}

ODE* OdeEntry::instance_ode(OdeTypes ode_type) {
    switch (ode_type) {
        case OdeTypes::HarmonicOscillation:
            return new ODE_Harmonic();

        case OdeTypes::GravitationalOscillation:
            return new ODE_V_Oscillation();

        default:
            std::cout << "WARNING [ControlsODE::instance_ode()]: Unhandled OdeTypes enum" << std::endl;
            return nullptr;
    }
}

void OdeEntry::purge() {
    sizer_grid->Clear(true);

    delete[] labels;
    delete[] inputs;
    delete ode;
}
