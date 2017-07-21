#pragma once
#include "stdafx.h"

template <typename T>
class Line2D
{
public:
	Vector2D<T> a;
	Vector2D<T> b;
};

using Line2d = Line2D<double>;