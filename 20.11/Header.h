#pragma once
#include <windows.h>
#include <tchar.h>
#include <time.h>
#include "resource.h"
#include <windowsX.h>

HWND hlist, hbutton, hedit;

int r = 0;
double sum = 0;
double ave = 0;
double proi = 1;

void Rand(int r)
{
	r = rand() % 10 - 10;
	if (r == 0)
	{
		r = rand() % 10 - 10;
	}
}

void Close(HWND hwnd)
{
	EndDialog(hwnd, 0);
}

BOOL InitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
	hlist = GetDlgItem(hwnd, IDC_LIST1);
	hbutton = GetDlgItem(hwnd, IDC_BUTTON1);
	hedit = GetDlgItem(hwnd, IDC_EDIT1);
	
	Rand(r);
	sum += r;
	proi *= r;
	SendMessage(hlist, LB_ADDSTRING, 0, r);
	Rand(r);
	sum += r;
	proi *= r;
	SendMessage(hlist, LB_ADDSTRING, 0, r);
	Rand(r);
	sum += r;
	proi *= r;
	SendMessage(hlist, LB_ADDSTRING, 0, r);
	Rand(r);
	sum += r;
	proi *= r;
	SendMessage(hlist, LB_ADDSTRING, 0, r);
	Rand(r);
	sum += r;
	proi *= r;
	SendMessage(hlist, LB_ADDSTRING, 0, r);
	Rand(r);
	sum += r;
	proi *= r;
	SendMessage(hlist, LB_ADDSTRING, 0, r);
	Rand(r);
	sum += r;
	proi *= r;
	SendMessage(hlist, LB_ADDSTRING, 0, r);
	Rand(r);
	sum += r;
	proi *= r;
	SendMessage(hlist, LB_ADDSTRING, 0, r);
	Rand(r);
	sum += r;
	proi *= r;
	SendMessage(hlist, LB_ADDSTRING, 0, r);
	Rand(r);
	sum += r;
	proi *= r;
	SendMessage(hlist, LB_ADDSTRING, 0, r);
	ave = sum / 10;

	return TRUE;
}

void Command(HWND hwnd, UINT message, HWND hwndCtl, UINT codeNotify)
{
	switch (message)
	{
	case IDC_BUTTON1:
	{
		TCHAR buf[10];
		LRESULT res1 = SendDlgItemMessage(hwnd, IDC_RADIO1, BM_GETCHECK, 0, 0);
		LRESULT res2 = SendDlgItemMessage(hwnd, IDC_RADIO2, BM_GETCHECK, 0, 0);
		LRESULT res3 = SendDlgItemMessage(hwnd, IDC_RADIO3, BM_GETCHECK, 0, 0);
		if (res1 == BST_CHECKED)
		{
			wsprintf(buf, TEXT("%d"), sum);
			SetWindowText(hedit, buf);
		}
		if (res2 == BST_CHECKED)
		{
			wsprintf(buf, TEXT("%d"), proi);
			SetWindowText(hedit, buf);
		}
		if (res3 == BST_CHECKED)
		{
			wsprintf(buf, TEXT("%d"), ave);
			SetWindowText(hedit, buf);
		}
	}
	break;
	}
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		HANDLE_MSG(hwnd, WM_CLOSE, Close);
		HANDLE_MSG(hwnd, WM_INITDIALOG, InitDialog);
		HANDLE_MSG(hwnd, WM_COMMAND, Command);
	}
	return FALSE;
}