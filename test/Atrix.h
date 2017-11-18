#pragma once
#define atrixSize 10

// Atrix 对话框

class Node
{
public:
	Node();
    void setNode(int degree,int index);
    friend void setColor(int map[atrixSize][atrixSize],Node node[atrixSize],int size);
	static int getCount();
	void setCoord(int size);
	int getIndex();
	int getColor();
	CPoint getCoord();
	int getX();
	int getY();
	void Initi();
	static void ReSetInitialNumber();
private:
	int index;
	int color;
	int degree;
	static int initialNumber;
	CPoint coord;
};


class Atrix : public CDialogEx
{
	public:
		friend class Node;
		static int Count;

	DECLARE_DYNAMIC(Atrix)

public:
	Atrix(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Atrix();

// 对话框数据
	enum { IDD = IDD_DIALOG_INPUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnClose();

public:
	CEdit *pedit;
	afx_msg void OnPaint();
};

