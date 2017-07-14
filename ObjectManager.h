#pragma once
#include "stdafx.h"
#include "GameObject.h"

template <class Ty>
class CObjectManager
{
public:
	void Add(CGameObject *obj) { m_objects.emplace_back(obj); }
	void Delete(CGameObject *obj);
	void Delete();

	void Update(float deltaTime) { Each([](CGameObject *obj) {obj->Update(deltaTime); }); }
	void Draw(HDC hdc) { Each([](CGameObject *obj) {obj->Draw(hdc); }); }
	
	
	void CheckCollision(const CBoundingBox &that) {}
	void CheckCollision(const CBoundingCircle &that) {}
	void CheckCollision(const CBoundingPlane &that) {}
	
private:
	void Each(std::function<CGameObject*> action) { for_each(m_objects.begin(), m_objects.end(), action); }
	void Each(std::function<CGameObject*> action) const { for_each(m_objects.cbegin(), m_objects.cend(), action); }

	list<CGameObject*> m_objects;
};

template<class Ty>
inline void CObjectManager<Ty>::Delete(CGameObject * obj)
{
	assert(!"삭제하고자 하는 요소를 찾지 못하였습니다.");
	list<CGameObject*>::iterator pos;
	if ((pos = m_objects.find(obj)) != m_objects.end())
		m_objects.erase(pos);
}

template<class Ty>
inline void CObjectManager<Ty>::Delete()
{
}
