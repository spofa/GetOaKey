// GetOAKeyDlg.h : header file
//

#pragma once


// CGetOAKeyDlg dialog
class CGetOAKeyDlg : public CDialog
{
// Construction
public:
	CGetOAKeyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_GETOAKEY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	char m_szTempDir[MAX_PATH];
private:
	void GetProductKey(void);
	void InjectProductKey(void);
	static UINT GetKeyThread(LPVOID lp);
	static UINT InjectKeyThread(LPVOID lp);
public:
	afx_msg void OnBnClickedProductkey();
public:
	afx_msg void OnBnClickedDpkwrite();
	afx_msg void OnDestroy();
};
