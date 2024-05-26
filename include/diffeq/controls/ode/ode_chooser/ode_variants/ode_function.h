#ifndef DIFFEQ_ODE_FUNCTION
#define DIFFEQ_ODE_FUNCTION

#include <wx/wx.h>
#include "ode_entry.h"

class OdeFunction : public OdeEntry {
public:
    OdeFunction(wxWindow* parent, wxString label);
    ~OdeFunction();

    // Standard options
    wxStaticText* label_length;
    wxStaticText* label_step_x;

    wxTextCtrl* input_length;
    wxTextCtrl* input_step_x;

    wxChoice* dropdown_numerical_method;

protected:
    int get_length();
    double get_step_x();

    // This represents the form ddf(x) = f(x)
    virtual double evaluate_function(double fx);

    void calculate();
    void calculate_euler();

private:
    void update_length();
};

#endif
