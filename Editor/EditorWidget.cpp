#pragma once

#include <wx/wxprec.h>
#include <wx/artprov.h>


#include "MainApp.h"
#include "EditorWidget.h"

EditorWidget::EditorWidget()
    : wxFrame(nullptr, wxID_ANY, "Editor")
{
    m_menu_file = new wxMenu;
    m_menu_file->Append(wxID_NEW);
    m_menu_file->Append(wxID_OPEN);
    m_menu_file->Append(wxID_CLOSE); //Ctrl + W
    m_menu_file->Append(wxID_SAVE);
    m_menu_file->Append(wxID_SAVEAS);
    m_menu_file->AppendSeparator();
    m_menu_file->Append(wxID_EXIT);  //Alt + F4

    m_menu_edit = new wxMenu;
    m_menu_edit->Append(wxID_UNDO);
    //m_menu_edit->Enable(wxID_UNDO, false);
    m_menu_edit->Append(wxID_REDO); // Ctrl + Y
    m_menu_edit->AppendSeparator();
    m_menu_edit->Append(wxID_CUT);
    m_menu_edit->Append(wxID_COPY);
    m_menu_edit->Append(wxID_PASTE);
    m_menu_edit->AppendSeparator();
    m_menu_edit->Append(wxID_FIND);

    m_menu_view = new wxMenu;

    m_menu_settings = new wxMenu;

    m_menu_help = new wxMenu;
    m_menu_help->Append(wxID_HELP); // display help
    m_menu_help->AppendSeparator();
    m_menu_help->Append(wxID_ABOUT);

    m_menu_bar = new wxMenuBar;
    m_menu_bar->Append(m_menu_file, "&File");
    m_menu_bar->Append(m_menu_edit, "&Edit");
    m_menu_bar->Append(m_menu_view, "&View");
    m_menu_bar->Append(m_menu_settings, "&Settings");
    m_menu_bar->Append(m_menu_help, "&Help");
    
    SetMenuBar(m_menu_bar);

    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");

    m_top_tool_bar = CreateToolBar(wxTB_HORIZONTAL , wxID_ANY);
    m_top_tool_bar->AddTool(wxID_NEW, "New", wxArtProvider::GetBitmap("wxART_NEW")); 
    m_top_tool_bar->Realize();


    m_left_tool_bar = new wxToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_VERTICAL);
    m_left_tool_bar->AddTool(wxID_ABOUT, "About", wxArtProvider::GetBitmap("wxART_HELP_SIDE_PANEL"));
    m_left_tool_bar->Realize();


    Bind(wxEVT_MENU, &EditorWidget::on_new, this, wxID_NEW);
    Bind(wxEVT_MENU, &EditorWidget::on_about, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &EditorWidget::on_exit, this, wxID_EXIT);
}

void EditorWidget::on_exit(wxCommandEvent& event)
{
    Close(true);
}

void EditorWidget::on_about(wxCommandEvent& event)
{
    wxMessageBox(L"Unicode test\nLorem ipsum dolor sit amet\n漢語",
        "About Hello World", wxOK | wxICON_INFORMATION);
}

void EditorWidget::on_new(wxCommandEvent& event)
{
    wxMessageBox("New");
}
