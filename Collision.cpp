#include "stdafx.h"
#include "Collision.h"


CBoundingBox::CBoundingBox(RECT box)
	:m_box(box)
{
}


CBoundingBox::~CBoundingBox()
{
}

bool CBoundingBox::isCollide(const CBoundingBox & that) const
{
	return false;
}

bool CBoundingBox::isCollide(const CBoundingCircle & that) const
{
	return false;
}

bool CBoundingBox::isCollide(const CBoundingPlane & that) const
{
	return false;
}


CBoundingCircle::CBoundingCircle(Vector2i center, float radius)
	:m_center(center), m_radius(radius)
{
}


CBoundingCircle::~CBoundingCircle()
{
}

bool CBoundingCircle::isCollide(const CBoundingBox & that) const
{
	return false;
}

bool CBoundingCircle::isCollide(const CBoundingCircle & that) const
{
	return false;
}

bool CBoundingCircle::isCollide(const CBoundingPlane & that) const
{
	return false;
}


CBoundingPlane::CBoundingPlane(Vector2i pos_a, Vector2i pos_b)
{
}


CBoundingPlane::~CBoundingPlane()
{
}

bool CBoundingPlane::isCollide(const CBoundingBox & that) const
{
	return false;
}

bool CBoundingPlane::isCollide(const CBoundingCircle & that) const
{
	return false;
}

bool CBoundingPlane::isCollide(const CBoundingPlane & that) const
{
	return false;
}
