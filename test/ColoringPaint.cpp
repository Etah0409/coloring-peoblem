// ColoringPaint.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test.h"
#include "ColoringPaint.h"
#include "afxdialogex.h"
#include "Atrix.h"
#define color1 RGB(121,196,175)
#define color2 RGB(222,216,92)
#define color3 RGB(248,174,114)
#define color4 RGB(233,112,123)
#define x this->node[i].getX()
#define y this->node[i].getY()

// ColoringPaint �Ի���

IMPLEMENT_DYNAMIC(ColoringPaint, CDialogEx)

ColoringPaint::ColoringPaint(CWnd* pParent /*=NULL*/)
	: CDialogEx(ColoringPaint::IDD, pParent)
{

}

ColoringPaint::~ColoringPaint()
{
}

void ColoringPaint::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ColoringPaint, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &ColoringPaint::OnBnClickedCancel)
	ON_WM_PAINTCLIPBOARD()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// ColoringPaint ��Ϣ�������


void ColoringPaint::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	for (int i = 0; i < Node::getCount(); i++)
		for (int k = 0; k < Node::getCount(); k++)
			node[i * Node::getCount() + k].Initi();
	Node::ReSetInitialNumber();
	CDialogEx::OnCancel();
}



void ColoringPaint::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	dc.FillSolidRect(0, 0, 500, 500, RGB(255, 255, 255));
	CPen newPen;	
	newPen.CreatePen(PS_SOLID,1,RGB(155,155,155));
	dc.SelectObject(&newPen);
	for (int i = 0; i < Node::getCount(); i++)
		for (int k = 0; k < Node::getCount(); k++)
		{
			if (this->map[i][k])
			{
				dc.MoveTo(this->node[i].getCoord());
				dc.LineTo(this->node[k].getCoord());
			}
		}

	for(int i = 0; i < Node::getCount(); i++)
	{
		CString str;
		CBrush newBrush;
		switch(this->node[i].getColor())
	    {
		case 1:newBrush.CreateSolidBrush(color1);break;
		case 2:newBrush.CreateSolidBrush(color2);break;
		case 3:newBrush.CreateSolidBrush(color3);break;
		case 4:newBrush.CreateSolidBrush(color4);break;
		}
		dc.SelectObject(&newBrush);
		dc.Ellipse(x-20,y-20,x+20,y+20);
		newBrush.DeleteObject();
		str.Format("%d", i+1);
		dc.TextOutA(x-5, y-10, str);
	}
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
}