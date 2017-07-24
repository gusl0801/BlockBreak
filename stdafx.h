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
#include <array>
#include <string>
#include <algorithm>
#include <functional>
#include <future>
#include <cassert>
#include <chrono>
#include <atlimage.h>

using std::map;
using std::unordered_map;
using std::list;
using std::string;
using std::array;
#include "Resource.h"
#include "Vector2D.h"
#include "Rect.h"

// DEFINE
#define CLIENT_HEIGHT 640
#define CLIENT_WIDTH 540

#define DIR_LEFT 0x01
#define DIR_RIGHT 0x02


enum class WindingOrder
{
	CCW = 0,
	CW
};
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

inline double distance(const Vector2d &a, const Vector2d &b)
{
	return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}
#define PI 3.141592
inline double DegreeToRadian(double angle)
{
	//180 degree = PI radian;
	//1 degree = PI / 180  radian;
	//x degree = x * PI / 180 radian
	return angle * PI / 180;
}
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
inline double clamp(double data, double low, double high)
{
	return min(max(data, low), high);
}

inline bool isZero(double data)
{
	return std::fabs(data) < std::numeric_limits<double>::epsilon();
}