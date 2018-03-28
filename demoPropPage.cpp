// demoPropPage.cpp : CdemoPropPage 属性页类的实现。

#include "stdafx.h"
#include "demo.h"
#include "demoPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CdemoPropPage, COlePropertyPage)

// 消息映射

BEGIN_MESSAGE_MAP(CdemoPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CdemoPropPage, "DEMO.demoPropPage.1",
	0xa135e1d5, 0x3aa9, 0x4803, 0x8b, 0x30, 0x2a, 0x9, 0x6d, 0xad, 0xcd, 0x1)

// CdemoPropPage::CdemoPropPageFactory::UpdateRegistry -
// 添加或移除 CdemoPropPage 的系统注册表项

BOOL CdemoPropPage::CdemoPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_DEMO_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CdemoPropPage::CdemoPropPage - 构造函数

CdemoPropPage::CdemoPropPage() :
	COlePropertyPage(IDD, IDS_DEMO_PPG_CAPTION)
{
}

// CdemoPropPage::DoDataExchange - 在页和属性间移动数据

void CdemoPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CdemoPropPage 消息处理程序
