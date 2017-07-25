#include "stdafx.h"
#include "Obstacle.h"


CObstacle::CObstacle(Rect position)
	:CGameObject(position)
{
	m_boundingBox = CBoundingBox(position);
	m_image.Load(TEXT("resource/block.png"));
	m_size.x = position.right - position.left;
	m_size.y = position.bottom - position.top;
}


CObstacle::~CObstacle()
{
	if (m_image) m_image.Destroy();
}

void CObstacle::Update(float deltaTime)
{
}

void CObstacle::Draw(HDC hdc)
{
	m_image.StretchBlt(hdc, m_position.left, m_position.top, m_size.x, m_size.y, 0, 0, m_image.GetWidth(), m_image.GetHeight(), SRCCOPY);
}

CollisionBounary CObstacle::getCollisionBoundary(void ** addr)
{
	*addr = &m_boundingBox;
	return CollisionBounary::Box;
}
