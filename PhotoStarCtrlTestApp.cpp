/***************************************************************
 * Name:      PhotoStarCtrlTestApp.cpp
 * Purpose:   Code for Application Class
 * Author:    yowen (yowen@126.com)
 * Created:   2017-07-17
 * Copyright: yowen (www.yowenit.com)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "PhotoStarCtrlTestApp.h"
#include "PhotoStarCtrlTestMain.h"

IMPLEMENT_APP(PhotoStarCtrlTestApp);

bool PhotoStarCtrlTestApp::OnInit()
{
    PhotoStarCtrlTestFrame* frame = new PhotoStarCtrlTestFrame(0L, _("wxWidgets Application Template"));
    frame->SetIcon(wxICON(aaaa)); // To Set App Icon
    frame->Show();
    
    return true;
}
