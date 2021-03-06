#pragma once
#include "GameWindowClass.h"
#include <vector>
#include "FileObject.h"
#include "Input.h"
#include "Player.h"
class DxGameClass :
	public GameWindowClass
{
private:
LPDIRECT3D9 pDirect3D;
LPDIRECT3DDEVICE9  pDirect3Device;
std::vector<FileObject> modelFiles;
int files = 0;
public:
	Player pla;
	void Init(HINSTANCE hInstan, int nCmdShow);
	HRESULT InitalDirect3D(HWND hwnd);
	LPDIRECT3DDEVICE9 getDevice() {
		return pDirect3Device;
	}
	void render();
	HRESULT loadFile(LPCWSTR loadstr);

};

