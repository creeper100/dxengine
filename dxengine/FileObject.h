#pragma once
class FileObject
{
private:
	LPD3DXMESH pMesh = NULL;
	LPD3DXBUFFER pMeshBuffer = NULL;
	D3DMATERIAL9* pMeshMaterial = NULL;
	LPDIRECT3DTEXTURE9* pMeshTextura = NULL;
	DWORD dwNumber;
public:

	FileObject();
	HRESULT Load(LPDIRECT3DDEVICE9 pDirect3Device, LPCWSTR name);
	~FileObject();
};

