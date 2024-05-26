#ifndef DIFFEQ_ODE_ENTRY
#define DIFFEQ_ODE_ENTRY

#include <wx/wx.h>
#include <wx/clrpicker.h>
#include "settings.h"
#include "controls.h"

class OdeEntry : public Controls {
public:
    OdeEntry(wxWindow* parent, wxString name);
    ~OdeEntry();

    wxBoxSizer* sizer_options;

    wxColourPickerCtrl* colour_picker;
    wxButton* button_up;
    wxButton* button_down;
    wxButton* button_remove;

    size_t get_result_length();
    double* get_result_x();
    double* get_result_y();
    uint32_t get_colour();

    void enable_buttons(bool button_up, bool button_down);

protected:
    double* result_x;
    double* result_y;
    size_t result_length;

    void set_result_length(size_t new_length);
    virtual void calculate();

    void add_option(wxStaticText* label, wxTextCtrl* input);

private:
    void init_elements();
    void init_sizers();
};

#endif
