#pragma once
#include "GameObject.h"

class CObstacle :
	public CGameObject
{
private:
	CBoundingBox m_boundingBox;
	CImage m_image;
	Vector2d m_size;

public:
	CObstacle(Rect position);
	~CObstacle();

public:
	virtual void Update(float deltaTime) override;
	virtual void Draw(HDC hdc) override;

	virtual bool CheckCollision(const CBoundingBox &that) override { return m_boundingBox.isCollide(that); }
	virtual bool CheckCollision(const CBoundingCircle &that) override { return m_boundingBox.isCollide(that); }
	virtual bool CheckCollision(const CBoundingPlane &that) override { return m_boundingBox.isCollide(that); }

	virtual CollisionBounary getCollisionBoundary(void **addr) override;
};

