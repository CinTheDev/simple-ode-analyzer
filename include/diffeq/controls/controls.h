#ifndef DIFFEQ_CONTROLS
#define DIFFEQ_CONTROLS

#include <wx/wx.h>

class Controls : public wxPanel {
public:
    Controls(wxWindow* parent);
    ~Controls();

public:
    wxButton* test_button;

    wxBoxSizer* sizer_main;
};

#endif
