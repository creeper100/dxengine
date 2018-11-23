#pragma once
class Camera
{
private:
	double cx, cy, cz;
	double lx, ly, lz;
	LPDIRECT3DDEVICE9 pDD;
public:
	void Lookmove(double x, double y, double z);
	Camera(double x, double y, double z, double lox, double loy, double loz, LPDIRECT3DDEVICE9 pDev);
	void init(double x, double y, double z, double lox, double loy, double loz, LPDIRECT3DDEVICE9 pDev);
	Camera();
	void LookAt(double x, double y, double z);
	void move(double x, double y, double z);
	void LookDeg(double rx, double ry);
	~Camera();
};

