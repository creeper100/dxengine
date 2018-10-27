#include "stdafx.h"
#include "FileObject.h"


FileObject::FileObject(){
}


FileObject::~FileObject() {

}

HRESULT FileObject::Load(LPDIRECT3DDEVICE9 pDirect3Device,LPCWSTR name) {
	if (FAILED(D3DXLoadMeshFromX(name, D3DXMESH_SYSTEMMEM, pDirect3Device, NULL, &pMeshBuffer, NULL, &dwNumber, &pMesh)))
		return E_FAIL;
	D3DXMATERIAL* D3DXMeshMaterials = (D3DXMATERIAL *)pMeshBuffer->GetBufferPointer();
	pMeshMaterial = new D3DMATERIAL9[dwNumber];
	pMeshTextura = new LPDIRECT3DTEXTURE9[dwNumber];
	for (DWORD i = 0;i < dwNumber;i++) {
		pMeshMaterial[i] = D3DXMeshMaterials[i].MatD3D;
		pMeshMaterial[i].Ambient = pMeshMaterial[i].Diffuse;
		if (FAILED(D3DXCreateTextureFromFileA(pDirect3Device, D3DXMeshMaterials[i].pTextureFilename, &pMeshTextura[i])))
			pMeshTextura[i] = NULL;
	}
	pMeshBuffer->Release();
	return S_OK;
}
