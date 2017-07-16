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
	Rect m_box;

public:
	CBoundingBox(Rect box = Rect{});
	~CBoundingBox();

public:
	void Transform(Rect box);

	bool isCollide(const CBoundingBox &that) const;
	bool isCollide(const CBoundingCircle &that) const;
	bool isCollide(const CBoundingPlane &that) const;

	Rect getBox() const { return m_box; }
};

class CBoundingCircle
{
private:
	Vector2d m_center;
	float m_radius;

public:
	CBoundingCircle(Vector2d center = {}, float radius = 0.0f);
	~CBoundingCircle();

public:
	void Transform(Vector2d center);

	bool isCollide(const CBoundingBox &that) const;
	bool isCollide(const CBoundingCircle &that) const;
	bool isCollide(const CBoundingPlane &that) const;

public:
	Vector2d getCenter() const { return m_center; }
	float getRadius() const { return m_radius; }
};

class CBoundingPlane
{
private:
	union
	{
		Vector2d m_arr[2];
		struct { Vector2d m_a, m_b; };
	};

public:
	CBoundingPlane(Vector2d pos_a = Vector2d{}, Vector2d pos_b = Vector2d{});
	~CBoundingPlane();

public:
	bool isCollide(const CBoundingBox &that) const;
	bool isCollide(const CBoundingCircle &that) const;
	bool isCollide(const CBoundingPlane &that) const;

public:
	Vector2d getPointA() const { return m_a; }
	Vector2d getPointB() const { return m_b; }
};

