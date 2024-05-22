#include "controls.h"

Controls::Controls(wxWindow* parent, wxString label) : wxPanel(parent) {
    Bind(wxEVT_TEXT, &Controls::on_text_input, this);

    sizer_grid = new wxFlexGridSizer(2, 5, 5);
    sizer_grid->AddGrowableCol(0, 1);

    sizer_main = new wxStaticBoxSizer(wxVERTICAL, this, label);
    sizer_main->Add(sizer_grid, 1, wxEXPAND | wxALL, 10);

    SetSizer(sizer_main);
}

Controls::~Controls() { }

void Controls::on_text_input(wxEvent& evt) {
    // TODO: Generic implementation
}

double Controls::get_input_double(wxTextCtrl* input_field, wxStaticText* label) {
    double val;
    try {
        val = std::stod(input_field->GetValue().ToStdString());
        label->SetForegroundColour(*wxWHITE);
    }
    catch (...) {
        val = 1.0;
        label->SetForegroundColour(*wxRED);
    }

    return val;
}

int Controls::get_input_int(wxTextCtrl* input_field, wxStaticText* label) {
    int val;

    try {
        val = std::stoi(input_field->GetValue().ToStdString());
        label->SetForegroundColour(*wxWHITE);
    }
    catch (...) {
        val = 0;
        label->SetForegroundColour(*wxRED);
    }

    return val;
}

wxString Controls::double_to_string(double val) {
    std::string string_val = std::to_string(val);
    string_val.erase(string_val.find_last_not_of('0') + 1, std::string::npos);
    string_val.erase(string_val.find_last_not_of('.') + 1, std::string::npos);

    return wxString(string_val);
}
