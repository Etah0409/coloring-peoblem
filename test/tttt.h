#pragma once


// tttt �Ի���

class tttt : public CDialogEx
{
	DECLARE_DYNAMIC(tttt)

public:
	tttt(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~tttt();

// �Ի�������
	enum { IDD = IDD_DIALOG_INPUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
