#ifndef DIFFEQ_ODE_ENTRY
#define DIFFEQ_ODE_ENTRY

#include <wx/wx.h>

// TODO: Layout
// | ODE Type (Dropdown) | Numerical Method (Dropdown) | Color (Color picker) | Remove button |

class OdeEntry : public wxPanel {
public:
    OdeEntry(wxWindow* parent);
    ~OdeEntry();

    wxButton* test_button;
    wxBoxSizer* sizer_main;
};

#endif
