/***************************************************************
 * Name:      overloadApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Jimbo (13318999519@qq.com)
 * Created:   2016-01-31
 * Copyright: Jimbo (www.here.com)
 * License:
 **************************************************************/

#include "overloadApp.h"

//(*AppHeaders
#include "overloadMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(overloadApp);

bool overloadApp::OnInit()
{

    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	overloadFrame* Frame = new overloadFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
