#include "stdafx.h"
#include "ObjectManager.h"

CObjectManager::~CObjectManager()
{
	std::for_each(m_objects.begin(), m_objects.end(), [](CGameObject *obj) {delete obj; });
	m_objects.clear();
}

list<CGameObject*>::iterator CObjectManager::Delete(CGameObject * obj)
{

	list<CGameObject*>::iterator pos = std::find(m_objects.begin(), m_objects.end(), obj);
	//assert(!"삭제하고자 하는 요소를 찾지 못하였습니다." && pos == m_objects.end());
	if (pos != m_objects.end())
		pos = m_objects.erase(pos);
	return pos;
}

list<CGameObject*>::iterator CObjectManager::Delete()
{
	return {};
}

void CObjectManager::CheckCollision(CObjectManager &that)
{
	void			*boundaryThat, *boundaryThis;
	CollisionBounary typeThat, typeThis;

	for (auto i = this->m_objects.begin(); i != this->m_objects.end();)
	{
		bool isCollide = false;
		typeThis = (*i)->getCollisionBoundary(&boundaryThis);
		for (auto j = that.m_objects.begin(); j != that.m_objects.end(); ++j)
		{
			typeThat = (*j)->getCollisionBoundary(&boundaryThat);

			switch (typeThat)
			{
			case CollisionBounary::Box:
				break;
			case CollisionBounary::Circle:
				if ((*i)->CheckCollision(*static_cast<CBoundingCircle*>(boundaryThat)))
				{
					CBoundingPlane plane
						= static_cast<CBoundingBox*>(boundaryThis)->getCollidePlane(*static_cast<CBoundingCircle*>(boundaryThat));
					(*j)->HandleCollision(plane.getNormal());
					isCollide = true;
				}
				break;
			case CollisionBounary::Plane:
				break;
			}
		}
		if (isCollide) {
			i = this->Delete(*i);
			break;
		}
		else
			++i;
	}
}

void CObjectManager::CheckCollision(const CBoundingPlane & plane)
{
	Each([plane](CGameObject *obj) 
	{
		if (obj->CheckCollision(plane)) {
			std::cout << "충돌" << std::endl;
			obj->HandleCollision(plane.getNormal());
		}
	});
}
