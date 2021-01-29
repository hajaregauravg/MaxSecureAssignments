
// finalView.cpp : implementation of the CfinalView class
//
#include "stdafx.h"
#include "final.h"
#include "finalDoc.h"
#include "finalView.h"
#include "windows.h"

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CfinalView

IMPLEMENT_DYNCREATE(CfinalView, CFormView)

BEGIN_MESSAGE_MAP(CfinalView, CFormView)
END_MESSAGE_MAP()

// CfinalView construction/destruction

CfinalView::CfinalView()
	: CFormView(CfinalView::IDD)
{
	// TODO: add construction code here

}

CfinalView::~CfinalView()
{
}

void CfinalView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CfinalView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CfinalView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void CfinalView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CfinalView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CfinalView diagnostics

#ifdef _DEBUG
void CfinalView::AssertValid() const
{
	CFormView::AssertValid();
}

void CfinalView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CfinalDoc* CfinalView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CfinalDoc)));
	return (CfinalDoc*)m_pDocument;
}
#endif //_DEBUG


// CfinalView message handlers
BEGIN_EVENTSINK_MAP(CfinalView, CFormView)
	ON_EVENT(CfinalView, IDC_COMMANDBUTTON1, DISPID_CLICK, CfinalView::ClickCommandbutton1, VTS_NONE)
END_EVENTSINK_MAP()

void tree(char *basePath, const int root, FILE * pFile)
{
    int i;
    char path[1000];	


    struct dirent *dp;
    DIR *dir = opendir(basePath);

    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL){
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0){
            for (i=0; i<root; i++) {
                if (i%2 == 0 || i == 0)
                    fprintf(pFile,"|");
                else
                    fprintf(pFile,"_");
			}

            fprintf(pFile,"|---%s\n", dp->d_name);

            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            tree(path, root + 2, pFile);
        }
    }

    closedir(dir);
}
void CfinalView::ClickCommandbutton1()
{
	char *path, ch[100];
	FILE * pFile;
	LPWSTR ptr;
	wchar_t wtext[200];

	path = "C:\\random";
	pFile = fopen ("result2.txt","w");
    tree(path, 0, pFile);
	fclose (pFile);
	pFile = fopen ("result2.txt","r");
	while(fscanf (pFile, "%s", ch) != EOF){
		strcat(ch,"\n");
		mbstowcs(wtext, ch, strlen(ch)+1);
		ptr = wtext;
		OutputDebugString(ptr);
	}
	fclose(pFile);
	cin.get();
}