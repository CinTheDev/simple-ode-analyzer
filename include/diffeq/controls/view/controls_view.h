#ifndef CONTROLS_VIEW
#define CONTROLS_VIEW

#include <wx/wx.h>

class ControlsView : public wxScrolledWindow {
public:
    ControlsView(wxWindow* parent);
    ~ControlsView();

    wxTextCtrl* input_view_x;
    wxTextCtrl* input_view_y;

    wxFlexGridSizer* sizer_main;

private:
    void init_elements();
    void init_sizers();
};

#endif
