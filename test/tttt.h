#pragma once


// tttt 对话框

class tttt : public CDialogEx
{
	DECLARE_DYNAMIC(tttt)

public:
	tttt(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~tttt();

// 对话框数据
	enum { IDD = IDD_DIALOG_INPUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
