#include "stdafx.h"
#include "Obstacle.h"


CObstacle::CObstacle()
{
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
	return CollisionBounary::Box;
}
