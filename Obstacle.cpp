#include "stdafx.h"
#include "Obstacle.h"


CObstacle::CObstacle(Rect position)
	:CGameObject(position)
{
	m_boundingBox = CBoundingBox(position);
}


CObstacle::~CObstacle()
{
}

void CObstacle::Update(float deltaTime)
{
}

void CObstacle::Draw(HDC hdc)
{
	Rectangle(hdc, m_position.left, m_position.top, m_position.right, m_position.bottom);
}

CollisionBounary CObstacle::getCollisionBoundary(void ** addr)
{
	*addr = &m_boundingBox;
	return CollisionBounary::Box;
}
