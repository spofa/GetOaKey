// GetOAKeyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GetOAKey.h"
#include "GetOAKeyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define CHECK_EXE
//#define FPTW_EXE
//#define IDRV_DLL
//#define PMX_DLL
//#define FPARTS_TXT
#define AFUWIN_EXE
#define AMIFLDRV32_DLL
#define AMIFLDRV64_DLL

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CGetOAKeyDlg dialog




CGetOAKeyDlg::CGetOAKeyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGetOAKeyDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGetOAKeyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGetOAKeyDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_PRODUCTKEY, &CGetOAKeyDlg::OnBnClickedProductkey)
	ON_BN_CLICKED(IDC_DPKWRITE, &CGetOAKeyDlg::OnBnClickedDpkwrite)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CGetOAKeyDlg message handlers

BOOL CGetOAKeyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}



	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	GetTempPath(MAX_PATH,m_szTempDir);
	strcpy(m_szTempDir,getenv("SystemRoot"));
	strcat(m_szTempDir,"\\Temp");
	DWORD dwLen;
	CFile fp;
	BOOL bRet;
	char szFileName[MAX_PATH];
	SetCurrentDirectory(m_szTempDir);
//---------------------------------------------------------------------
	//Microsoft tools
#ifdef CHECK_EXE
	HRSRC hSrc = FindResource(NULL,MAKEINTRESOURCE(IDR_CHECK),"DATA");
	HGLOBAL hGl = LoadResource(NULL,hSrc);
	dwLen = SizeofResource(NULL,hSrc);
	LPBYTE lpBuf = (LPBYTE)LockResource(hGl);
	bRet = fp.Open("Check.exe",CFile::modeCreate|CFile::modeReadWrite);
	fp.Write((LPBYTE)lpBuf,dwLen);
	fp.Close();

	hSrc = FindResource(NULL,MAKEINTRESOURCE(IDR_OATOOL),"DATA");
	hGl = LoadResource(NULL,hSrc);
	dwLen = SizeofResource(NULL,hSrc);
	lpBuf = (LPBYTE)LockResource(hGl);
	fp.Open("oa3tool.exe",CFile::modeCreate|CFile::modeReadWrite);
	fp.Write((LPBYTE)lpBuf,dwLen);
	fp.Close();

	hSrc = FindResource(NULL,MAKEINTRESOURCE(IDR_CFG),"DATA");
	hGl = LoadResource(NULL,hSrc);
	dwLen = SizeofResource(NULL,hSrc);
	lpBuf = (LPBYTE)LockResource(hGl);
	fp.Open("oa3toolfile.cfg",CFile::modeCreate|CFile::modeReadWrite);
	fp.Write((LPBYTE)lpBuf,dwLen);
	fp.Close();
#endif
	//Intel tools
#ifdef FPTW_EXE
	HRSRC hSrc = FindResource(NULL,MAKEINTRESOURCE(IDR_FPTW),"DATA");
	HGLOBAL hGl = LoadResource(NULL,hSrc);
	dwLen = SizeofResource(NULL,hSrc);
	LPBYTE lpBuf = (LPBYTE)LockResource(hGl);
	bRet = fp.Open("fptw.exe",CFile::modeCreate|CFile::modeReadWrite);
	fp.Write((LPBYTE)lpBuf,dwLen);
	fp.Close();
#endif
#ifdef IDRV_DLL
	hSrc = FindResource(NULL,MAKEINTRESOURCE(IDR_IDRVDLL),"DATA");
	hGl = LoadResource(NULL,hSrc);
	dwLen = SizeofResource(NULL,hSrc);
	lpBuf = (LPBYTE)LockResource(hGl);
	bRet = fp.Open("idrvdll.dll",CFile::modeCreate|CFile::modeReadWrite);
	fp.Write((LPBYTE)lpBuf,dwLen);
	fp.Close();
#endif
#ifdef PMX_DLL
	hSrc = FindResource(NULL,MAKEINTRESOURCE(IDR_PMXDLL),"DATA");
	hGl = LoadResource(NULL,hSrc);
	dwLen = SizeofResource(NULL,hSrc);
	lpBuf = (LPBYTE)LockResource(hGl);
	bRet = fp.Open("pmxdll.dll",CFile::modeCreate|CFile::modeReadWrite);
	fp.Write((LPBYTE)lpBuf,dwLen);
	fp.Close();
#endif
#ifdef FPARTS_TXT
	hSrc = FindResource(NULL,MAKEINTRESOURCE(IDR_FPARTS),"DATA");
	hGl = LoadResource(NULL,hSrc);
	dwLen = SizeofResource(NULL,hSrc);
	lpBuf = (LPBYTE)LockResource(hGl);
	bRet = fp.Open("fparts.txt",CFile::modeCreate|CFile::modeReadWrite);
	fp.Write((LPBYTE)lpBuf,dwLen);
	fp.Close();
#endif
	//AMI tools
#ifdef AFUWIN_EXE
	hSrc = FindResource(NULL,MAKEINTRESOURCE(IDR_AFUWIN),"DATA");
	hGl = LoadResource(NULL,hSrc);
	dwLen = SizeofResource(NULL,hSrc);
	lpBuf = (LPBYTE)LockResource(hGl);
	bRet = fp.Open("afuwin.exe",CFile::modeCreate|CFile::modeReadWrite);
	fp.Write((LPBYTE)lpBuf,dwLen);
	fp.Close();
#endif
#ifdef AMIFLDRV32_DLL
	hSrc = FindResource(NULL,MAKEINTRESOURCE(IDR_AMIFLDRV32),"DATA");
	hGl = LoadResource(NULL,hSrc);
	dwLen = SizeofResource(NULL,hSrc);
	lpBuf = (LPBYTE)LockResource(hGl);
	bRet = fp.Open("amifldrv32.sys",CFile::modeCreate|CFile::modeReadWrite);
	fp.Write((LPBYTE)lpBuf,dwLen);
	fp.Close();
#endif
#ifdef AMIFLDRV64_DLL
	hSrc = FindResource(NULL,MAKEINTRESOURCE(IDR_AMIFLDRV64),"DATA");
	hGl = LoadResource(NULL,hSrc);
	dwLen = SizeofResource(NULL,hSrc);
	lpBuf = (LPBYTE)LockResource(hGl);
	bRet = fp.Open("amifldrv64.sys",CFile::modeCreate|CFile::modeReadWrite);
	fp.Write((LPBYTE)lpBuf,dwLen);
	fp.Close();
#endif
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGetOAKeyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGetOAKeyDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGetOAKeyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CGetOAKeyDlg::GetProductKey(void)
{
	CWaitCursor wc;
	BOOL retval;
	PROCESS_INFORMATION pi={0};
	STARTUPINFO si={0};
	SECURITY_ATTRIBUTES sa={0};
	HANDLE hReadPipe,hWritePipe;
	DWORD retcode = -1;
	CFile fp;

	sa.bInheritHandle=TRUE;
	sa.nLength=sizeof SECURITY_ATTRIBUTES;
	sa.lpSecurityDescriptor=NULL;
	retval=CreatePipe(&hReadPipe,&hWritePipe,&sa,0);
	if(retval)
	{
		si.cb=sizeof STARTUPINFO;
		si.wShowWindow=SW_HIDE;
		si.dwFlags=STARTF_USESHOWWINDOW|STARTF_USESTDHANDLES;
		si.hStdOutput=si.hStdError=hWritePipe;
		retval=CreateProcess(NULL,"cmd.exe /c Check.exe",&sa,&sa,TRUE,0,NULL,m_szTempDir,&si,&pi);
		if(retval)
		{
			DWORD dwLen,dwRead;
			WaitForSingleObject(pi.hThread,INFINITE);//等待命令行执行完毕
			GetExitCodeProcess(pi.hProcess,&retcode);
			CloseHandle(pi.hThread);
			CloseHandle(pi.hProcess);
			if (retcode != 0)
			{
				SetDlgItemText(IDC_DPK,"Product Key is unavailable");
				goto end;
			}
			dwLen=GetFileSize(hReadPipe,NULL);
			char *buff=new char [dwLen+1];
			char dpk[30]={0};
			char* vptr,*token="Product key:       ";
			memset(buff,0,dwLen+1);
			retval=ReadFile(hReadPipe,buff,dwLen,&dwRead,NULL);
			vptr=strstr(buff+700,token);
			if (vptr)
			{
				vptr +=strlen(token);
				strncpy(dpk,vptr,29);
			}
			SetDlgItemText(IDC_DPK,dpk);
			SetDlgItemText(IDC_DPKSAVE,"");
			delete buff;
		}
		retval=CreateProcess(NULL,"cmd.exe /c oa3tool.exe /report /configfile=oa3toolfile.cfg",&sa,&sa,TRUE,0,NULL,m_szTempDir,&si,&pi);
		if(retval)
		{
			DWORD dwLen,dwRead;
			WaitForSingleObject(pi.hThread,INFINITE);//等待命令行执行完毕
			GetExitCodeProcess(pi.hProcess,&retcode);
			CloseHandle(pi.hThread);
			CloseHandle(pi.hProcess);
			if (retcode)
			{
				SetDlgItemText(IDC_PKID,"");
				goto end;
			}
			if (!fp.Open("oa3.xml",CFile::modeRead|CFile::typeBinary))
			{
				SetDlgItemText(IDC_PKID,"");
				goto end;
			}
			dwLen=(DWORD)fp.GetLength();
			char* fBuff = new char[dwLen];
			char pkid[14]={0};
			fp.Read(fBuff,dwLen);
			fp.Close();
			char* dpk=strstr(fBuff,"<ProductKeyID>");
			if (dpk)
			{
				strncpy(pkid,dpk+14,13);
				SetDlgItemText(IDC_PKID,pkid);
			}
			delete fBuff;
		}
end:
		CloseHandle(hWritePipe);
		CloseHandle(hReadPipe);
	}
	else
	{
		SetDlgItemText(IDC_DPK,"Product Key is unavailable");
		SetDlgItemText(IDC_PKID,"");
	}
}

void CGetOAKeyDlg::InjectProductKey(void)
{
	CWaitCursor wc;
	BOOL retval;
	PROCESS_INFORMATION pi={0};
	STARTUPINFO si={0};
	SECURITY_ATTRIBUTES sa={0};

	sa.bInheritHandle=FALSE;
	sa.nLength=sizeof SECURITY_ATTRIBUTES;
	sa.lpSecurityDescriptor=NULL;
	si.cb=sizeof STARTUPINFO;
	si.wShowWindow=SW_SHOW;
	si.dwFlags=STARTF_USESHOWWINDOW;
	si.hStdOutput=si.hStdError=NULL;
	retval=CreateProcess(NULL,"cmd.exe /c afuwin.exe /oad && afuwin.exe /atmp.bin",&sa,&sa,0,0,NULL,m_szTempDir,&si,&pi);
	if(retval)
	{
		WaitForSingleObject(pi.hThread,INFINITE);//等待命令行执行完毕
		CloseHandle(pi.hThread);
		CloseHandle(pi.hProcess);
	}
}

void CGetOAKeyDlg::OnBnClickedProductkey()
{
	// TODO: Add your control notification handler code here
	CloseHandle(CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)GetKeyThread,this,0,NULL));
}

void CGetOAKeyDlg::OnBnClickedDpkwrite()
{
	// TODO: Add your control notification handler code here
	CWaitCursor wc;
	CString szKey;
	GetDlgItemText(IDC_DPKSAVE,szKey);
	if (szKey.GetLength()!=29)
	{
		MessageBox("Key length is incorrect","ProductKeyTool",MB_ICONERROR);
		return;
	}
	char szVerify[32]={0};
	strcpy(szVerify,(LPSTR)(LPCSTR)szKey);
	char* p=strtok(szVerify,"-");
	char* p2 = p;
	int i=5;
	while (i--)
	{
		p2=p;
		if (strlen(p2) != 5)
		{
			MessageBox("Key format is incorrect","ProductKeyTool",MB_ICONERROR);
			return;
		}
		while (*p2)
		{
			if (!isalnum(*p2))
			{
				MessageBox("Key contains illegal characters","ProductKeyTool",MB_ICONERROR);
				return;
			}
			p2++;
		}
		p = strtok(NULL,"-");
	}
	char szDPK[20]={0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					0x1d,0x00,0x00,0x00};
	CFile fp;
	if (!fp.Open("tmp.bin",CFile::modeCreate|CFile::modeWrite|CFile::typeBinary))
	{
		MessageBox("Create key file failed!","ProductKeyTool",MB_ICONERROR);
		return;
	}
	fp.Write(szDPK,20);
	fp.Write((LPSTR)(LPCTSTR)szKey,szKey.GetLength());
	fp.Close();
	CloseHandle(CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)InjectKeyThread,this,0,NULL));
}

UINT CGetOAKeyDlg::GetKeyThread(LPVOID lp)
{
	CGetOAKeyDlg* p = (CGetOAKeyDlg*)lp;
	p->GetDlgItem(IDC_PRODUCTKEY)->EnableWindow(0);
	p->GetDlgItem(IDC_DPKWRITE)->EnableWindow(0);
	EnableMenuItem(::GetSystemMenu(p->m_hWnd,FALSE),SC_CLOSE,MF_BYCOMMAND|MF_DISABLED);
	p->GetProductKey();
	p->GetDlgItem(IDC_PRODUCTKEY)->EnableWindow();
	p->GetDlgItem(IDC_DPKWRITE)->EnableWindow();
	EnableMenuItem(::GetSystemMenu(p->m_hWnd,FALSE),SC_CLOSE,MF_BYCOMMAND|MF_ENABLED);
	return 0L;
}

UINT CGetOAKeyDlg::InjectKeyThread(LPVOID lp)
{
	CGetOAKeyDlg* p = (CGetOAKeyDlg*)lp;
	p->GetDlgItem(IDC_PRODUCTKEY)->EnableWindow(0);
	p->GetDlgItem(IDC_DPKWRITE)->EnableWindow(0);
	EnableMenuItem(::GetSystemMenu(p->m_hWnd,FALSE),SC_CLOSE,MF_BYCOMMAND|MF_DISABLED);
	p->InjectProductKey();
	p->GetDlgItem(IDC_PRODUCTKEY)->EnableWindow();
	p->GetDlgItem(IDC_DPKWRITE)->EnableWindow();
	EnableMenuItem(::GetSystemMenu(p->m_hWnd,FALSE),SC_CLOSE,MF_BYCOMMAND|MF_ENABLED);
	return 0L;
}
void CGetOAKeyDlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: Add your message handler code here
	char szFileName[MAX_PATH];
//---------------------------------------------------------------------
	//Microsoft tools
#ifdef CHECK_EXE
	DeleteFile("Check.exe");
	DeleteFile("oa3tool.exe");
	DeleteFile("oa3toolfile.cfg");
#endif
	//Intel tools
#ifdef FPTW_EXE
	DeleteFile("fptw.exe");
#endif
#ifdef IDRV_DLL
	DeleteFile("idrvdll.dll");
#endif
#ifdef PMX_DLL
	DeleteFile("pmxdll.dll");
#endif
#ifdef FPARTS_TXT
	DeleteFile("fparts.txt");
#endif
	//AMI tools
#ifdef AFUWIN_EXE
	DeleteFile("afuwin.exe");
#endif
#ifdef AMIFLDRV32_DLL
	DeleteFile("amifldrv32.sys");
#endif
#ifdef AMIFLDRV64_DLL
	DeleteFile("amifldrv64.sys");
#endif
	DeleteFile("tmp.bin");
	DeleteFile("oa3.xml");
}
