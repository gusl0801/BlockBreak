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
	double m_friction;		// ����
	double m_velocity;		// �ӷ�

public:
	CBoard(Rect position);
	~CBoard();

public:
	virtual void Update(float deltaTime) override;
	virtual void Draw(HDC hdc) override;

	virtual CollisionBounary getCollisionBoundary(void **addr) override;
};

