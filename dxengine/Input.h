#pragma once
class Input
{
private:
	LPDIRECTINPUT8 pInput;
	LPDIRECTINPUTDEVICE8 pInputDevice;
	LPDIRECT3DDEVICE9 pDD;
public:
	Input();
	~Input();
	HRESULT InitialInput(HINSTANCE hinstanceMain,HWND hWnd, LPDIRECT3DDEVICE9 pDirect3DDevice);
	void readinput();
	bool isinital() { return !pInputDevice == NULL ||pDD==NULL; }
};

