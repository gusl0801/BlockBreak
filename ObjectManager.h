#pragma once
#include "GameObject.h"

class CObjectManager
{
public:
	void Add(CGameObject *obj) { m_objects.emplace_back(obj); }
	void Delete(CGameObject *obj);
	void Delete();

	void Update(float deltaTime) { Each([deltaTime](CGameObject *obj) {obj->Update(deltaTime); }); }
	void Draw(HDC hdc) { Each([hdc](CGameObject *obj) {obj->Draw(hdc); }); }
	
	void CheckCollision(const CBoundingBox *that) {}
	void CheckCollision(const CBoundingCircle *that) {}
	void CheckCollision(const CBoundingPlane *that) {}

	void CheckCollision(CObjectManager &that);

private:
	void Each(std::function<void (CGameObject*)> action) { for_each(m_objects.begin(), m_objects.end(), action); }
	void Each(std::function<void (CGameObject*)> action) const { for_each(m_objects.cbegin(), m_objects.cend(), action); }

	list<CGameObject*> m_objects;
};
