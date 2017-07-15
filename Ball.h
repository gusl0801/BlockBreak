#pragma once
#include "GameObject.h"
class CBall :
	public CGameObject
{
public:
	CBall(Vector2i center, int radius);
	~CBall();

public:
	virtual void Update(float deltaTime) override;
	virtual void Draw(HDC hdc) override;

	virtual CollisionBounary getCollisionBoundary(void **addr) override;

private:
	CBoundingCircle m_boundingBox;
	
	Vector2i m_center;
	int m_radius;

	Vector2i m_movingDir;
};

