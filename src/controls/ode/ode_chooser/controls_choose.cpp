#include "controls_choose.h"

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

void ControlsChoose::on_button_create(wxCommandEvent& evt) {
    add_entry();
}

#include <iostream>
void ControlsChoose::on_list_changed(wxEvent& evt) {
    std::cout << "List changed" << std::endl;
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
