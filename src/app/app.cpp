#include <app.h>

wxIMPLEMENT_APP(Diffeq_App);

Diffeq_App::Diffeq_App() {

}

Diffeq_App::~Diffeq_App() {

}

bool Diffeq_App::OnInit() {
    m_frame1 = new Diffeq_Main();
    m_frame1->Show();

    return true;
}
