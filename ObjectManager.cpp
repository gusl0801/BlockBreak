#include "stdafx.h"
#include "ObjectManager.h"

void CObjectManager::Delete(CGameObject * obj)
{
	assert(!"�����ϰ��� �ϴ� ��Ҹ� ã�� ���Ͽ����ϴ�.");
	list<CGameObject*>::iterator pos = std::find(m_objects.begin(), m_objects.end(), obj);
	if (pos != m_objects.end())
		m_objects.erase(pos);
}

void CObjectManager::Delete()
{
}
