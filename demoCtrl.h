#pragma once
#include "MyClass.h"

// demoCtrl.h : CdemoCtrl ActiveX �ؼ����������


// CdemoCtrl : �й�ʵ�ֵ���Ϣ������� demoCtrl.cpp��

class CdemoCtrl : public COleControl
{
	DECLARE_DYNCREATE(CdemoCtrl)

// ���캯��
public:
	CdemoCtrl();

// ��д
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	virtual DWORD GetControlFlags();

// ʵ��
protected:
	~CdemoCtrl();
	CMyClass m_window;

	DECLARE_OLECREATE_EX(CdemoCtrl)    // �๤���� guid
	DECLARE_OLETYPELIB(CdemoCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CdemoCtrl)     // ����ҳ ID
	DECLARE_OLECTLTYPE(CdemoCtrl)		// �������ƺ�����״̬

// ��Ϣӳ��
	DECLARE_MESSAGE_MAP()

// ����ӳ��
	DECLARE_DISPATCH_MAP()

// �¼�ӳ��
	DECLARE_EVENT_MAP()
	
// ���Ⱥ��¼� ID
public:
	enum {
		dispidfunction = 1L,
		eventidevent1 = 1L
	};
protected:
	//������ӦMyClass.h�е��Զ�����Ϣ
	afx_msg LRESULT OnMyClassHandler(WPARAM, LPARAM);

	//��ӵ��¼�������jsʵ�ֿؼ����¼���Ӧ
	void event1()
	{
		FireEvent(eventidevent1, EVENT_PARAM(VTS_NONE));
	}

public:
	//������OnCreate()��OnSize()����������ҳ����ʱ�������Զ��壨�ߴ硢λ�ã���ʾ
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
protected:
	void function();
};

