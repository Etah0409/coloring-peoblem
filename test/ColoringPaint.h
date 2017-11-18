#pragma once

#include "Atrix.h"
// ColoringPaint 对话框

class ColoringPaint : public CDialogEx
{
	DECLARE_DYNAMIC(ColoringPaint)

public:
	ColoringPaint(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ColoringPaint();
	Node *node;	
	int map[atrixSize][atrixSize];
// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	//afx_msg void OnPaintClipboard(CWnd* pClipAppWnd, HGLOBAL hPaintStruct);
	afx_msg void OnPaint();
};
