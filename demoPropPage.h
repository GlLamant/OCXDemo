#pragma once

// demoPropPage.h : CdemoPropPage 属性页类的声明。


// CdemoPropPage : 有关实现的信息，请参阅 demoPropPage.cpp。

class CdemoPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CdemoPropPage)
	DECLARE_OLECREATE_EX(CdemoPropPage)

// 构造函数
public:
	CdemoPropPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_DEMO };

// 实现
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 消息映射
protected:
	DECLARE_MESSAGE_MAP()
};

