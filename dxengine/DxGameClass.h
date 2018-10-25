#pragma once
#include "GameWindowClass.h"
class DxGameClass :
	public GameWindowClass
{
private:
LPDIRECT3D9 pDirect3D;
LPDIRECT3DDEVICE9  pDirect3Device;
public:
	DxGameClass(HINSTANCE hInstan, int nCmdShow) :GameWindowClass(hInstan, nCmdShow) {
		if (FAILED(InitalDirect3D(hWnd)))
			exit(556);
	};
	HRESULT InitalDirect3D(HWND hwnd);
};

