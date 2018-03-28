// demoCtrl.cpp : CdemoCtrl ActiveX �ؼ����ʵ�֡�

#include "stdafx.h"
#include "demo.h"
#include "demoCtrl.h"
#include "demoPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CdemoCtrl, COleControl)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CdemoCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_MESSAGE(WM_BUTTONCLICK1,OnMyClassHandler)			//������ʵ������Ϣӳ�䣬�����ǽ�WM_BUTTONCLICK1�ڴ���ʱ������Ϣ���У�ִ��OnMyClassHandler()����
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// ����ӳ��

BEGIN_DISPATCH_MAP(CdemoCtrl, COleControl)
	DISP_STOCKPROP_READYSTATE()
	DISP_FUNCTION_ID(CdemoCtrl, "function", dispidfunction, function, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()

// �¼�ӳ��

BEGIN_EVENT_MAP(CdemoCtrl, COleControl)
	EVENT_STOCK_READYSTATECHANGE()
	EVENT_CUSTOM_ID("event1", eventidevent1, event1, VTS_NONE)		//ʵ�����¼�ӳ�䣬����js�Կؼ����¼���Ӧ
END_EVENT_MAP()

// ����ҳ

// TODO: ������Ҫ��Ӹ�������ҳ�����ס���Ӽ���!
BEGIN_PROPPAGEIDS(CdemoCtrl, 1)
	PROPPAGEID(CdemoPropPage::guid)
END_PROPPAGEIDS(CdemoCtrl)

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CdemoCtrl, "DEMO.demoCtrl.1",
	0x4ca8f922, 0xcb1e, 0x4051, 0xbc, 0xc5, 0x23, 0xee, 0xb4, 0xc2, 0xb3, 0x2)

// ����� ID �Ͱ汾

IMPLEMENT_OLETYPELIB(CdemoCtrl, _tlid, _wVerMajor, _wVerMinor)

// �ӿ� ID

const IID IID_Ddemo = { 0x21DADA62, 0xA40, 0x41B0, { 0x85, 0xD9, 0x7B, 0xD3, 0xA2, 0x94, 0x24, 0x95 } };
const IID IID_DdemoEvents = { 0xF1278A1D, 0x32C6, 0x4DCB, { 0x9C, 0xD3, 0x1F, 0xAD, 0x2B, 0x14, 0xB8, 0xF1 } };

// �ؼ�������Ϣ

static const DWORD _dwdemoOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CdemoCtrl, IDS_DEMO, _dwdemoOleMisc)

// CdemoCtrl::CdemoCtrlFactory::UpdateRegistry -
// ��ӻ��Ƴ� CdemoCtrl ��ϵͳע�����

BOOL CdemoCtrl::CdemoCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  ��֤���Ŀؼ��Ƿ���ϵ�Ԫģ���̴߳������
	// �йظ�����Ϣ����ο� MFC ����˵�� 64��
	// ������Ŀؼ������ϵ�Ԫģ�͹�����
	// �����޸����´��룬��������������
	// afxRegApartmentThreading ��Ϊ 0��

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_DEMO,
			IDB_DEMO,
			afxRegApartmentThreading,
			_dwdemoOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CdemoCtrl::CdemoCtrl - ���캯��

CdemoCtrl::CdemoCtrl()
{
	InitializeIIDs(&IID_Ddemo, &IID_DdemoEvents);

	m_lReadyState = READYSTATE_LOADING;
	// TODO:  �� readystate ����ʱ���� InternalSetReadyState��
	// TODO:  �ڴ˳�ʼ���ؼ���ʵ�����ݡ�
}

// CdemoCtrl::~CdemoCtrl - ��������

CdemoCtrl::~CdemoCtrl()
{
	// TODO:  �ڴ�����ؼ���ʵ�����ݡ�
}

LRESULT CdemoCtrl::OnMyClassHandler(WPARAM, LPARAM)
{
	//MessageBox(_T("enter OnMyClassHandler and execute event1() next"));
	event1();
	return LRESULT();
}

// CdemoCtrl::OnDraw - ��ͼ����

void CdemoCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  �����Լ��Ļ�ͼ�����滻����Ĵ��롣
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CdemoCtrl::DoPropExchange - �־���֧��

void CdemoCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Ϊÿ���־õ��Զ������Ե��� PX_ ������
}


// CdemoCtrl::GetControlFlags -
// �Զ��� MFC �� ActiveX �ؼ�ʵ�ֵı�־��
//
DWORD CdemoCtrl::GetControlFlags()
{
	DWORD dwFlags = COleControl::GetControlFlags();

	// ��ǰδ�����ؼ��������
	// �ؼ���֤��������Ƶ�����
	// ���ι�����֮�⡣
	dwFlags &= ~clipPaintDC;
	return dwFlags;
}


// CdemoCtrl::OnResetState - ���ؼ�����ΪĬ��״̬

void CdemoCtrl::OnResetState()
{
	COleControl::OnResetState();  // ���� DoPropExchange ���ҵ���Ĭ��ֵ

	// TODO:  �ڴ��������������ؼ�״̬��
}


// CdemoCtrl ��Ϣ�������


int CdemoCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	m_window.Create(IDD_MAIN, this);
	m_window.ShowWindow(SW_SHOW);
	return 0;
}


void CdemoCtrl::OnSize(UINT nType, int cx, int cy)
{
	COleControl::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	//λ�ÿ����Լ��������ã�����˵������ʾ��ʲô��
	CRect rect;
	GetClientRect(&rect);
	m_window.MoveWindow(&rect);
}

void CdemoCtrl::function()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: �ڴ���ӵ��ȴ���������
	m_window.setText();
}
