#pragma once
#include "GameObject.h"

class CObstacle :
	public CGameObject
{
public:
	CObstacle();
	~CObstacle();

public:
	virtual void Update(float deltaTime) override;
	virtual void Draw(HDC hdc) override;

	virtual CollisionBounary getCollisionBoundary(void **addr) override;

private:
	CBoundingBox m_boundingBox;
};

