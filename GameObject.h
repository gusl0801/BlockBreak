#pragma once
#include "Collision.h"

class CGameObject
{
protected:
	RECT m_position;

public:
	CGameObject(Vector2i position = {}, Vector2i size = {});
	CGameObject(RECT position);
	virtual ~CGameObject();

public:
	virtual void Update(float deltaTime) = 0;
	virtual void Draw(HDC hdc) = 0;

	void CheckCollision(const CBoundingBox &that) {};
	void CheckCollision(const CBoundingCircle &that) {};
	void CheckCollision(const CBoundingPlane &that) {};

	virtual CollisionBounary getCollisionBoundary(void **addr) = 0;

	// unnormalized vector
	void Move(Vector2i dir);

	// normalized vector
	void Move(Vector2i dir, int velocity);
};

