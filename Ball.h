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

	virtual bool CheckCollision(const CBoundingBox &that) override { return m_boundingCircle.isCollide(that); }
	virtual bool CheckCollision(const CBoundingCircle &that) override { return m_boundingCircle.isCollide(that); }
	virtual bool CheckCollision(const CBoundingPlane &that) override { return m_boundingCircle.isCollide(that); }

	virtual CollisionBounary getCollisionBoundary(void **addr) override;
};

