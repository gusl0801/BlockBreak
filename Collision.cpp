#include "stdafx.h"
#include "Collision.h"

CBoundingBox::CBoundingBox(Rect box)
	:m_box(box)
{
}

CBoundingBox::CBoundingBox(Vector2d center, double radius)
{
	m_box.left = center.x - radius;
	m_box.right = center.x + radius;
	m_box.top = center.y - radius;
	m_box.bottom = center.y + radius;
}


CBoundingBox::~CBoundingBox()
{
}


void CBoundingBox::Extend(CBoundingBox &that, double radius)
{
	that.m_box.left -= radius;
	that.m_box.top -= radius;
	that.m_box.bottom += radius;
	that.m_box.right += radius;
}

void CBoundingBox::Transform(Rect box)
{
	m_box = box;
}

bool CBoundingBox::isCollide(const CBoundingBox & that) const
{
	if (m_box.left >= that.m_box.right) return false;
	if (m_box.right <= that.m_box.left) return false;
	if (m_box.top >= that.m_box.bottom) return false;
	if (m_box.bottom <= that.m_box.top) return false;
	
	std::cout << "Ãæµ¹" << std::endl;
	return true;
}

bool CBoundingBox::isCollide(const CBoundingCircle & that) const
{
	return that.isCollide(*this);
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
	CBoundingBox extendedBox = that.getBox();

	CBoundingBox::Extend(extendedBox, m_radius * 0.5f);

	CBoundingBox a(m_center, m_radius);
	return extendedBox.isCollide(a);
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
