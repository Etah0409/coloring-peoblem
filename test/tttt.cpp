// tttt.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test.h"
#include "tttt.h"
#include "afxdialogex.h"


// tttt �Ի���

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


// tttt ��Ϣ�������


void tttt::OnBnClickedOk()
{

	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}
