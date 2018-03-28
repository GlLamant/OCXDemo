// demoCtrl.cpp : CdemoCtrl ActiveX 控件类的实现。

#include "stdafx.h"
#include "demo.h"
#include "demoCtrl.h"
#include "demoPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CdemoCtrl, COleControl)

// 消息映射

BEGIN_MESSAGE_MAP(CdemoCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_MESSAGE(WM_BUTTONCLICK1,OnMyClassHandler)			//这句代码实现了消息映射，作用是将WM_BUTTONCLICK1在触发时放入消息队列，执行OnMyClassHandler()函数
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// 调度映射

BEGIN_DISPATCH_MAP(CdemoCtrl, COleControl)
	DISP_STOCKPROP_READYSTATE()
	DISP_FUNCTION_ID(CdemoCtrl, "function", dispidfunction, function, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()

// 事件映射

BEGIN_EVENT_MAP(CdemoCtrl, COleControl)
	EVENT_STOCK_READYSTATECHANGE()
	EVENT_CUSTOM_ID("event1", eventidevent1, event1, VTS_NONE)		//实现了事件映射，用于js对控件的事件响应
END_EVENT_MAP()

// 属性页

// TODO: 根据需要添加更多属性页。请记住增加计数!
BEGIN_PROPPAGEIDS(CdemoCtrl, 1)
	PROPPAGEID(CdemoPropPage::guid)
END_PROPPAGEIDS(CdemoCtrl)

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CdemoCtrl, "DEMO.demoCtrl.1",
	0x4ca8f922, 0xcb1e, 0x4051, 0xbc, 0xc5, 0x23, 0xee, 0xb4, 0xc2, 0xb3, 0x2)

// 键入库 ID 和版本

IMPLEMENT_OLETYPELIB(CdemoCtrl, _tlid, _wVerMajor, _wVerMinor)

// 接口 ID

const IID IID_Ddemo = { 0x21DADA62, 0xA40, 0x41B0, { 0x85, 0xD9, 0x7B, 0xD3, 0xA2, 0x94, 0x24, 0x95 } };
const IID IID_DdemoEvents = { 0xF1278A1D, 0x32C6, 0x4DCB, { 0x9C, 0xD3, 0x1F, 0xAD, 0x2B, 0x14, 0xB8, 0xF1 } };

// 控件类型信息

static const DWORD _dwdemoOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CdemoCtrl, IDS_DEMO, _dwdemoOleMisc)

// CdemoCtrl::CdemoCtrlFactory::UpdateRegistry -
// 添加或移除 CdemoCtrl 的系统注册表项

BOOL CdemoCtrl::CdemoCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  验证您的控件是否符合单元模型线程处理规则。
	// 有关更多信息，请参考 MFC 技术说明 64。
	// 如果您的控件不符合单元模型规则，则
	// 必须修改如下代码，将第六个参数从
	// afxRegApartmentThreading 改为 0。

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


// CdemoCtrl::CdemoCtrl - 构造函数

CdemoCtrl::CdemoCtrl()
{
	InitializeIIDs(&IID_Ddemo, &IID_DdemoEvents);

	m_lReadyState = READYSTATE_LOADING;
	// TODO:  当 readystate 更改时调用 InternalSetReadyState。
	// TODO:  在此初始化控件的实例数据。
}

// CdemoCtrl::~CdemoCtrl - 析构函数

CdemoCtrl::~CdemoCtrl()
{
	// TODO:  在此清理控件的实例数据。
}

LRESULT CdemoCtrl::OnMyClassHandler(WPARAM, LPARAM)
{
	//MessageBox(_T("enter OnMyClassHandler and execute event1() next"));
	event1();
	return LRESULT();
}

// CdemoCtrl::OnDraw - 绘图函数

void CdemoCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  用您自己的绘图代码替换下面的代码。
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CdemoCtrl::DoPropExchange - 持久性支持

void CdemoCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: 为每个持久的自定义属性调用 PX_ 函数。
}


// CdemoCtrl::GetControlFlags -
// 自定义 MFC 的 ActiveX 控件实现的标志。
//
DWORD CdemoCtrl::GetControlFlags()
{
	DWORD dwFlags = COleControl::GetControlFlags();

	// 当前未剪辑控件的输出。
	// 控件保证它不会绘制到它的
	// 矩形工作区之外。
	dwFlags &= ~clipPaintDC;
	return dwFlags;
}


// CdemoCtrl::OnResetState - 将控件重置为默认状态

void CdemoCtrl::OnResetState()
{
	COleControl::OnResetState();  // 重置 DoPropExchange 中找到的默认值

	// TODO:  在此重置任意其他控件状态。
}


// CdemoCtrl 消息处理程序


int CdemoCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	m_window.Create(IDD_MAIN, this);
	m_window.ShowWindow(SW_SHOW);
	return 0;
}


void CdemoCtrl::OnSize(UINT nType, int cx, int cy)
{
	COleControl::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	//位置可以自己测量设置，比如说居中显示啊什么的
	CRect rect;
	GetClientRect(&rect);
	m_window.MoveWindow(&rect);
}

void CdemoCtrl::function()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: 在此添加调度处理程序代码
	m_window.setText();
}
