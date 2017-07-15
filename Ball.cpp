#include "stdafx.h"
#include "Ball.h"


CBall::CBall(Vector2i center, int radius)
	:CGameObject(RECT{ center.x - radius , center.y - radius ,center.x + radius,center.y + radius })
{
	m_center = center;
	m_radius = radius;

	m_movingDir = { 0, 5 };
}


CBall::~CBall()
{
}

void CBall::Update(float deltaTime)
{
	Move(m_movingDir);
}

void CBall::Draw(HDC hdc)
{
	Ellipse(hdc, m_position.left, m_position.top, m_position.right, m_position.bottom);
}

CollisionBounary CBall::getCollisionBoundary(void ** addr)
{
	return CollisionBounary();
}
