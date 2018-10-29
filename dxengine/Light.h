#pragma once
class Light
{
private:
	D3DLIGHT9 Lighter;
	LPDIRECT3DDEVICE9 pDD;
public:
	Light(D3DLIGHTTYPE type, float r, float g, float b, float range, D3DXVECTOR3 pos, D3DXVECTOR3 dir, LPDIRECT3DDEVICE9 pDDir);
	~Light();
};

