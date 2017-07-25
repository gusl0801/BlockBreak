#include "stdafx.h"
#include "Board.h"


CBoard::CBoard(Rect position)
	:CGameObject(position)
{
	m_boundingBox = CBoundingBox(position);
	m_size.x = position.right - position.left;
	m_size.y = position.bottom - position.top;
	m_image.Load(TEXT("resource/board_1.png"));
}


CBoard::~CBoard()
{
	if (m_image) m_image.Destroy();
}

void CBoard::Update(float deltaTime)
{
	if (m_movingDir.isZero()) return;

//	double velocity;
	const double stopSpeed = 4.0f;
	Vector2d velocity = m_movingDir * deltaTime;
	
	Move(velocity, true);
	m_movingDir -= velocity;

	if (m_movingDir.Length() < stopSpeed)
	{
		Stop();
	}
	m_boundingBox.Transform(m_position);
}

void CBoard::Draw(HDC hdc)
{
	m_image.StretchBlt(hdc, m_position.left, m_position.top, m_size.x, m_size.y, 0, 0, m_image.GetWidth(), m_image.GetHeight(), SRCCOPY);
}

CollisionBounary CBoard::getCollisionBoundary(void ** addr)
{
	*addr = &m_boundingBox;
	return CollisionBounary::Box;
}
