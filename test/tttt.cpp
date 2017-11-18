// tttt.cpp : 实现文件
//

#include "stdafx.h"
#include "test.h"
#include "tttt.h"
#include "afxdialogex.h"


// tttt 对话框

IMPLEMENT_DYNAMIC(tttt, CDialogEx)

tttt::tttt(CWnd* pParent /*=NULL*/)
	: CDialogEx(tttt::IDD, pParent)
{

}

tttt::~tttt()
{
}

void tttt::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(tttt, CDialogEx)
	ON_BN_CLICKED(IDOK, &tttt::OnBnClickedOk)
END_MESSAGE_MAP()


// tttt 消息处理程序


void tttt::OnBnClickedOk()
{

	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
