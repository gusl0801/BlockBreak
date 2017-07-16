#pragma once
#include "Collision.h"

namespace DefineOfObject
{	
	// 1초에 화면 가로 길이의 1 / 3만큼 이동 가능
	const double MAX_SPEED = CLIENT_WIDTH * 0.333f;
	const double MIN_SPEED = -MAX_SPEED;
}
class CGameObject
{
protected:
	Rect m_position;

	Vector2d m_movingDir;

public:
	CGameObject(Vector2i position = {}, Vector2i size = {});
	CGameObject(Rect position);
	virtual ~CGameObject();

public:
	virtual void Update(float deltaTime) = 0;
	virtual void Draw(HDC hdc) = 0;

	void CheckCollision(const CBoundingBox &that) {};
	void CheckCollision(const CBoundingCircle &that) {};
	void CheckCollision(const CBoundingPlane &that) {};

	virtual CollisionBounary getCollisionBoundary(void **addr) = 0;

	// unnormalized vector
	void Move(const Vector2d &dir, bool nowUpdate = true);

	// normalized vector
	void Move(const Vector2d &dir, double velocity);
	
	void Move(DWORD dir, double velocity);
};

