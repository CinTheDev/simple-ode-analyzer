#include "controls_choose.h"
#include "events.h"

ControlsChoose::ControlsChoose(wxWindow* parent) : wxScrolledWindow(parent) {
    sizer_main = new wxStaticBoxSizer(wxVERTICAL, this, "Select ODEs");

    button_create_entry = new wxButton(this, wxID_ANY, "Add ODE");
    sizer_main->Add(button_create_entry, 0, wxEXPAND);

    button_create_entry->Bind(wxEVT_BUTTON, &ControlsChoose::on_button_create, this);

    SetSizer(sizer_main);

    SetScrollRate(0, 5);
}

ControlsChoose::~ControlsChoose() { }

void ControlsChoose::add_entry() {
    OdeEntry* new_entry = new OdeEntry(this);

    new_entry->dropdown_ode->Bind(wxEVT_CHOICE, &ControlsChoose::on_list_changed, this);
    new_entry->dropdown_approx->Bind(wxEVT_CHOICE, &ControlsChoose::on_list_changed, this);
    new_entry->colour_picker->Bind(wxEVT_COLOURPICKER_CHANGED, &ControlsChoose::on_list_changed, this);
    new_entry->button_remove->Bind(wxEVT_BUTTON, &ControlsChoose::on_child_remove, this);

    sizer_main->Add(new_entry, 0, wxEXPAND);

    FitInside();
    Layout();
    GetParent()->Layout();
}

OdeListValues* ControlsChoose::construct_list_values(size_t& list_length) {
    list_length = sizer_main->GetItemCount() - 1;

    if (list_length < 1) return nullptr;

    OdeListValues* list_values = new OdeListValues[list_length];

    for (size_t i = 0; i < list_length; i++) {
        OdeEntry* entry = static_cast<OdeEntry*>(sizer_main->GetItem(i + 1)->GetWindow());
        list_values[i] = entry->construct_values();
    }

    return list_values;
}

void ControlsChoose::on_button_create(wxCommandEvent& evt) {
    add_entry();
}

void ControlsChoose::on_list_changed(wxEvent& evt) {
    size_t list_length;
    OdeListValues* list_values = construct_list_values(list_length);

    OdeListUpdateEvent list_update_event(EVT_ODE_LIST, GetId(), list_values, list_length);
    list_update_event.SetEventObject(this);
    list_update_event.ResumePropagation(__INT_MAX__);
    ProcessEvent(list_update_event);
}

void ControlsChoose::on_child_remove(wxCommandEvent& evt) {
    on_list_changed(evt);

    wxButton* evt_button = reinterpret_cast<wxButton*>(evt.GetEventObject());
    wxWindow* entry = evt_button->GetParent();

    for (size_t i = 0; i < sizer_main->GetItemCount(); i++) {
        if ( (wxWindow*) sizer_main->GetItem(i)->GetWindow() == entry) {
            sizer_main->Remove(i);
            delete entry;
        }
    }
    
    FitInside();
    Layout();
    GetParent()->Layout();
}
