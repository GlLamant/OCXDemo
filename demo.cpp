// demo.cpp : CdemoApp �� DLL ע���ʵ�֡�

#include "stdafx.h"
#include "demo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CdemoApp theApp;

const GUID CDECL _tlid = { 0xC656C404, 0xC4FC, 0x4D38, { 0xAC, 0x8D, 0xE5, 0x4A, 0x59, 0xFC, 0x39, 0x32 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CdemoApp::InitInstance - DLL ��ʼ��

BOOL CdemoApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  �ڴ�������Լ���ģ���ʼ�����롣
	}

	return bInit;
}



// CdemoApp::ExitInstance - DLL ��ֹ

int CdemoApp::ExitInstance()
{
	// TODO:  �ڴ�������Լ���ģ����ֹ���롣

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - ������ӵ�ϵͳע���

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - �����ϵͳע������Ƴ�

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
