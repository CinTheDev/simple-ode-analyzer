#ifndef DIFFEQ_CONTROLS
#define DIFFEQ_CONTROLS

#include <wx/wx.h>

class Controls : public wxScrolledWindow {
public:
    Controls(wxWindow* parent, wxString label);
    ~Controls();

    wxStaticBoxSizer* sizer_main;
    wxFlexGridSizer* sizer_grid;

public:
    virtual void on_text_input(wxEvent& evt);

protected:
    double get_input_double(wxTextCtrl* input_field, wxStaticText* label);
    int get_input_int(wxTextCtrl* input_field, wxStaticText* label);

    wxString double_to_string(double val);
};

#endif
