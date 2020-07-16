/***************************************************************
 * Name:      overloadMain.h
 * Purpose:   Defines Application Frame
 * Author:    Jimbo (13318999519@qq.com)
 * Created:   2016-01-31
 * Copyright: Jimbo (www.here.com)
 * License:
 **************************************************************/

#ifndef OVERLOADMAIN_H
#define OVERLOADMAIN_H

//(*Headers(overloadFrame)
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/aui/aui.h>
#include <wx/button.h>
#include <wx/animate.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class overloadFrame: public wxFrame
{
    public:

        overloadFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~overloadFrame();

    private:

        //(*Handlers(overloadFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnTextCtrl1Text(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnAuiNotebook3PageClose(wxAuiNotebookEvent& event);
        void OnClose1(wxCloseEvent& event);
        void OnAuiNotebook1PageClose(wxAuiNotebookEvent& event);
        void OnClose2(wxCloseEvent& event);
        void OnAuiNotebook1PageClose1(wxAuiNotebookEvent& event);
        void OnTextCtrl1Text1(wxCommandEvent& event);
        //*)

        //(*Identifiers(overloadFrame)
        static const long ID_ANIMATIONCTRL1;
        static const long ID_TEXTCTRL1;
        static const long ID_AUINOTEBOOK1;
        static const long ID_BTN_EXIT;
        static const long ID_BTN_SAY;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(overloadFrame)
        wxButton* Button1;
        wxBoxSizer* BoxSizer2;
        wxButton* Button2;
        wxStatusBar* StatusBar1;
        wxAuiNotebook* AuiNotebook1;
        wxBoxSizer* BoxSizer1;
        wxTextCtrl* TextCtrl1;
        wxAnimationCtrl* AnimationCtrl1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // OVERLOADMAIN_H
