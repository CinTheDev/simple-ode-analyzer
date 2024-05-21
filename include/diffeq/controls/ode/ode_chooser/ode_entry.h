#ifndef DIFFEQ_ODE_ENTRY
#define DIFFEQ_ODE_ENTRY

#include <wx/wx.h>

// TODO: Layout
// | ODE Type (Dropdown) | Numerical Method (Dropdown) | Color (Color picker) | Remove button |

class OdeEntry : public wxPanel {
public:
    OdeEntry(wxWindow* parent);
    ~OdeEntry();

    wxBoxSizer* sizer_main;

    wxChoice* dropdown_test;
};

#endif
