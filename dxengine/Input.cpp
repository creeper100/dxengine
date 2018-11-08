#include "stdafx.h"
#include "Input.h"
#include "DxGameClass.h"

#define  KEYDOWN(name,key)(name[key] &0x80)
extern DxGameClass mwnd;
Input::Input()
{
}


Input::~Input()
{
}
HRESULT  Input::InitialInput(HINSTANCE hinstanceMain,HWND hWnd ,LPDIRECT3DDEVICE9 pDirect3DDevice)
{
	pDD = pDirect3DDevice; // �����
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
	if (pInputDevice == NULL)
		exit(5);
	return S_OK;

}
void Input::readinput() {
	char keyboard[256];
	pInputDevice->GetDeviceState(sizeof(keyboard), (LPVOID)&keyboard);
	if (KEYDOWN(keyboard, DIK_ESCAPE))
		PostQuitMessage(0);
	// ��������� ������� < LEFT >
	// �������� ���������� ���������� �� �������� ����
	if (KEYDOWN(keyboard, DIK_LEFT))
	{
		mwnd.pla.left(0.1);
	}
	// ��������� ������� < RIGHT >
	// ���������� � �������� ���������
	if (KEYDOWN(keyboard, DIK_RIGHT))
	{
		mwnd.pla.right(0.1);
	}
	// ��������� ������� < Up >
	// �������� ���������� ���������� �� ����� ����
	if (KEYDOWN(keyboard, DIK_UP))
	{
		mwnd.pla.forward(0.1);
	}
	// ��������� ������� < Down >
	// �������� ���������� ���������� �� ������� ����
	if (KEYDOWN(keyboard, DIK_DOWN))
	{
		mwnd.pla.backward(0.1);
	}
}
