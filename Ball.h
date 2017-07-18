#pragma once
#include "GameObject.h"
class CBall :
	public CGameObject
{
private:
	CBoundingCircle m_boundingCircle;

	Vector2d m_center;
	int m_radius;

public:
	CBall(Vector2d center, int radius);
	~CBall();

public:
	virtual void Update(float deltaTime) override;
	virtual void Draw(HDC hdc) override;

	virtual bool CheckCollision(const CBoundingBox &box) override { return m_boundingCircle.isCollide(box); }
	virtual bool CheckCollision(const CBoundingCircle &circle) override { return m_boundingCircle.isCollide(circle); }
	virtual bool CheckCollision(const CBoundingPlane &plane) override { return m_boundingCircle.isCollide(plane); }

	virtual CollisionBounary getCollisionBoundary(void **addr) override;
};

