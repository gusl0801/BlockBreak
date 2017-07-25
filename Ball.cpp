#include "stdafx.h"
#include "Ball.h"


CBall::CBall(Vector2d center, int radius)
	:CGameObject(Rect{ center.x - radius , center.y - radius ,center.x + radius,center.y + radius })
{
	m_center = center;
	m_radius = radius;

	// 1초에 화면 길이의 절반 만큼 이동
	m_movingDir = { CLIENT_WIDTH * 0.5f , CLIENT_HEIGHT *0.5f };

	m_boundingCircle = CBoundingCircle(center, radius);
	m_size.x = m_position.right - m_position.left;
	m_size.y = m_position.bottom - m_position.top;
	m_image.Load(TEXT("resource/ball.png"));
	m_eraseColor = RGB(255, 0, 255);
}


CBall::~CBall()
{
	if (m_image) m_image.Destroy();
}

void CBall::Update(float deltaTime)
{
	Move(m_movingDir * deltaTime);
	m_center += m_movingDir * deltaTime;

	if (m_position.bottom >= CLIENT_HEIGHT)
	{
	//	m_movingDir.Reflect();
	}
	m_boundingCircle.Transform(m_center);
}

void CBall::Draw(HDC hdc)
{
	m_image.TransparentBlt(hdc, m_position.left, m_position.top, m_size.x, m_size.y, 0, 0, m_image.GetWidth(), m_image.GetHeight(), m_eraseColor);
}

CollisionBounary CBall::getCollisionBoundary(void ** addr)
{
	*addr = &m_boundingCircle;
	return CollisionBounary::Circle;
}
