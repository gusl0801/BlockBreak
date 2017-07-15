#include "stdafx.h"
#include "ObjectManager.h"

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
