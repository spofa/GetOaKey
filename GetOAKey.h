// GetOAKey.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CGetOAKeyApp:
// See GetOAKey.cpp for the implementation of this class
//

class CGetOAKeyApp : public CWinApp
{
public:
	CGetOAKeyApp();

// Overrides
	public:
	HANDLE m_hMutex;
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CGetOAKeyApp theApp;