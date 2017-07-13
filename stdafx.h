// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
#include <iostream>
#include <fstream>

#include <map>
#include <unordered_map>
#include <list>
#include <string>
#include <algorithm>
#include <future>
#include <cassert>
#include <chrono>
#include <atlimage.h>

using std::map;
using std::unordered_map;
using std::list;
using std::string;
#include "Resource.h"
#include "Vector2D.h"

// DEFINE
#define CLIENT_HEIGHT 640
#define CLIENT_WIDTH 540

// TYPE DEFINE

// ������
using Degree = float;	
// ȣ����
using Radian = float;	


#ifdef _DEBUG
	#ifdef UNICODE
		#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
	#else
		#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
	#endif
#endif

inline int wrap(int data, int low, int high)
{
	assert(low < high);
	const int n = (data - low) % (high - low);
	return (n >= 0) ? (n + low) : (n + high);
}
inline int wrap(int data, int MAX)
{
	return data % MAX;
}
inline float wrap(float data, float low, int high)
{
	assert(low < high);
	const float f = std::fmod((data - low), (high - low));
	return (f >= 0) ? (f + low) : (f + high);
}
inline float wrap(float data, float MAX)
{
	return std::fmod(data, MAX);
}
inline int clamp(int data, int low, int high)
{
	return min(max(data, low), high);
}