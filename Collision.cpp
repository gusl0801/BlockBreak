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

bool CBoundingBox::isInside(const Vector2d & vector)
{
	bool hor = (m_box.left <= vector.x) && (vector.x <= m_box.right);
	bool ver = (m_box.top <= vector.y) && (vector.y <= m_box.bottom);
	return hor && ver;
}

CBoundingPlane CBoundingBox::getCollidePlane(const CBoundingCircle &circle) const
{
	Vector2d center = circle.getCenter();
	double distances[4];

	distances[0] = center.distance({ m_box.left, m_box.top }, 0);
	distances[1] = center.distance({ m_box.right, (m_box.top + m_box.bottom) * 0.5f}, 0);
	distances[2] = center.distance({ m_box.right, m_box.bottom }, 0);
	distances[3] = center.distance({ m_box.left, (m_box.top + m_box.bottom) * 0.5f }, 0);

	double distance = *std::min_element(std::begin(distances), std::end(distances));
	int index;
	for (int i = 0; i < 4; ++i) {
		if (distances[i] == distance) {
			index = i;
			break;
		}
	}
	
	Vector2d vecA, vecB;
	if (index == 0)		
	{
		vecA.x = m_box.left, vecA.y = m_box.top;
		vecB.x = m_box.right, vecB.y = m_box.top;
	}
	else if (index == 1)
	{
		vecA.x = m_box.right, vecA.y = m_box.top;
		vecB.x = m_box.right, vecB.y = m_box.bottom;
	}
	else if (index == 2)
	{
		vecA.x = m_box.right, vecA.y = m_box.bottom;
		vecB.x = m_box.left, vecB.y = m_box.bottom;
	}
	else if (index == 3)
	{
		vecA.x = m_box.left, vecA.y = m_box.bottom;
		vecB.x = m_box.left, vecB.y = m_box.top;
	}
	return CBoundingPlane(vecA, vecB);
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


CBoundingPlane::CBoundingPlane(Vector2d pos_a, Vector2d pos_b, WindingOrder order)
	:m_a(pos_a), m_b(pos_b), m_windingOrder(order)
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
	m_windingOrder = other.m_windingOrder;
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
	return length <= that.getRadius();
}

bool CBoundingPlane::isCollide(const CBoundingPlane & that) const
{
	return false;
}

Vector2d CBoundingPlane::getNormal() const
{
	double dx;
	double dy;
	
	if (m_windingOrder == WindingOrder::CW)
	{
		dx = m_b.x - m_a.x;
		dy = m_b.y - m_a.y;
	}
	else if (m_windingOrder == WindingOrder::CCW)
	{
		dx = m_a.x - m_b.x;
		dy = m_a.y - m_b.y;
	}
	
	Vector2d normal{ -dy, dx };

	normal.Normalize();
	return normal;
}
