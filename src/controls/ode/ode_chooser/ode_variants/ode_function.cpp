#include "ode_function.h"

const wxString numerical_method_labels[] = {
    "Euler",
};

enum {
    EULER,
};

OdeFunction::OdeFunction(wxWindow* parent, wxString label) : OdeEntry(parent, label) {
    label_length = new wxStaticText(this, wxID_ANY, "Amount calculated values");
    label_step_x = new wxStaticText(this, wxID_ANY, "Step along x");
    label_initial_s = new wxStaticText(this, wxID_ANY, "Initial s");
    label_initial_v = new wxStaticText(this, wxID_ANY, "Initial v");

    input_length = new wxTextCtrl(this, wxID_ANY, "100");
    input_step_x = new wxTextCtrl(this, wxID_ANY, "0.01");
    input_initial_s = new wxTextCtrl(this, wxID_ANY, "1.0");
    input_initial_v = new wxTextCtrl(this, wxID_ANY, "0.0");

    add_option(label_length, input_length);
    add_option(label_step_x, input_step_x);
    add_option(label_initial_s, input_initial_s);
    add_option(label_initial_v, input_initial_v);

    const size_t amount_options = sizeof(numerical_method_labels) / sizeof(numerical_method_labels[0]);
    dropdown_numerical_method = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, amount_options, numerical_method_labels);
    dropdown_numerical_method->SetSelection(0);
    sizer_main->Prepend(dropdown_numerical_method, 0, wxEXPAND | wxALL & ~wxBOTTOM, 10);
}

OdeFunction::~OdeFunction() { }

void OdeFunction::update_length() {
    int length_input = get_length();
    if (length_input < 2) return;
    set_result_length(length_input);
}

int OdeFunction::get_length() {
    return get_input_int(input_length, label_length);
}

double OdeFunction::get_step_x() {
    return get_input_double(input_step_x, label_step_x);
}

double OdeFunction::get_initial_s() {
    return get_input_double(input_initial_s, label_initial_s);
}

double OdeFunction::get_initial_v() {
    return get_input_double(input_initial_v, label_initial_v);
}

double OdeFunction::evaluate_function(double fx) { return 0.0; }

void OdeFunction::calculate() {
    update_length();

    size_t index = dropdown_numerical_method->GetSelection();
    switch (index) {
    case EULER:
        calculate_euler();
        break;

    default:
        std::cout << "WARNING: Unhandled selection " << index << " in OdeFunction::calculate()" << std::endl;
        break;
    }
}

void OdeFunction::calculate_euler() {
    double dt = get_step_x();

    double current_f = get_initial_s();
    double current_df = get_initial_v();

    for (size_t i = 0; i < result_length; i++) {
        result[i] = current_f;

        double ddf = evaluate_function(current_f);
        current_df += ddf * dt;

        double df = current_df;
        current_f += df * dt;
    }
}
