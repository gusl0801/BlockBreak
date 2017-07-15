#pragma once
#include "GameObject.h"
class CBoard :
	public CGameObject
{
public:
	CBoard(RECT position);
	~CBoard();

public:
	virtual void Update(float deltaTime) override;
	virtual void Draw(HDC hdc) override;

	virtual CollisionBounary getCollisionBoundary(void **addr) override;

private:
	CBoundingBox m_boundingBox;
};

