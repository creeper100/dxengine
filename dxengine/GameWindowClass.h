#pragma once
class GameWindowClass
{
private:
	HINSTANCE hInst;
public:
	GameWindowClass(HINSTANCE hInstan, int nCmdShow);
	ATOM  MyRegisterClass(HINSTANCE hInstance);
	BOOL  InitInstance(HINSTANCE,int);
};

