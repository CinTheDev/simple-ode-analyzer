#ifndef DIFFEQ_ENTRY_ADD_DIALOGUE
#define DIFFEQ_ENTRY_ADD_DIALOGUE

#include <wx/wx.h>
#include "ode_entry.h"

class EntryDialog : public wxDialog {
public:
    EntryDialog(wxWindow* parent);
    ~EntryDialog();

    wxBoxSizer* sizer_main;

    wxListBox* list_options;
    wxButton* button_choose;

    OdeEntry* get_entry();

    void on_button_choose(wxCommandEvent& evt);

private:
    OdeEntry* ode_entry;

    void init_elements();
    void init_sizers();

    void create_entry();
};

#endif
