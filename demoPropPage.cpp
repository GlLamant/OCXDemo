// demoPropPage.cpp : CdemoPropPage ����ҳ���ʵ�֡�

#include "stdafx.h"
#include "demo.h"
#include "demoPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CdemoPropPage, COlePropertyPage)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CdemoPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CdemoPropPage, "DEMO.demoPropPage.1",
	0xa135e1d5, 0x3aa9, 0x4803, 0x8b, 0x30, 0x2a, 0x9, 0x6d, 0xad, 0xcd, 0x1)

// CdemoPropPage::CdemoPropPageFactory::UpdateRegistry -
// ��ӻ��Ƴ� CdemoPropPage ��ϵͳע�����

BOOL CdemoPropPage::CdemoPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_DEMO_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CdemoPropPage::CdemoPropPage - ���캯��

CdemoPropPage::CdemoPropPage() :
	COlePropertyPage(IDD, IDS_DEMO_PPG_CAPTION)
{
}

// CdemoPropPage::DoDataExchange - ��ҳ�����Լ��ƶ�����

void CdemoPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CdemoPropPage ��Ϣ�������
