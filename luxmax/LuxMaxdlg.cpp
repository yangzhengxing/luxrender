/***************************************************************************
* Copyright 1998-2015 by authors (see AUTHORS.txt)                        *
*                                                                         *
*   This file is part of LuxRender.                                       *
*                                                                         *
* Licensed under the Apache License, Version 2.0 (the "License");         *
* you may not use this file except in compliance with the License.        *
* You may obtain a copy of the License at                                 *
*                                                                         *
*     http://www.apache.org/licenses/LICENSE-2.0                          *
*                                                                         *
* Unless required by applicable law or agreed to in writing, software     *
* distributed under the License is distributed on an "AS IS" BASIS,       *
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.*
* See the License for the specific language governing permissions and     *
* limitations under the License.                                          *
***************************************************************************/

#include "LuxMaxpch.h"
#include "resource.h"
#include "LuxMax.h"
#include <maxscript\maxscript.h>
#include "3dsmaxport.h"
#include <sstream>
#include <string>

extern HINSTANCE hInstance;
static INT_PTR CALLBACK LuxMaxParamDlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

class LuxMaxParamDlg : public RendParamDlg {
public:
	LuxMax *rend;
	IRendParams *ir;
	HWND hPanel;
	//HWND hDlg;
	BOOL prog;
	HFONT hFont;
	ISpinnerControl* depthSpinner;
	TSTR workFileName;
	//int workRenderType;
	int halttime;
	TSTR halttimewstr = L"30";
	float LensRadius;
	TSTR LensRadiusstr = L"0";
	int  rendertype;
	TSTR vbinterval = L"1";
	bool defaultlightchk = true;
	bool defaultlightauto = true;

	LuxMaxParamDlg(LuxMax *r, IRendParams *i, BOOL prog);
	~LuxMaxParamDlg();
	void AcceptParams();
	void DeleteThis() { delete this; }
	void InitParamDialog(HWND hWnd);
	void InitProgDialog(HWND hWnd);
	void ReleaseControls() {}
	BOOL FileBrowse();

	INT_PTR WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
};

LuxMaxParamDlg::~LuxMaxParamDlg()
{
	DeleteObject(hFont);
	ir->DeleteRollupPage(hPanel);
}

INT_PTR LuxMaxParamDlg::WndProc(
	HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(wParam);
	LuxMaxParamDlg *dlg = DLGetWindowLongPtr<LuxMaxParamDlg*>(hWnd);

	switch (msg) {
	case WM_INITDIALOG:
		dlg = (LuxMaxParamDlg*)lParam;
		DLSetWindowLongPtr(hWnd, lParam);
		if (dlg)
		{
			if (dlg->prog)
				dlg->InitProgDialog(hWnd);
			else
				dlg->InitParamDialog(hWnd);
		}
		break;

	case WM_DESTROY:
		if (!dlg->prog)
		{
			//ReleaseISpinner(dlg->depthSpinner);
			ReleaseControls();
		}
		break;

	default:
		return FALSE;
	}
	return TRUE;
}



static INT_PTR CALLBACK LuxMaxParamDlgProc(
	HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	//LuxMaxParamDlg *info = DLGetWindowLongPtr<LuxMaxParamDlg*>(hWnd);

	DisableAccelerators();
	LuxMaxParamDlg *dlg = DLGetWindowLongPtr<LuxMaxParamDlg*>(hWnd);
	switch (msg) 
	{
	case WM_INITDIALOG:
	{
		dlg = (LuxMaxParamDlg*)lParam;
		DLSetWindowLongPtr(hWnd, lParam);
		
		SendDlgItemMessage(hWnd, IDC_RENDERTYPE, CB_ADDSTRING, 0, (LPARAM)L"BIASPATHCPU");
		SendDlgItemMessage(hWnd, IDC_RENDERTYPE, CB_ADDSTRING, 0, (LPARAM)L"BIASPATHOCL");
		SendDlgItemMessage(hWnd, IDC_RENDERTYPE, CB_ADDSTRING, 0, (LPARAM)L"BIDIRCPU");
		//SendDlgItemMessage(hWnd, IDC_RENDERTYPE, CB_ADDSTRING, 0, (LPARAM)L"BIDIRHYBRID");
		SendDlgItemMessage(hWnd, IDC_RENDERTYPE, CB_ADDSTRING, 0, (LPARAM)L"BIDIRVMCPU");
		//SendDlgItemMessage(hWnd, IDC_RENDERTYPE, CB_ADDSTRING, 0, (LPARAM)L"CBIDIRHYBRID");
		//SendDlgItemMessage(hWnd, IDC_RENDERTYPE, CB_ADDSTRING, 0, (LPARAM)L"LIGHTCPU");
		SendDlgItemMessage(hWnd, IDC_RENDERTYPE, CB_ADDSTRING, 0, (LPARAM)L"PATHCPU");
		//SendDlgItemMessage(hWnd, IDC_RENDERTYPE, CB_ADDSTRING, 0, (LPARAM)L"PATHHYBRID");
		SendDlgItemMessage(hWnd, IDC_RENDERTYPE, CB_ADDSTRING, 0, (LPARAM)L"PATHOCL");
		//SendDlgItemMessage(hWnd, IDC_RENDERTYPE, CB_ADDSTRING, 0, (LPARAM)L"PATHOCLBASE");
		SendDlgItemMessage(hWnd, IDC_RENDERTYPE, CB_ADDSTRING, 0, (LPARAM)L"RTBIASPATHOCL");
		SendDlgItemMessage(hWnd, IDC_RENDERTYPE, CB_ADDSTRING, 0, (LPARAM)L"RTPATHOCL");
		SendDlgItemMessage(hWnd, IDC_RENDERTYPE, CB_SELECTSTRING, 0, (LPARAM)L"PATHCPU");
		//SendDlgItemMessage(hWnd, IDC_RENDERTYPE, CB_SETCURSEL, 0, (LPARAM)L"PATHCPU");
		//store value back into workRenderType = rend->renderType
		SendDlgItemMessage(hWnd, IDC_COMBO2, CB_ADDSTRING, 0, (LPARAM)L"Random");
		SendDlgItemMessage(hWnd, IDC_COMBO2, CB_ADDSTRING, 0, (LPARAM)L"Sobol");
		SendDlgItemMessage(hWnd, IDC_COMBO2, CB_ADDSTRING, 0, (LPARAM)L"Metropolis");
		SendDlgItemMessage(hWnd, IDC_COMBO2, CB_SELECTSTRING, 0, (LPARAM)L"Sobol");

		SendDlgItemMessage(hWnd, IDC_FILTERS_TYPE_COMBO, CB_ADDSTRING, 0, (LPARAM)L"Blackman Harris");
		SendDlgItemMessage(hWnd, IDC_FILTERS_TYPE_COMBO, CB_ADDSTRING, 0, (LPARAM)L"Catmall rom");
		SendDlgItemMessage(hWnd, IDC_FILTERS_TYPE_COMBO, CB_ADDSTRING, 0, (LPARAM)L"Triangle");
		SendDlgItemMessage(hWnd, IDC_FILTERS_TYPE_COMBO, CB_ADDSTRING, 0, (LPARAM)L"Sinc");
		SendDlgItemMessage(hWnd, IDC_FILTERS_TYPE_COMBO, CB_ADDSTRING, 0, (LPARAM)L"Mitchell");
		SendDlgItemMessage(hWnd, IDC_FILTERS_TYPE_COMBO, CB_ADDSTRING, 0, (LPARAM)L"Gaussian");
		SendDlgItemMessage(hWnd, IDC_FILTERS_TYPE_COMBO, CB_ADDSTRING, 0, (LPARAM)L"Box");
		SendDlgItemMessage(hWnd, IDC_FILTERS_TYPE_COMBO, CB_SELECTSTRING, 0, (LPARAM)L"Mitchell");

		SendDlgItemMessage(hWnd, IDC_COMBO_FILM_OUTPUT_TYPE, CB_ADDSTRING, 0, (LPARAM)L"RGBA_TONEMAPPED");
		SendDlgItemMessage(hWnd, IDC_COMBO_FILM_OUTPUT_TYPE, CB_ADDSTRING, 0, (LPARAM)L"RGB_TONEMAPPED");
		SendDlgItemMessage(hWnd, IDC_COMBO_FILM_OUTPUT_TYPE, CB_SELECTSTRING, 0, (LPARAM)L"RGBA_TONEMAPPED");
		
		CheckDlgButton(hWnd, IDC_CHECK_OPENCL_GPU, BST_UNCHECKED);
		CheckDlgButton(hWnd, IDC_CHECK_OPENCL_CPU, BST_CHECKED);
		//CheckDlgButton(hWnd, IDC_OUTPUTSCENE, BST_UNCHECKED);

		CheckDlgButton(hWnd, IDC_CHECK_DEFAULT_LIGHT, BST_CHECKED);
		CheckDlgButton(hWnd, IDC_CHECK_DEFUALT_LIGHT_DISABLE, BST_CHECKED);
		CheckDlgButton(hWnd, IDC_CHECK_OVERRIDE_MATTERIALS, BST_UNCHECKED);

		break;
	}
	case WM_LBUTTONDOWN:
	{}
	case WM_MOUSEMOVE:
	{}
	case WM_LBUTTONUP:
	{
			dlg->ir->RollupMouseMessage(hWnd, msg, wParam, lParam);
			break;
	}

		case WM_COMMAND:
		{
			switch (LOWORD(wParam))
			{
			case IDC_BUTTON1:
			{
				if (dlg->FileBrowse()) 
				{
					SetDlgItemText(hWnd, IDC_FILENAME, dlg->workFileName.data());
					break;
				}
				break;
			}
			case IDC_HALTTIME:
			{
				HWND hwndOutput = GetDlgItem(hWnd, IDC_HALTTIME);
				dlg->halttimewstr = GetWindowText(hwndOutput);
				break;
			}
			case IDC_CAMERA_DEPTH:
			{
				HWND hwndOutputB = GetDlgItem(hWnd, IDC_CAMERA_DEPTH);
				dlg->LensRadiusstr = GetWindowText(hwndOutputB);
				break;
			}
			case IDC_RENDERTYPE:
			{
				switch (HIWORD(wParam))
				{
					case CBN_SELCHANGE:
					{
						
						//dlg->rendertype = SendMessage((HWND)lParam, CB_GETCURSEL, 0, 0);
						HWND comboCtl = GetDlgItem(hWnd, IDC_RENDERTYPE);
						//int itemindex = ComboBox_GetCurSel(comboCtl);
						dlg->rendertype = ComboBox_GetCurSel(comboCtl);
						mprintf(_T("\n Selected renderengine index %i \n"), dlg->rendertype);
						//dlg->rendertype = ComboBox_GetItemData(comboCtl, sel);
						//sel = ComboBox_GetItemData(comboCtl, sel);
						//mprintf(_T("\n Selected renderengine sel %i \n"), sel);
						//mprintf(_T("\n Selected renderengine typr %i \n"), dlg->rendertype);
						//TSTR temp = ComboBox_GetText(comboCtl, text,MAX_PATH);
						/*switch (itemindex)
						{
							case 0:
								dlg->rendertype = "BIASPATHCPU";
								break;
							case 1:
								dlg->rendertype = "BIASPATHOCL";
								break;
							case 2:
								dlg->rendertype = "BIDIRCPU";
								break;
							case 3:
								dlg->rendertype = "BIDIRVMCPU";
								break;
							case 4:
								dlg->rendertype = "PATHCPU";
								break;
							case 5:
								dlg->rendertype = "PATHOCL";
								break;
							case 6:
								dlg->rendertype = "RTBIASPATHOCL";
								break;
							case 7:
								dlg->rendertype = "RTPATHOCL";
								break;
						}*/
						SetFocus(hWnd);
						break;
					}
				}

				//MessageBox(0, L"Set new render typr.", L"TEST", MB_OK);
				//dlg->defaultlightchk = GetCheckBox(hWnd, IDC_CHECK_DEFAULT_LIGHT)
				break;
			}
			case IDC_VBINTERVAL:
			{
				HWND hwndOutput = GetDlgItem(hWnd, IDC_VBINTERVAL);
				dlg->vbinterval = GetWindowText(hwndOutput);
				break;
			}
			case IDC_CHECK_DEFAULT_LIGHT:
			{
				dlg->defaultlightchk = (GetCheckBox(hWnd, IDC_CHECK_DEFAULT_LIGHT) != 0);
				//dlg->defaultlightchk = GetCheckBox(hWnd, IDC_CHECK_DEFAULT_LIGHT)
				break;
			}
			case IDC_CHECK_DEFUALT_LIGHT_DISABLE:
			{
				dlg->defaultlightauto = (GetCheckBox(hWnd, IDC_CHECK_DEFUALT_LIGHT_DISABLE) != 0);
				//dlg->defaultlightauto = GetCheckBox(hWnd, IDC_CHECK_DEFUALT_LIGHT_DISABLE)
				break;
			}
			//case IDC_ANGLE_SPINNER: // A specific spinner ID.
				//angle = ((ISpinnerControl *)lParam)->GetFVal();
				//break;
		}

		}
		
		case CC_SPINNER_CHANGE:
		{
		}
		break;
	}
	if (dlg) return dlg->WndProc(hWnd, msg, wParam, lParam);
	else return FALSE;
}

LuxMaxParamDlg::LuxMaxParamDlg(
	LuxMax *r, IRendParams *i, BOOL prog)
{
	hFont = hFont = CreateFont(14, 0, 0, 0, FW_BOLD, 0, 0, 0, 0, 0, 0, 0, VARIABLE_PITCH | FF_SWISS, _T(""));
	rend = r;
	ir = i;
	this->prog = prog;
	if (prog) {
		hPanel = ir->AddRollupPage(
			hInstance,
			MAKEINTRESOURCE(IDD_RENDER_PROG),
			LuxMaxParamDlgProc,
			GetString(IDS_VRENDTITLE),
			(LPARAM)this);
	}
	else {
		hPanel = ir->AddRollupPage(
			hInstance,
			MAKEINTRESOURCE(IDD_RENDER_PARAMS),
			LuxMaxParamDlgProc,
			GetString(IDS_VRENDTITLE),
			(LPARAM)this);
		hPanel = ir->AddRollupPage(
			hInstance,
			MAKEINTRESOURCE(IDD_RENDER_SAMPLER),
			LuxMaxParamDlgProc,
			GetString(IDS_SAMPLER),
			(LPARAM)this);
		hPanel = ir->AddRollupPage(
			hInstance,
			MAKEINTRESOURCE(IDD_RENDER_FILTER),
			LuxMaxParamDlgProc,
			GetString(IDS_FILTERS),
			(LPARAM)this);
		hPanel = ir->AddRollupPage(
			hInstance,
			MAKEINTRESOURCE(IDD_DEPTH),
			LuxMaxParamDlgProc,
			GetString(IDS_DEPTH),
			(LPARAM)this);
	}
}

void LuxMaxParamDlg::InitParamDialog(HWND hWnd) {
	workFileName = rend->FileName;
	halttimewstr = rend->halttimewstr;
	LensRadiusstr = rend->LensRadiusstr;
	rendertype = rend->renderType;
	defaultlightchk = rend->defaultlightchk;
	defaultlightauto = rend->defaultlightauto;
	vbinterval = rend->vbinterval;

	// Setup the spinner controls for raytrace depth
	depthSpinner = GetISpinner(GetDlgItem(hWnd, IDC_LENSRADIUS_SPIN));
	//depthSpinner->LinkToEdit(GetDlgItem(hWnd,IDC_LENSRADIUS),EDITTYPE_FLOAT);
	//depthSpinner2->SetLimits(0.0f, 10.0f, false);


	//depthSpinner = GetISpinner(GetDlgItem(hWnd, IDC_LENSRADIUS_SPIN));
	//depthSpinner->LinkToEdit(GetDlgItem(hWnd, IDC_LENSRADIUS), EDITTYPE_INT);
	//depthSpinner->SetLimits(0, 25, TRUE);
	//depthSpinner->SetValue(rend->LxRenderParams.lenser, FALSE);

	SetDlgItemText(hWnd, IDC_FILENAME, workFileName);

	HWND hwndOutput = GetDlgItem(hWnd, IDC_HALTTIME);
	SetWindowText(hwndOutput, rend->halttimewstr);

	HWND hwndOutputB = GetDlgItem(hWnd, IDC_CAMERA_DEPTH);
	SetWindowText(hwndOutputB, rend->LensRadiusstr);
}

void LuxMaxParamDlg::InitProgDialog(HWND hWnd) {
	SetDlgItemText(hWnd, IDC_FILENAME, rend->FileName.data());

	HWND hwndOutput = GetDlgItem(hWnd, IDC_HALTTIME);
	SetWindowText(hwndOutput, rend->halttimewstr.data());

	HWND hwndOutputB = GetDlgItem(hWnd, IDC_CAMERA_DEPTH);
	SetWindowText(hwndOutputB, rend->LensRadiusstr.data());
}

void LuxMaxParamDlg::AcceptParams() {
	rend->FileName = workFileName;
	rend->renderType = rendertype;
	rend->halttimewstr = halttimewstr;
	rend->LensRadiusstr = LensRadiusstr;
	rend->vbinterval = vbinterval;
	rend->defaultlightchk = defaultlightchk;
	rend->defaultlightauto = defaultlightauto;
}

RendParamDlg * LuxMax::CreateParamDialog(IRendParams *ir, BOOL prog) {
	return new LuxMaxParamDlg(this, ir, prog);
}

// File Browse ------------------------------------------------------------
BOOL FileExists(const TCHAR *filename) {
	HANDLE findhandle;
	WIN32_FIND_DATA file;
	findhandle = FindFirstFile(filename, &file);
	FindClose(findhandle);
	if (findhandle == INVALID_HANDLE_VALUE)
		return(FALSE);
	else
		return(TRUE);
}

BOOL RunningNewShell()
{
	OSVERSIONINFO os;
	os.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx(&os);
	if (os.dwPlatformId == VER_PLATFORM_WIN32_NT && os.dwMajorVersion < 4)
		return FALSE;
	return TRUE;
}

#define FileEXT _T(".png")
#define FileFILTER _T("*.png")

void FixFileExt(OPENFILENAME &ofn, TCHAR* ext = FileEXT) {
	int l = static_cast<int>(_tcslen(ofn.lpstrFile));  // SR DCAST64: Downcast to 2G limit.
	int e = static_cast<int>(_tcslen(ext));   // SR DCAST64: Downcast to 2G limit.
	if (_tcsicmp(ofn.lpstrFile + l - e, ext)) {
		_tcscat(ofn.lpstrFile, ext);
	}
}

#if 0
UINT_PTR WINAPI FileHook( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_INITDIALOG:
		SetDlgItemText(hDlg, IDOK, _T("OK"));
		break;
	case WM_COMMAND:{
	}

		break;
	}
	return FALSE;
}

UINT_PTR PMFileHook(HWND hWnd,UINT message,WPARAM wParam,LPARAM   lParam)
{
	switch (message) {
	case WM_INITDIALOG:
		SetDlgItemText(hWnd, IDOK, _T("OK"));
		break;
	case WM_COMMAND:{
	}

		break;
	}
	return 0;
}
#endif

BOOL LuxMaxParamDlg::FileBrowse() {
	FilterList filterList;
	HWND hWnd = hPanel;
	static int filterIndex = 1;
	OPENFILENAME  ofn;
	
	TSTR filename;
	TCHAR fname[512];
	TCHAR saveDir[1024];
	{
		TSTR dir;
		SplitFilename(workFileName, &dir, &filename, NULL);
		_tcscpy(saveDir, dir.data());
	}
	_tcscpy(fname, filename.data());
	_tcscat(fname, FileEXT);

	filterList.Append(GetString(IDS_FILE));
	memset(&ofn, 0, sizeof(ofn));

	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = hWnd;
	ofn.hInstance = hInstance;

	ofn.nFilterIndex = filterIndex;
	ofn.lpstrFilter = filterList;

	ofn.lpstrTitle = GetString(IDS_WRITE_FILE);
	ofn.lpstrFile = fname;
	ofn.nMaxFile = _countof(fname);

	Interface *iface = GetCOREInterface();

	if (saveDir[0])
		ofn.lpstrInitialDir = saveDir;
	else
		ofn.lpstrInitialDir = iface->GetDir(APP_SCENE_DIR);

	if (RunningNewShell()) {
		ofn.Flags = OFN_HIDEREADONLY | OFN_EXPLORER | OFN_ENABLEHOOK | OFN_ENABLESIZING;
		ofn.lpfnHook = NULL;
		ofn.lCustData = 0;   // 0 for save, 1 for open

	}
	else {
		ofn.Flags = OFN_HIDEREADONLY | OFN_PATHMUSTEXIST | OFN_EXPLORER | OFN_ENABLEHOOK | OFN_ENABLESIZING;
		ofn.lpfnHook = NULL; 
		ofn.lCustData = 0;
	}

	FixFileExt(ofn, FileEXT);
	while (GetSaveFileName(&ofn))    {
	//while ((&ofn)){
	FixFileExt(ofn, FileEXT); // add ".vue" if absent

		workFileName = ofn.lpstrFile;
		return TRUE;
	}
	return FALSE;
}