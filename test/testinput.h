#pragma once


// testinput 对话框

class testinput : public CDialogEx
{
	DECLARE_DYNAMIC(testinput)

public:
	testinput(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~testinput();

// 对话框数据
	enum { IDD = IDD_DIALOG_INPUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
