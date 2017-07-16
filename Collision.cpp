#include "stdafx.h"
#include "Collision.h"

CBoundingBox::CBoundingBox(Rect box)
	:m_box(box)
{
}


CBoundingBox::~CBoundingBox()
{
}

void CBoundingBox::Transform(Rect box)
{
	m_box = box;
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


CBoundingCircle::CBoundingCircle(Vector2d center, float radius)
	:m_center(center), m_radius(radius)
{
}

CBoundingCircle::~CBoundingCircle()
{
}

void CBoundingCircle::Transform(Vector2d center)
{
	m_center = center;
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


CBoundingPlane::CBoundingPlane(Vector2d pos_a, Vector2d pos_b)
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
