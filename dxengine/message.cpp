#pragma once
#include "stdafx.h"
#include "dxengine.h"
extern DxGameClass mwnd;
Input inp;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
		
		break;
	case WM_PAINT:
	{
		if (mwnd.getDevice() != NULL) {
			if (inp.isinital())
				inp.InitialInput(mwnd.getInst(), hWnd, mwnd.getDevice());
			inp.readinput();
			mwnd.render();
		}
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}