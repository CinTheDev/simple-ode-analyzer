#ifndef DIFFEQ_ENTRY_ADD_DIALOGUE
#define DIFFEQ_ENTRY_ADD_DIALOGUE

#include <wx/wx.h>

class EntryDialog : public wxDialog {
public:
    EntryDialog(wxWindow* parent);
    ~EntryDialog();

    wxBoxSizer* sizer_main;

    wxButton* test_button;
};

#endif
