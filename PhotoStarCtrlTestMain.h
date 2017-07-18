/***************************************************************
 * Name:      PhotoStarCtrlTestMain.h
 * Purpose:   Defines Application Frame
 * Author:    yowen (yowen@126.com)
 * Created:   2017-07-17
 * Copyright: yowen (www.yowenit.com)
 * License:
 **************************************************************/

#ifndef PHOTOSTARCTRLTESTMAIN_H
#define PHOTOSTARCTRLTESTMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "PhotoStarCtrlTestApp.h"

#include "PhotoStarCtrl.h"

class PhotoStarCtrlTestFrame: public wxFrame
{
    public:
        PhotoStarCtrlTestFrame(wxFrame *frame, const wxString& title);
        ~PhotoStarCtrlTestFrame();
    private:
        enum
        {
            idMenuQuit = 1000,
            idMenuAbout
        };
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        DECLARE_EVENT_TABLE()
};


#endif // PHOTOSTARCTRLTESTMAIN_H
