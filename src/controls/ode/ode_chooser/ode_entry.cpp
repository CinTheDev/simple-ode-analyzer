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

    // Default selection
    dropdown_ode->SetSelection(0);
    dropdown_approx->SetSelection(0);

    dropdown_ode->Bind(wxEVT_CHOICE, &OdeEntry::on_dropdown_ode, this);
}

void OdeEntry::init_sizers() {
    sizer_options = new wxBoxSizer(wxHORIZONTAL);

    sizer_options->Add(dropdown_ode, 0);
    sizer_options->Add(dropdown_approx, 0);
    sizer_options->Add(colour_picker, 0);
    sizer_options->Add(button_remove, 0);

    sizer_main->Prepend(sizer_options, 0, wxEXPAND | wxALL & ~wxBOTTOM, 10);

    SetSizer(sizer_main);
}

void OdeEntry::create_options(size_t number, wxString* labels) {
    purge();

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
    std::cout << "Dropdown event" << std::endl;
}

void OdeEntry::purge() {
    sizer_grid->Clear(true);

    delete[] labels;
    delete[] inputs;
}
