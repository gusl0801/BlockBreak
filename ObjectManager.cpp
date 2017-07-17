#include "stdafx.h"
#include "ObjectManager.h"

CObjectManager::~CObjectManager()
{
	std::for_each(m_objects.begin(), m_objects.end(), [](CGameObject *obj) {delete obj; });
	m_objects.clear();
}

void CObjectManager::Delete(CGameObject * obj)
{
	assert(!"삭제하고자 하는 요소를 찾지 못하였습니다.");
	list<CGameObject*>::iterator pos = std::find(m_objects.begin(), m_objects.end(), obj);
	if (pos != m_objects.end())
		m_objects.erase(pos);
}

void CObjectManager::Delete()
{
}

void CObjectManager::CheckCollision(CObjectManager &that)
{
	void			*boundaryThat;
	CollisionBounary typeThat;

	for (auto i = this->m_objects.begin(); i != this->m_objects.end(); ++i)
	{
		for (auto j = that.m_objects.begin(); j != that.m_objects.end(); ++j)
		{
			typeThat = (*j)->getCollisionBoundary(&boundaryThat);
			
			switch (typeThat)
			{
			case CollisionBounary::Box:
				CheckCollision(static_cast<CBoundingBox*>(boundaryThat));
				break;
			case CollisionBounary::Circle:
				if ((*i)->CheckCollision(*static_cast<CBoundingCircle*>(boundaryThat)))
					(*j)->Stop();
				CheckCollision(static_cast<CBoundingCircle*>(boundaryThat));
				break;
			case CollisionBounary::Plane:
				CheckCollision(static_cast<CBoundingPlane*>(boundaryThat));
				break;
			}
		}
	}
}
