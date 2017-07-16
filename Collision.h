#pragma once

enum class CollisionBounary
{
	None,
	Box,
	Circle,
	Plane
};
class CBoundingCircle;
class CBoundingPlane;

class CBoundingBox
{
private:
	RECT m_box;

public:
	CBoundingBox(RECT box = RECT{});
	~CBoundingBox();

public:
	bool isCollide(const CBoundingBox &that) const;
	bool isCollide(const CBoundingCircle &that) const;
	bool isCollide(const CBoundingPlane &that) const;

	RECT getBox() const { return m_box; }
};

class CBoundingCircle
{
private:
	Vector2i m_center;
	float m_radius;

public:
	CBoundingCircle(Vector2i center = Vector2i{}, float radius = 0.0f);
	~CBoundingCircle();

public:
	bool isCollide(const CBoundingBox &that) const;
	bool isCollide(const CBoundingCircle &that) const;
	bool isCollide(const CBoundingPlane &that) const;

public:
	Vector2i getCenter() const { return m_center; }
	float getRadius() const { return m_radius; }
};

class CBoundingPlane
{
private:
	union
	{
		Vector2i m_arr[2];
		struct { Vector2i m_a, m_b; };
	};

public:
	CBoundingPlane(Vector2i pos_a = Vector2i{}, Vector2i pos_b = Vector2i{});
	~CBoundingPlane();

public:
	bool isCollide(const CBoundingBox &that) const;
	bool isCollide(const CBoundingCircle &that) const;
	bool isCollide(const CBoundingPlane &that) const;

public:
	Vector2i getPointA() const { return m_a; }
	Vector2i getPointB() const { return m_b; }
};

