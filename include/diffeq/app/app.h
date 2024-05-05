#include <wx/wx.h>
#include "main.h"

class Diffeq_App : public wxApp {
public:
    Diffeq_App();
    ~Diffeq_App();

private:
    Diffeq_Main* m_frame1 = nullptr;

public:
    virtual bool OnInit();
};
