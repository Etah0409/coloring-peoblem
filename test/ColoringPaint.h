#pragma once

#include "Atrix.h"
// ColoringPaint �Ի���

class ColoringPaint : public CDialogEx
{
	DECLARE_DYNAMIC(ColoringPaint)

public:
	ColoringPaint(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ColoringPaint();
	Node *node;	
	int map[atrixSize][atrixSize];
// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	//afx_msg void OnPaintClipboard(CWnd* pClipAppWnd, HGLOBAL hPaintStruct);
	afx_msg void OnPaint();
};
