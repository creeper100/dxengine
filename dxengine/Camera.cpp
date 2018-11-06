#include "stdafx.h"
#include "Camera.h"


void Camera::init(double x, double y, double z, double lox, double loy, double loz, LPDIRECT3DDEVICE9 pDev)
{
	cx = x;
	cy = y;
	cz = z;
	lx = lox;
	ly = loy;
	lz = loz;
	pDD = pDev;
	D3DXMatrixLookAtLH(&MatrixView, &D3DXVECTOR3(cx, cy, cz), &D3DXVECTOR3(lx, ly, lz), &D3DXVECTOR3(0.0f, 1.0f, 0.0));
	pDD->SetTransform(D3DTS_VIEW, &MatrixView);
}
Camera::Camera() {};
Camera::Camera(double x, double y, double z, double lox, double loy, double loz, LPDIRECT3DDEVICE9 pDev){
	init(x, y, z, lox, loy, loz, pDev);
}
Camera::~Camera()
{
}
void Camera::LookAt(double x, double y, double z) {
	lx = x;
	ly = y;
	lz = z;
	//D3DXMatrixLookAtLH(&MatrixView, &D3DXVECTOR3(0.0f, 0.0f, -8.0), &D3DXVECTOR3(0.0f, 0.0f, 0.0), &D3DXVECTOR3(0.0f, 1.0f, 0.0));
	D3DXMatrixLookAtLH(&MatrixView, &D3DXVECTOR3(cx, cy, cz), &D3DXVECTOR3(x, y, z), &D3DXVECTOR3(0.0f, 1.0f, 0.0));
	pDD->SetTransform(D3DTS_VIEW, &MatrixView);
}
void Camera::Lookmove(double x, double y, double z) {
	lx += x;
	ly += y;
	lz += z;
	//D3DXMatrixLookAtLH(&MatrixView, &D3DXVECTOR3(0.0f, 0.0f, -8.0), &D3DXVECTOR3(0.0f, 0.0f, 0.0), &D3DXVECTOR3(0.0f, 1.0f, 0.0));
	D3DXMatrixLookAtLH(&MatrixView, &D3DXVECTOR3(cx, cy, cz), &D3DXVECTOR3(lx, ly, lz), &D3DXVECTOR3(0.0f, 1.0f, 0.0));
	pDD->SetTransform(D3DTS_VIEW, &MatrixView);
}
void Camera::move(double x, double y, double z) {
	cx = x;
	cy = y;
	cz = z;
	D3DXMatrixLookAtLH(&MatrixView, &D3DXVECTOR3(x, y, z), &D3DXVECTOR3 (lx, ly, lz), &D3DXVECTOR3(0.0f, 1.0f, 0.0));
	pDD->SetTransform(D3DTS_VIEW, &MatrixView);
}