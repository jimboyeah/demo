/***************************************************************
 * Name:      overloadMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Jimbo (13318999519@qq.com)
 * Created:   2016-01-31
 * Copyright: Jimbo (www.here.com)
 * License:
 **************************************************************/

#include "overloadMain.h"
#include <wx/msgdlg.h>
#include <string>

using namespace std;


class Food
{
    public:
        Food(){ weight = 1; nutrition = string("raw"); }
        string taste() { return string("raw food.");}
        virtual string cook() { return string("not very smelly"); }
    protected:
        string nutrition;
    private:
        double weight;
};
class Pancake : public Food
{
    public:
        Pancake(){ nutrition = string("sugar & powder");}
        string taste(){ return string("fine food."); }
        string taste(string mix){ return string("well, pancake with ")+mix; }
        string cook(){ return string("ancient dilicious"); }
};


//(*InternalHeaders(overloadFrame)
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(overloadFrame)
const long overloadFrame::ID_ANIMATIONCTRL1 = wxNewId();
const long overloadFrame::ID_TEXTCTRL1 = wxNewId();
const long overloadFrame::ID_AUINOTEBOOK1 = wxNewId();
const long overloadFrame::ID_BTN_EXIT = wxNewId();
const long overloadFrame::ID_BTN_SAY = wxNewId();
const long overloadFrame::idMenuQuit = wxNewId();
const long overloadFrame::idMenuAbout = wxNewId();
const long overloadFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(overloadFrame,wxFrame)
    //(*EventTable(overloadFrame)
    //*)
END_EVENT_TABLE()

overloadFrame::overloadFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(overloadFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, _("C++ Overload, Redefine, Override & Virtual "), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(308,472));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    AuiNotebook1 = new wxAuiNotebook(this, ID_AUINOTEBOOK1, wxPoint(0,0), wxSize(228,160), wxAUI_NB_DEFAULT_STYLE);
    AuiNotebook1->SetMinSize(wxSize(-1,-1));
    AuiNotebook1->SetMaxSize(wxSize(-1,-1));
    	wxAnimation anim_1(_T("..\\asts\\cloudy.gif"));
    AnimationCtrl1 = new wxAnimationCtrl(AuiNotebook1, ID_ANIMATIONCTRL1, anim_1, wxPoint(100,73), wxSize(122,128), wxAC_DEFAULT_STYLE, _T("ID_ANIMATIONCTRL1"));
    AnimationCtrl1->SetInactiveBitmap(wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_COPY")),wxART_CMN_DIALOG));
    AnimationCtrl1->Play();
    //wxMessageBox(wxString(_T("Extra code")));
    TextCtrl1 = new wxTextCtrl(AuiNotebook1, ID_TEXTCTRL1, _("\nclass Food\n{\n    public:\n        Food(){ weight = 1; nutrition = string(\"raw\"); }\n        string taste() { return string(\"raw food.\");}\n        virtual string cook() { return string(\"not very smelly\"); }\n    protected:\n        string nutrition;\n    private:\n        double weight;\n};\nclass Pancake : public Food\n{\n    public:\n        Pancake(){ nutrition = string(\"sugar & powder\");}\n        string taste(){ return string(\"fine food.\"); }\n        string taste(string mix){ return string(\"well, pancake with \")+mix; }\n        string cook(){ return string(\"ancient dilicious\"); }\n};\n"), wxPoint(0,0), wxSize(179,328), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    AuiNotebook1->AddPage(AnimationCtrl1, _("animation"));
    AuiNotebook1->AddPage(TextCtrl1, _("Textpad"));
    BoxSizer1->Add(AuiNotebook1, 4, wxEXPAND|wxFIXED_MINSIZE, 0);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    Button1 = new wxButton(this, ID_BTN_EXIT, _("Exit"), wxPoint(328,160), wxSize(85,82), 0, wxDefaultValidator, _T("ID_BTN_EXIT"));
    BoxSizer2->Add(Button1, 2, wxEXPAND, 0);
    Button2 = new wxButton(this, ID_BTN_SAY, _("test"), wxDefaultPosition, wxSize(85,13), 0, wxDefaultValidator, _T("ID_BTN_SAY"));
    BoxSizer2->Add(Button2, 3, wxEXPAND, 0);
    BoxSizer1->Add(BoxSizer2, 0, wxALIGN_LEFT, 0);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    SetSizer(BoxSizer1);
    Layout();

    Connect(ID_BTN_EXIT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&overloadFrame::OnQuit);
    Connect(ID_BTN_SAY,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&overloadFrame::OnButton2Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&overloadFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&overloadFrame::OnAbout);
    //*)
}

overloadFrame::~overloadFrame()
{
    //(*Destroy(overloadFrame)
    //*)
}

void overloadFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void overloadFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void overloadFrame::OnButton2Click(wxCommandEvent& event)
{
    AuiNotebook1->SetSelection(1);
    wxTextCtrl &t = *TextCtrl1;;
    t.AppendText(wxString(_T("\n")));

    Pancake p;
    Food &f = dynamic_cast<Food&>(p);
    string r(f.taste());
    r.append("\n");
    r+=f.cook();
    r.append("\n");
    r+=dynamic_cast<Pancake&>(f).taste(string("Spicy Sauce"));
    t.AppendText(wxString(r.c_str(), wxConvUTF8));
}

