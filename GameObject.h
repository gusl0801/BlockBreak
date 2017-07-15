#pragma once
#include "Collision.h"

class CGameObject
{
public:
	CGameObject();
	~CGameObject();

public:
	virtual void Update(float deltaTime) = 0;
	virtual void Draw(HDC hdc) = 0;

	void CheckCollision(const CBoundingBox &that) {};
	void CheckCollision(const CBoundingCircle &that) {};
	void CheckCollision(const CBoundingPlane &that) {};

	virtual CollisionBounary getCollisionBoundary(void **addr) = 0;
};

