#include <wx/wx.h>
#include "MainApp.h"
#include "EditorWidget.h"

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    EditorWidget* editor = new EditorWidget();
    editor->Show(true);
    return true;
}


