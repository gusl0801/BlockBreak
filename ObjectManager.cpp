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
	void			*boundaryThat, *boundaryThis;
	CollisionBounary typeThat, typeThis;

	for (auto i = this->m_objects.begin(); i != this->m_objects.end(); ++i)
	{
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
					std::cout << "충돌" << std::endl;
					CBoundingPlane plane
						= static_cast<CBoundingBox*>(boundaryThis)->getCollidePlane(*static_cast<CBoundingCircle*>(boundaryThat));
					(*j)->HandleCollision(plane.getNormal());
					//(*j)->Stop();
				}
				break;
			case CollisionBounary::Plane:
				break;
			}
		}
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
