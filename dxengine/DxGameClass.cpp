#pragma once
#include "stdafx.h"
#include "DxGameClass.h"
HRESULT DxGameClass :: InitalDirect3D(HWND hwnd) {
	if (NULL == (pDirect3D = Direct3DCreate9(D3D_SDK_VERSION)))
		return E_FAIL;
	D3DDISPLAYMODE Display;
	if (FAILED(pDirect3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &Display)))
		return E_FAIL;
	D3DPRESENT_PARAMETERS Direct3DParametr;
	ZeroMemory(&Direct3DParametr, sizeof(Direct3DParametr));
	Direct3DParametr.Windowed = 1;
	Direct3DParametr.EnableAutoDepthStencil = true;
	Direct3DParametr.AutoDepthStencilFormat = D3DFMT_D16;
	Direct3DParametr.SwapEffect = D3DSWAPEFFECT_DISCARD;
	Direct3DParametr.BackBufferFormat = Display.Format;
	if (FAILED(pDirect3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &Direct3DParametr, &pDirect3Device)))
		return E_FAIL;
	pDirect3Device->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);
	pDirect3Device->SetRenderState(D3DRS_AMBIENT, 0xffffffff);
	return S_OK;
}