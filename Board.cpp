#include "stdafx.h"
#include "Board.h"


CBoard::CBoard(Rect position)
	:CGameObject(position)
{
	m_boundingBox = CBoundingBox(position);
}


CBoard::~CBoard()
{
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
		m_movingDir.x = 0;
		m_movingDir.y = 0;
	}
	m_boundingBox.Transform(m_position);
}

void CBoard::Draw(HDC hdc)
{
	Rectangle(hdc, m_position.left, m_position.top, m_position.right, m_position.bottom);
}

CollisionBounary CBoard::getCollisionBoundary(void ** addr)
{
	*addr = &m_boundingBox;
	return CollisionBounary::Box;
}
