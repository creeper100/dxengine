#include "stdafx.h"
#include "Player.h"


Player::Player(LPDIRECT3DDEVICE9 pDirect3Device)
{
	init(pDirect3Device);
}
Player::Player() {}
void Player::init(LPDIRECT3DDEVICE9 pDirect3Device){
	pDD = pDirect3Device;
	x = y = z = 0;
	tgor = tvert = 0;
	cam.init(0.0f, 0.0f, -1.5f, 0.0f, 0.0f, -0.5f, pDirect3Device);
}
Player::~Player()
{
}
void Player::forward(double val) {
	move(val, 0.0f, 0.0f);
}
void Player::left(double val) {
	move(0.0f, 0.0f, -val);
}
void Player::right(double val) {
	move(0.0f, 0.0f, val);
}
void Player::backward(double val) {
	move(-val, 0.0f, 0.0f);
}

void Player::move(double xm, double ym , double zm) {
	x += xm;
	y += ym;
	z += zm;
	cam.move(x, y, z);
	cam.Lookmove(xm, ym, zm);
}
void Player::rotate(double rx, double ry) {
	tgor += rx;
	//if (tgor >= 360)
		//tgor = 0;
	cam.LookDeg(tgor, ry);
}

