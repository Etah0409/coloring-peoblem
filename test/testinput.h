#pragma once


// testinput �Ի���

class testinput : public CDialogEx
{
	DECLARE_DYNAMIC(testinput)

public:
	testinput(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~testinput();

// �Ի�������
	enum { IDD = IDD_DIALOG_INPUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
