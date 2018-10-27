#pragma once
#include "GameWindowClass.h"
#include <vector>
#include "FileObject.h"
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
		FileObject model;
		if (FAILED(model.Load(pDirect3Device, L"tiger.x")))
			exit(9);
	};
	HRESULT InitalDirect3D(HWND hwnd);
	HRESULT InitalMesh();
	LPDIRECT3DDEVICE9 getDevice() {
		return pDirect3Device;
	}
};

