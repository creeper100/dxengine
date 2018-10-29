#pragma once
#include "stdafx.h"
#include "DxGameClass.h"
#include "Camera.h"
#include "Light.h"
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
	//pDirect3Device->SetRenderState(D3DRS_AMBIENT, 0xffffffff);
	pDirect3Device->SetRenderState(D3DRS_LIGHTING, TRUE);
	pDirect3Device->SetRenderState(D3DRS_AMBIENT, 0);
	return S_OK;
}

void DxGameClass::Init(HINSTANCE hInstan, int nCmdShow) {
	init( hInstan,  nCmdShow);
	if (FAILED(InitalDirect3D(hWnd)))
		exit(556);
	if (FAILED(loadFile(L"tiger.x")))
		exit(234);
	Camera cam(0.0f, 0.0f, -1.5f, pDirect3Device);
	cam.LookAt(0, 0, 0);
	Light flash(D3DLIGHT_SPOT, 1.0f, 1.0f, 1.0f,10.0f, D3DXVECTOR3(0.0f, 0.0f, -3.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), pDirect3Device);
}
void DxGameClass::render() {
	if (pDirect3Device != NULL) {
		pDirect3Device->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
		pDirect3Device->BeginScene();
		for (int i = 0;i < files;i++) {
			modelFiles[i].draw(pDirect3Device);
		}
		pDirect3Device->EndScene();
		pDirect3Device->Present(NULL, NULL, NULL, NULL);
	}
}
HRESULT DxGameClass::loadFile(LPCWSTR loadstr) {
	FileObject lf;
	if (FAILED(lf.Load(pDirect3Device, loadstr)))
		return E_FAIL;
	modelFiles.push_back(lf);
		files++;
		return S_OK;
}