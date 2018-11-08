#pragma once
#include "Camera.h"
class Player
{
	double x, y, z;
	Camera cam;
	LPDIRECT3DDEVICE9 pDD;

public:
	Player(LPDIRECT3DDEVICE9 pDirect3Device);
	void init(LPDIRECT3DDEVICE9 pDirect3Device);
	Player();
	~Player();
	void forward(double val);
	void left(double val);
	void right(double val);
	void backward(double val);
	void move(double x, double y, double z);
	void rotate(double rx, double ry);
};

