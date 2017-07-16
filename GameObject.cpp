#include "stdafx.h"
#include "GameObject.h"


CGameObject::CGameObject(Vector2i position, Vector2i size)
{
	m_position.left = position.x;
	m_position.top = position.y;
	m_position.right = position.x + size.x;
	m_position.bottom = position.y + size.y;
}

CGameObject::CGameObject(Rect position)
	:m_position(position)
{
}


CGameObject::~CGameObject()
{
}

void CGameObject::Move(const Vector2d &dir, bool nowUpdate)
{
	if (nowUpdate)
	{
		m_position.left += dir.x;
		m_position.right += dir.x;
		m_position.bottom += dir.y;
		m_position.top += dir.y;
	}
	else
	{
		m_movingDir = Vector2d::Clamp(m_movingDir + dir, DefineOfObject::MIN_SPEED, DefineOfObject::MAX_SPEED);
	}
}

void CGameObject::Move(const Vector2d &dir, double velocity)
{
	Move(dir * velocity);
}

void CGameObject::Move(DWORD dir, double velocity)
{
	if (dir != 0)
	{
		if (dir & DIR_LEFT)
		{
			Move({ -velocity, 0 }, false);
		}
		if (dir & DIR_RIGHT)
		{
			Move({ velocity, 0 }, false);
		}
	}
}

