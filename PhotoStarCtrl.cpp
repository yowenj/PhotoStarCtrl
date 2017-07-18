#include "PhotoStarCtrl.h"


BEGIN_EVENT_TABLE(PhotoStarCtrl, wxStaticBitmap)
    EVT_PAINT(PhotoStarCtrl::OnPaint)
    EVT_LEFT_DOWN(PhotoStarCtrl::OnMouseDown)
    EVT_MOTION(PhotoStarCtrl::OnMouseMove)
END_EVENT_TABLE()

const int StarW = 22;
const int StarH = 16;

PhotoStarCtrl::PhotoStarCtrl(wxWindow* parent, wxWindowID pid)
{

    m_start = 0;

    MakeStartBmp();


    Create(parent,
           pid,     // wxID_ANY
           *m_bmp,  // wxImage(_T("E:\\boost\\wxProject\\PHouse\\doc\\xing.jpg"))),
           wxDefaultPosition,
           wxSize(StarW*3,-1),
           wxNO_BORDER, // wxDOUBLE_BORDER,
            _T("ID_STATICBITMAP1")
            );


}

PhotoStarCtrl::~PhotoStarCtrl()
{
    //dtor
}

void PhotoStarCtrl::MakeStartBmp()
{
    //wxRect rect = GetClientRect();
    m_bmp = new wxBitmap(StarW*3, StarH);

    wxMemoryDC dc;
    dc.SelectObject(*m_bmp);

    wxColour  backgroundColour;

    if (isViewModel == false)
        backgroundColour = wxSystemSettings::GetColour(wxSYS_COLOUR_MENUBAR);  // 工具条模式
        else
            backgroundColour = wxSystemSettings::GetColour(wxSYS_COLOUR_3DHIGHLIGHT); // 浏览模式

    dc.SetBrush(wxBrush(backgroundColour));


    dc.SetPen(*wxTRANSPARENT_PEN);
    dc.DrawRectangle(0, 0, StarW*3, StarH);


    for(int i=0;i<3;i++)
    {
        if ((i+1) <= m_start)
            dc.DrawBitmap(wxBitmap(xing_r), i*StarW , 0 ,true);
            else
                dc.DrawBitmap(wxBitmap(xing_k), i*StarW , 0 ,true);
    }

    dc.SelectObject(wxNullBitmap);
}

void PhotoStarCtrl::OnMouseMove(wxMouseEvent& event)
{
    wxPoint curPos = event.GetPosition();
    wxSize clientSize = GetClientSize();

    if ((curPos.x < clientSize.x) && (curPos.y < clientSize.y))
    {
        SetCursor(wxCURSOR_HAND);
    }else
    {
        SetCursor(wxCURSOR_ARROW);
    }

}

void PhotoStarCtrl::SetPhotoLevel(int level)
{
    m_start = level;

    MakeStartBmp();

    this->SetBitmap(*m_bmp);

}

void PhotoStarCtrl::OnMouseDown(wxMouseEvent& event)
{

    wxPoint curPos = event.GetPosition();
    if ((curPos.x > 0) && (curPos.x < StarW))
    {
        if (m_start > 1)
            m_start = 1;
        else if (m_start <= 0)
            m_start = 1;
        else
            m_start = 0;

    }else if ((curPos.x > StarW) && (curPos.x < StarW*2))
    {
        m_start = 2;

    }else if ((curPos.x > StarW*2) && (curPos.x < StarW*3))
    {
        m_start = 3;
    }

    if (isViewModel == false)
    {                         // 这里添加你的处理程序，鼠标点击一次执行一次


/*
        if (wxGetApp().m_PhotoLevel < 0) // 判断是否新建
        {
            wxGetApp().phouseDB.addImageXing(folderid, m_photoname, m_start); // 新建
        }else
        {
            wxGetApp().phouseDB.updateImageXing(folderid, m_photoname, m_start); // 修改
        }

        wxGetApp().m_PhotoLevel = m_start; // 更新全局变量

        wxGetApp().m_items[wxGetApp().m_index].m_PhotoLevel = m_start;
*/
    }


    MakeStartBmp();

    this->SetBitmap(*m_bmp);

    wxString str = wxString::Format(wxT("你选择了 %d 颗星"), m_start);
    wxMessageBox(str, wxT("信息"));

}

