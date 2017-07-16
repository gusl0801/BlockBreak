#pragma once
#include "GameObject.h"
class CBall :
	public CGameObject
{
private:
	CBoundingCircle m_boundingBox;

	Vector2d m_center;
	int m_radius;

public:
	CBall(Vector2d center, int radius);
	~CBall();

public:
	virtual void Update(float deltaTime) override;
	virtual void Draw(HDC hdc) override;

	virtual CollisionBounary getCollisionBoundary(void **addr) override;
};

