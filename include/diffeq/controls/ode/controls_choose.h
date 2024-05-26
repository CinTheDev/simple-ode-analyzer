#ifndef DIFFEQ_CONTROLS_CHOOSE
#define DIFFEQ_CONTROLS_CHOOSE

#include <wx/wx.h>
#include "controls.h"
#include "ode_entry.h"
#include "settings.h"
#include "events.h"

class ControlsChoose : public wxScrolledWindow {
public:
    ControlsChoose(wxWindow* parent);
    ~ControlsChoose();

    wxStaticBoxSizer* sizer_main;

    wxButton* button_create_entry;

    void add_entry();

    void on_button_create(wxCommandEvent& evt);
    void on_child_up(wxCommandEvent& evt);
    void on_child_down(wxCommandEvent& evt);
    void on_child_remove(wxCommandEvent& evt);

    void on_calculate(wxCommandEvent& evt);

    void SendResults();

private:
    double** get_all_results_x(size_t amount_results);
    double** get_all_results_y(size_t amount_results);
    uint32_t* get_all_colours(size_t amount_results);
    size_t* get_all_lengths(size_t amount_results);

    OdeEntry* get_entry_from_event(wxCommandEvent& evt);
    size_t get_entry_index(OdeEntry* entry);
    void update_entry_buttons();
    void entries_calculate();

    void swap_entries(size_t index_1, size_t index_2);
};

#endif
