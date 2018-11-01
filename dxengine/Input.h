#pragma once
class Input
{
	LPDIRECTINPUT8 pInput;
	LPDIRECTINPUTDEVICE8 pInputDevice;
public:
	Input();
	~Input();
	HRESULT InitialInput(HINSTANCE hinstanceMain,HWND hWnd, LPDIRECT3DDEVICE9 pDirect3DDevice);
};

