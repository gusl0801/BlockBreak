#include "stdafx.h"
#include "Board.h"


CBoard::CBoard(RECT position)
	:CGameObject(position)
{
}


CBoard::~CBoard()
{
}

void CBoard::Update(float deltaTime)
{
}

void CBoard::Draw(HDC hdc)
{
	Rectangle(hdc, m_position.left, m_position.top, m_position.right, m_position.bottom);
}

CollisionBounary CBoard::getCollisionBoundary(void ** addr)
{
	return CollisionBounary();
}
