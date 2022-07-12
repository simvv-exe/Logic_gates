#include <wx/wxprec.h>
#include "MainApp.h"
#include "EditorWidget.h"


wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    if (!wxApp::OnInit())
        return false;
    EditorWidget* editor = new EditorWidget();
    editor->Show(true);
    return true;
}


