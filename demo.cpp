// demo.cpp : CdemoApp 和 DLL 注册的实现。

#include "stdafx.h"
#include "demo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CdemoApp theApp;

const GUID CDECL _tlid = { 0xC656C404, 0xC4FC, 0x4D38, { 0xAC, 0x8D, 0xE5, 0x4A, 0x59, 0xFC, 0x39, 0x32 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CdemoApp::InitInstance - DLL 初始化

BOOL CdemoApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  在此添加您自己的模块初始化代码。
	}

	return bInit;
}



// CdemoApp::ExitInstance - DLL 终止

int CdemoApp::ExitInstance()
{
	// TODO:  在此添加您自己的模块终止代码。

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - 将项添加到系统注册表

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - 将项从系统注册表中移除

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
