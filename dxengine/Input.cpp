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
	pDD = pDirect3DDevice; // Буфер
	// Создание основного объекта 
	if (FAILED(DirectInput8Create(hinstanceMain, DIRECTINPUT_VERSION,
		IID_IDirectInput8, (void**)&pInput, NULL)))
		return E_FAIL;
	// Создание устройства клавиатуры

	if (FAILED(pInput->CreateDevice(GUID_SysKeyboard, &pInputDevice, NULL)))
	return E_FAIL;
	// Установка формата данных клавиатуры
	if (FAILED(pInputDevice->SetDataFormat(&c_dfDIKeyboard)))
		return E_FAIL;

	// Установка уровня взаимодействия клавиатуры
	if (FAILED(pInputDevice->SetCooperativeLevel(hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE)))
		return E_FAIL;
	
	// Захват доступа к клавиатуре
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
	// Обработка клавиши < LEFT >
	// Изменяем окружающие освещенние на зеленный цвет
	if (KEYDOWN(keyboard, DIK_LEFT))
	{
		mwnd.pla.left(0.1);
	}
	// Обработка клавиши < RIGHT >
	// Возвращаем в исходное состояние
	if (KEYDOWN(keyboard, DIK_RIGHT))
	{
		mwnd.pla.right(0.1);
	}
	// Обработка клавиши < Up >
	// Изменяем окружающие освещенние на синий цвет
	if (KEYDOWN(keyboard, DIK_UP))
	{
		mwnd.pla.forward(0.1);
	}
	// Обработка клавиши < Down >
	// Изменяем окружающие освещенние на красный цвет
	if (KEYDOWN(keyboard, DIK_DOWN))
	{
		mwnd.pla.backward(0.1);
	}
}
