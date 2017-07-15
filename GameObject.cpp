#include "stdafx.h"
#include "GameObject.h"


CGameObject::CGameObject(Vector2i position, Vector2i size)
{
	m_position.left = position.x;
	m_position.top = position.y;
	m_position.right = position.x + size.x;
	m_position.bottom = position.y + size.y;
}

CGameObject::CGameObject(RECT position)
	:m_position(position)
{
}


CGameObject::~CGameObject()
{
}

void CGameObject::Move(Vector2i dir)
{
	m_position.left += dir.x;
	m_position.right += dir.x;
	m_position.bottom += dir.y;
	m_position.top += dir.y;
}

void CGameObject::Move(Vector2i dir, int velocity)
{
	dir *= velocity;

	Move(dir);
}

