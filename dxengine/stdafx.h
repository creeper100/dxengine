// stdafx.h: включаемый файл для стандартных системных включаемых файлов
// или включаемых файлов для конкретного проекта, которые часто используются, но
// нечасто изменяются
//

#pragma once
#define INITGUID
#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Исключите редко используемые компоненты из заголовков Windows
// Файлы заголовков Windows
#include <windows.h>

// Файлы заголовков среды выполнения C
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#pragma comment(lib,"d3d9.lib")
//#pragma comment(lib,"dinput.lib")
#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"dxguid.lib")
#pragma comment(lib,"d3dx9.lib")
#include "d3d9.h"
#include <d3dx9.h>
#include <cmath>
#include "d3dx9core.h"
#include <d3dx9mesh.h>
#include "dinput.h"
// установите здесь ссылки на дополнительные заголовки, требующиеся для программы
