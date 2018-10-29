#pragma once
class Camera
{
private:
	D3DXMATRIX MatrixView;
	double cx, cy, cz;
	LPDIRECT3DDEVICE9 pDD;
public:
	Camera(double x, double y, double z, LPDIRECT3DDEVICE9 pDev);
	void LookAt(double x, double y, double z);
	~Camera();
};

