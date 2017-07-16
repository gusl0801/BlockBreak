#pragma once

#include "stdafx.h"

class Rect
{
public:
	double left;
	double top;
	double right;
	double bottom;

public:
	Rect() { left = top = right = bottom = double{}; }
	Rect(double left, double top, double right, double bottom)
		: left(left), top(top), right(right), bottom(bottom) {}

};