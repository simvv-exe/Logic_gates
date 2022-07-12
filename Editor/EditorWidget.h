#pragma once

class EditorWidget : public wxFrame
{
public:
    EditorWidget();

private:
    void on_exit(wxCommandEvent& event);
    void on_about(wxCommandEvent& event);
    void on_new(wxCommandEvent& event);

    wxMenu* m_menu_file = nullptr;
    wxMenu* m_menu_edit = nullptr;
    wxMenu* m_menu_view = nullptr;
    wxMenu* m_menu_settings = nullptr;
    wxMenu* m_menu_help = nullptr;
    wxMenuBar* m_menu_bar = nullptr;
    wxToolBar* m_top_tool_bar = nullptr;
    wxToolBar* m_left_tool_bar = nullptr;

};
