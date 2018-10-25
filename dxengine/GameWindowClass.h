#pragma once
class GameWindowClass{
protected:
	HINSTANCE hInst;
	HWND hWnd;
public:
	GameWindowClass(HINSTANCE hInstan, int nCmdShow);
	ATOM  MyRegisterClass(HINSTANCE hInstance);
	BOOL  InitInstance(HINSTANCE,int);
};

