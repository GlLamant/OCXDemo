#pragma once
#include "MyClass.h"

// demoCtrl.h : CdemoCtrl ActiveX 控件类的声明。


// CdemoCtrl : 有关实现的信息，请参阅 demoCtrl.cpp。

class CdemoCtrl : public COleControl
{
	DECLARE_DYNCREATE(CdemoCtrl)

// 构造函数
public:
	CdemoCtrl();

// 重写
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	virtual DWORD GetControlFlags();

// 实现
protected:
	~CdemoCtrl();
	CMyClass m_window;

	DECLARE_OLECREATE_EX(CdemoCtrl)    // 类工厂和 guid
	DECLARE_OLETYPELIB(CdemoCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CdemoCtrl)     // 属性页 ID
	DECLARE_OLECTLTYPE(CdemoCtrl)		// 类型名称和杂项状态

// 消息映射
	DECLARE_MESSAGE_MAP()

// 调度映射
	DECLARE_DISPATCH_MAP()

// 事件映射
	DECLARE_EVENT_MAP()
	
// 调度和事件 ID
public:
	enum {
		dispidfunction = 1L,
		eventidevent1 = 1L
	};
protected:
	//用于响应MyClass.h中的自定义消息
	afx_msg LRESULT OnMyClassHandler(WPARAM, LPARAM);

	//添加的事件，用于js实现控件的事件响应
	void event1()
	{
		FireEvent(eventidevent1, EVENT_PARAM(VTS_NONE));
	}

public:
	//重载了OnCreate()和OnSize()，用于在网页调用时创建并自定义（尺寸、位置）显示
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
protected:
	void function();
};

