#include "stdafx.h"
#include "Light.h"


Light::Light(D3DLIGHTTYPE type,float r, float g, float b, float range, D3DXVECTOR3 pos, D3DXVECTOR3 dir, LPDIRECT3DDEVICE9 pDDir)
{
	pDD = pDDir;
	ZeroMemory(&Lighter, sizeof(D3DLIGHT9));
	Lighter.Type = type;
	Lighter.Diffuse.r = r;
	Lighter.Diffuse.g = g;
	Lighter.Diffuse.b = b;
	Lighter.Range = range;
	Lighter.Position = pos;
	D3DXVec3Normalize((D3DXVECTOR3*)&Lighter.Direction, &dir);
	pDD->SetLight(0, &Lighter);
	pDD->LightEnable(0, TRUE);
}


Light::~Light()
{
}
