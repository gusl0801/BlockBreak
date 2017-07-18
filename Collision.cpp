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
	
	std::cout << "�浹" << std::endl;
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

bool CBoundingBox::isInside(const Vector2d & vector)
{
	bool hor = (m_box.left <= vector.x) && (vector.x <= m_box.right);
	bool ver = (m_box.top <= vector.y) && (vector.y <= m_box.bottom);
	return hor && ver;
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
	CBoundingBox::Extend(extendedBox, m_radius);
	return extendedBox.isInside(m_center);
}

bool CBoundingCircle::isCollide(const CBoundingCircle & that) const
{
	double length = Vector2d::Length(m_center, that.m_center);
	double radius = m_radius + that.m_radius;
	
	return (radius >= length);
}

bool CBoundingCircle::isCollide(const CBoundingPlane & that) const
{
	return that.isCollide(*this);
}


CBoundingPlane::CBoundingPlane(Vector2d pos_a, Vector2d pos_b)
	:m_a(pos_a), m_b(pos_b)
{
	if (pos_a.x == pos_b.x)
		m_type = PlaneType::Vertical;
	
	else if (pos_a.y == pos_b.y)
		m_type = PlaneType::Horizon;
}


CBoundingPlane::~CBoundingPlane()
{
}

void CBoundingPlane::operator=(const CBoundingPlane & other)
{
	m_a = other.m_a;
	m_b = other.m_b;
	m_type = other.m_type;
}

bool CBoundingPlane::isCollide(const CBoundingBox & that) const
{
	return false;
}

bool CBoundingPlane::isCollide(const CBoundingCircle & that) const
{
	Vector2d point;
	double length;

	if (m_type == PlaneType::Horizon)
	{
		point.x = that.getCenter().x;
		point.y = m_a.y;
	}
	else if (m_type == PlaneType::Vertical)
	{
		point.x = m_a.x;
		point.y = that.getCenter().y;
	}

	length = Vector2d::Length(point, that.getCenter());
	return length <= that.getRadius() * 2;
}

bool CBoundingPlane::isCollide(const CBoundingPlane & that) const
{
	return false;
}
