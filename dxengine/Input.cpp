#include "stdafx.h"
#include "Input.h"

#define  KEYDOWN(name,key)(name[key] &0x80)
Input::Input()
{
}


Input::~Input()
{
}
HRESULT  Input::InitialInput(HINSTANCE hinstanceMain,HWND hWnd ,LPDIRECT3DDEVICE9 pDirect3DDevice)
{
	HRESULT hr;
	char keyboard[256];  // �����
	// �������� ��������� ������� 
	if (FAILED(DirectInput8Create(hinstanceMain, DIRECTINPUT_VERSION,
		IID_IDirectInput8, (void**)&pInput, NULL)))
		return E_FAIL;
	// �������� ���������� ����������

	if (FAILED(pInput->CreateDevice(GUID_SysKeyboard, &pInputDevice, NULL)))
		return E_FAIL;
	// ��������� ������� ������ ����������
	if (FAILED(pInputDevice->SetDataFormat(&c_dfDIKeyboard)))
		return E_FAIL;

	// ��������� ������ �������������� ����������
	if (FAILED(pInputDevice->SetCooperativeLevel(hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE)))
		return E_FAIL;
	
	// ������ ������� � ����������
	if (FAILED(pInputDevice->Acquire()))
		return E_FAIL;

	// ���������� ������ � ����������
	if (FAILED(pInputDevice->GetDeviceState(sizeof(keyboard), (LPVOID)&keyboard)))
		return E_FAIL;
	
	if (KEYDOWN(keyboard, DIK_ESCAPE))
		PostQuitMessage(0);
	// ��������� ������� < LEFT >
	// �������� ���������� ���������� �� �������� ����
	if (KEYDOWN(keyboard, DIK_LEFT))
	{
		pDirect3DDevice->SetRenderState(D3DRS_AMBIENT, 0xf0ff00f);
	}
	// ��������� ������� < RIGHT >
	// ���������� � �������� ���������
	if (KEYDOWN(keyboard, DIK_RIGHT))
	{
		pDirect3DDevice->SetRenderState(D3DRS_AMBIENT, 0xffffffff);
	}
	// ��������� ������� < Up >
	// �������� ���������� ���������� �� ����� ����
	if (KEYDOWN(keyboard, DIK_UP))
	{
		pDirect3DDevice->SetRenderState(D3DRS_AMBIENT, 0x00000ff);
	}
	// ��������� ������� < Down >
	// �������� ���������� ���������� �� ������� ����
	if (KEYDOWN(keyboard, DIK_DOWN))
	{
		pDirect3DDevice->SetRenderState(D3DRS_AMBIENT, 0x00ff00ff);
	}
	return TRUE;
}
