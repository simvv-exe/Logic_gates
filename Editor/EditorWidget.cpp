#pragma once

#include <wx/wx.h>
#include "MainApp.h"
#include "EditorWidget.h"

enum
{
    ID_Hello = 1
};

EditorWidget::EditorWidget()
    : wxFrame(NULL, wxID_ANY, "Editor")
{
    wxMenu* menu_file = new wxMenu;
    menu_file->Append(wxID_NEW);
    menu_file->Append(wxID_OPEN);
    menu_file->Append(wxID_CLOSE); //Ctrl + W
    menu_file->Append(wxID_SAVE);
    menu_file->Append(wxID_SAVEAS);
    menu_file->AppendSeparator();
    menu_file->Append(wxID_EXIT);  //Alt + F4

    wxMenu* menu_edit = new wxMenu;
    menu_edit->Append(wxID_UNDO);
    //menu_edit->Enable(wxID_UNDO, false);
    menu_edit->Append(wxID_REDO);
    menu_edit->AppendSeparator();
    menu_edit->Append(wxID_CUT);
    menu_edit->Append(wxID_COPY);
    menu_edit->Append(wxID_PASTE);
    menu_edit->AppendSeparator();
    menu_edit->Append(wxID_FIND);

    wxMenu* menu_view = new wxMenu;

    wxMenu* menu_settings = new wxMenu;

    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_HELP);
    menuHelp->AppendSeparator();
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menu_file, "&File");
    menuBar->Append(menu_edit, "&Edit");
    menuBar->Append(menu_view, "&View");
    menuBar->Append(menu_settings, "&Settings");
    menuBar->Append(menuHelp, "&Help");
    
    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");

    Bind(wxEVT_MENU, &EditorWidget::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &EditorWidget::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &EditorWidget::OnExit, this, wxID_EXIT);
}

void EditorWidget::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void EditorWidget::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
        "About Hello World", wxOK | wxICON_INFORMATION);
}

void EditorWidget::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}