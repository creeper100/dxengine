#include "stdafx.h"
#include "Player.h"


Player::Player(LPDIRECT3DDEVICE9 pDirect3Device)
{
	init(pDirect3Device);
}
Player::Player() {}
void Player::init(LPDIRECT3DDEVICE9 pDirect3Device){
	pDD = pDirect3Device;
	cam.init(0.0f, 0.0f, -1.5f, 0.0f, 0.0f, 1.0f, pDirect3Device);
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
	cam.Lookmove(sin(rx* 3.14159265 / 180) * 8.0f, cos(rx* 3.14159265 / 180) * 8.0f, 0);
}

