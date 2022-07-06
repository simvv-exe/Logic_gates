#pragma once

class EditorWidget : public wxFrame
{
public:
    EditorWidget();

private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
};
