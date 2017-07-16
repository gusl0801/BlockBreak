#pragma once
#include "GameObject.h"

class CObstacle :
	public CGameObject
{
private:
	CBoundingBox m_boundingBox;

public:
	CObstacle();
	~CObstacle();

public:
	virtual void Update(float deltaTime) override;
	virtual void Draw(HDC hdc) override;

	virtual CollisionBounary getCollisionBoundary(void **addr) override;
};

