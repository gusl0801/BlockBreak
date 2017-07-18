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
	CBoundingBox(Vector2d center, double radius);
	~CBoundingBox();

public:
	static void Extend(CBoundingBox &that, double radius);

public:
	void Transform(Rect box);

	bool isCollide(const CBoundingBox &that) const;
	bool isCollide(const CBoundingCircle &that) const;
	bool isCollide(const CBoundingPlane &that) const;
	bool isInside(const Vector2d &vector);

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

enum class PlaneType
{
	Horizon,
	Vertical
};
class CBoundingPlane
{
private:
	union
	{
		Vector2d m_arr[2];
		struct { Vector2d m_a, m_b; };
	};
	PlaneType m_type;

public:
	CBoundingPlane(Vector2d pos_a = Vector2d{}, Vector2d pos_b = Vector2d{});
	~CBoundingPlane();

	void operator=(const CBoundingPlane &other);
public:
	bool isCollide(const CBoundingBox &box) const;
	bool isCollide(const CBoundingCircle &circle) const;
	bool isCollide(const CBoundingPlane &plane) const;

public:
	Vector2d getPointA() const { return m_a; }
	Vector2d getPointB() const { return m_b; }
};

