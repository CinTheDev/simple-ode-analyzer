#ifndef DIFFEQ_PLOTTER
#define DIFFEQ_PLOTTER

#include <wx/wx.h>

class Plotter : public wxPanel {
public:
    Plotter(wxWindow* parent);
    ~Plotter();

public:
    wxButton* test_button;

    wxBoxSizer* sizer_main;
};

#endif
