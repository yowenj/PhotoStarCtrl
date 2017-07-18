#ifndef PHOTOSTARCTRL_H
#define PHOTOSTARCTRL_H

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif


#include "wx/image.h"

#include "res/xing_k.xpm"
#include "res/xing_r.xpm"


class PhotoStarCtrl :public wxStaticBitmap
{
    DECLARE_EVENT_TABLE()

    public:
        PhotoStarCtrl(wxWindow* parent, wxWindowID pid);
        virtual ~PhotoStarCtrl();

        void OnMouseDown(wxMouseEvent& event);
        void OnMouseMove(wxMouseEvent& event);
        void SetPhotoLevel(int level);

        bool isViewModel;

        int m_start;

    protected:

        void MakeStartBmp();

        wxBitmap* m_bmp;

    private:
};

#endif // PHOTOSTARCTRL_H
