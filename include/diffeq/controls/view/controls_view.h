#ifndef CONTROLS_VIEW
#define CONTROLS_VIEW

#include <wx/wx.h>

class ControlsView : public wxPanel {
public:
    ControlsView(wxWindow* parent);
    ~ControlsView();

    wxButton* test_button;
    wxBoxSizer* sizer_main;
};

#endif
