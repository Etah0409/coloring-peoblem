// Atrix.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test.h"
#include "Atrix.h"
#include "afxdialogex.h"
#include "ColoringPaint.h"
#include "algorithm"
#define ColInterval 60
#define RowInterval 50
#define lineLength 100
#define PI(n) 3.14*2*(this->index)/n - 3.14*3/n
// Atrix �Ի���

IMPLEMENT_DYNAMIC(Atrix, CDialogEx)
	
int Node::initialNumber=0;

void Node::Initi()
{
	this->color = 0;
	this->coord = 0;
	this->index = 0;
}

int Node::getCount()
{
	return initialNumber;
}

Node::Node()
{
}

int Node::getColor()
{
	return color;
}

int Node::getIndex()
{
	return index;
}

CPoint Node::getCoord()
{
	return coord;
}

int Node::getX()
{
	return coord.x;
}

int Node::getY()
{
	return coord.y;
}

void Node::setNode(int degree,int index)
{
    this->degree = degree;
	this->index = index;
	this->color = 0;
	this->coord.x = 0;
	this->coord.y = 0;

}

void setColor(int map[atrixSize][atrixSize],Node node[atrixSize],int size) //Ϳɫ
{
    for(int i = 0; i < size; i++)
    {
	    int colorNumber = 1; 
		for(int k = 0; k < Node::initialNumber; k++)
		{
			if(map[i][k] == 0&&i!=k&&node[i].color==0)
			{
				for(int j = k+1; j < Node::initialNumber; j++)
				{
					if(node[j].color==node[k].color&&map[i][j]==1)
						break;
					if(j==Node::initialNumber-1)
						node[i].color=node[k].color;
				}
			}
			else if(map[i][k] == 1)
				colorNumber++;
		}		
		if(node[i].color==0)
			node[i].color=colorNumber;
	   Node::initialNumber++; 
	   node[i].setCoord(size);
	}
}

void Node::ReSetInitialNumber()
{
	initialNumber = 0;
}

void Node::setCoord(int size)
{
		this->coord.x = 200 - 100 * sin(PI(size));
		this->coord.y = 150 + 100 * cos(PI(size));
}


Atrix::Atrix(CWnd* pParent /*=NULL*/)
	: CDialogEx(Atrix::IDD, pParent)
{

}

Atrix::~Atrix()
{
}

void Atrix::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Atrix, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON4, &Atrix::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &Atrix::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &Atrix::OnBnClickedButton5)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// Atrix ��Ϣ�������


void Atrix::OnBnClickedButton4()
{   //���
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	for (int i = 0; i < Count; i++)
		for(int k = 0; k < Count; k++)
		   pedit[i * Count + k].SetWindowTextA("");
		
}


void Atrix::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	CDialogEx::OnCancel();
}


void Atrix::OnBnClickedButton5()
{
	//������ɫͼ
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	INT_PTR Res;// ���ڱ���DoModal�����ķ���ֵ
	CString temp; int countCorrectNumber = 0;
	ColoringPaint paint;
	paint.node = new Node[atrixSize];
	for(int i =0; i < Count; i++)
	    for(int k = 0; k < Count; k++)
		{
		    pedit[i*Count+k].GetWindowTextA(temp);
			paint.map[i][k] = strtoul(temp, NULL, 10);
		    if(strtoul(temp,NULL,0) == 0 || strtoul(temp,NULL,0) == 1)
					countCorrectNumber++;
       }
		for(int i = 0; i < Count; i++){
			int degree = 0;
			for(int k = 0; k < Count; k++)
			{ 
				if(paint.map[i][k])
				degree++;
			 } 
				paint.node[i].setNode(degree,i+1);
		}	
		setColor(paint.map,paint.node,Count);
		if(countCorrectNumber == Count * Count)
		{
		    Res = paint.DoModal();
		       if(IDCANCEL == Res)
				return;
		}
	    else
		{
			for (int i = 0; i < Count; i++)
		         for (int k = 0; k < Count; k++)
			         paint.node[i * Count + k].Initi();
	                    Node::ReSetInitialNumber();
			AfxMessageBox("�ڽӾ���ֻ��0��1��ʾ�����ضԽ��߶Գơ����������룡");//���
		
		}
}


int Atrix::Count = 0;

int Atrix::OnCreate(LPCREATESTRUCT lpCreateStruct)  //�������
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;
	int countNumber = 0, left = 50, top = 20, right = 80, bottom = 80;

	for(; countNumber < Count; countNumber++) //���ű�ʾ
	{
		CString count;
	    count.Format("%d",countNumber);
        CStatic *staticNumber = new CStatic;
        staticNumber->Create(count,WS_CHILD|WS_VISIBLE|SS_CENTER,CRect(left,top,right,bottom),this);
		left += ColInterval;
		right += ColInterval;
	}
	left = -10;
	top = 60;
	right = 80;
	bottom = 80;
	countNumber = 0;
		for(; countNumber < Count; countNumber++) //���ű�ʾ
	{
		CString count;
	    count.Format("%d",countNumber);
        CStatic *staticNumber = new CStatic;
        staticNumber->Create(count,WS_CHILD|WS_VISIBLE|SS_CENTER,CRect(left,top,right,bottom),this);
		top += RowInterval;
		bottom += RowInterval;
	}

	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CRect rect(50,50,80,80);

	pedit = new CEdit[Count*Count]; 
	for(int i = 0; i < Count; i++)
	{
		for(int k = 0; k < Count; k++)
	    {
		    pedit[i*Count+k].Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER, rect, this, i*Count+k+1);
			rect.right += ColInterval;
			rect.left += ColInterval;
	    }
		rect.top += RowInterval;
		rect.bottom += RowInterval;
		rect.right = 80;
		rect.left = 50;	
	}

	// TODO:  �ڴ������ר�õĴ�������

	return 0;
}


void Atrix::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	delete[] pedit;

	CDialogEx::OnClose();
}


void Atrix::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	 CBitmap   bitmap; 
     bitmap.LoadBitmap(IDB_BITMAP4);    //���IDB_BITMAP1Ҫ�Լ���� 
     CBrush   brush; 
     brush.CreatePatternBrush(&bitmap); 
     CBrush*   pOldBrush   =   dc.SelectObject(&brush); 
	 dc.Rectangle(0,0,550,500);   // ��Щ�������Ե���ͼƬ���λ�úʹ�С 
	 dc.SelectObject(pOldBrush); 
}
