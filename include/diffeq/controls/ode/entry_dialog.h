#ifndef DIFFEQ_ENTRY_ADD_DIALOGUE
#define DIFFEQ_ENTRY_ADD_DIALOGUE

#include <wx/wx.h>
#include "ode_entry.h"

class EntryDialog : public wxDialog {
public:
    EntryDialog(wxWindow* parent);
    ~EntryDialog();

    wxBoxSizer* sizer_main;

    wxButton* test_button;

    OdeEntry* get_entry();
};

#endif
