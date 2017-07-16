#include "stdafx.h"
#include "Ball.h"


CBall::CBall(Vector2d center, int radius)
	:CGameObject(Rect{ center.x - radius , center.y - radius ,center.x + radius,center.y + radius })
{
	m_center = center;
	m_radius = radius;

	// 1초에 화면 세로 길이의 절반 만큼 이동
	m_movingDir = { 0, CLIENT_HEIGHT *0.5f };
}


CBall::~CBall()
{
}

void CBall::Update(float deltaTime)
{
	Move(m_movingDir * deltaTime);
}

void CBall::Draw(HDC hdc)
{
	Ellipse(hdc, m_position.left, m_position.top, m_position.right, m_position.bottom);
}

CollisionBounary CBall::getCollisionBoundary(void ** addr)
{
	return CollisionBounary::Circle;
}
