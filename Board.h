#pragma once
#include "GameObject.h"

//namespace DefineOfBoard
//{
//	const double MAX_SPEED = 0.0f;
//	const double MIN_SPEED = 0.0f;
//};
class CBoard :
	public CGameObject
{
private:
	CBoundingBox m_boundingBox;
	double m_friction;		// ¸¶Âû
	double m_velocity;		// ¼Ó·Â
	CImage m_image;
	Vector2d m_size;

public:
	CBoard(Rect position);
	~CBoard();

public:
	virtual void Update(float deltaTime) override;
	virtual void Draw(HDC hdc) override;

	virtual bool CheckCollision(const CBoundingBox &that) override { return m_boundingBox.isCollide(that); }
	virtual bool CheckCollision(const CBoundingCircle &that) override { return m_boundingBox.isCollide(that); }
	virtual bool CheckCollision(const CBoundingPlane &that) override { return m_boundingBox.isCollide(that); }

	virtual CollisionBounary getCollisionBoundary(void **addr) override;
};

