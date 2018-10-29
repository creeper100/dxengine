#include "stdafx.h"
#include "Camera.h"


Camera::Camera(double x, double y, double z, LPDIRECT3DDEVICE9 pDev)
{
	cx = x;
	cy = y;
	cz = z;
	pDD = pDev;
	LookAt(0.0f, 0.0f, 0.0f);
}


Camera::~Camera()
{
}
void Camera::LookAt(double x, double y, double z) {
	//D3DXMatrixLookAtLH(&MatrixView, &D3DXVECTOR3(0.0f, 0.0f, -8.0), &D3DXVECTOR3(0.0f, 0.0f, 0.0), &D3DXVECTOR3(0.0f, 1.0f, 0.0));
	D3DXMatrixLookAtLH(&MatrixView, &D3DXVECTOR3(cx, cy, cz), &D3DXVECTOR3(x, y, z), &D3DXVECTOR3(0.0f, 1.0f, 0.0));
	pDD->SetTransform(D3DTS_VIEW, &MatrixView);
}
