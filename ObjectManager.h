#pragma once
#include "GameObject.h"

class CObjectManager
{
private:
	list<CGameObject*> m_objects;

public:
	~CObjectManager();
public:
	void Add(CGameObject *obj) { m_objects.emplace_back(obj); }
	void Delete(CGameObject *obj);
	void Delete();

	void Update(float deltaTime) { Each([deltaTime](CGameObject *obj) {obj->Update(deltaTime); }); }
	void Draw(HDC hdc) { Each([hdc](CGameObject *obj) {obj->Draw(hdc); }); }
	void Move(Vector2d dir) { Each([dir](CGameObject *obj) {obj->Move(dir); }); }
	void Move(DWORD dir, double velocity) { Each([dir, velocity](CGameObject *obj) {obj->Move(dir, velocity); }); }
	void Stop() { Each([](CGameObject *obj) {obj->Stop(); }); }

	void CheckCollision(const CBoundingBox *that) {}
	void CheckCollision(const CBoundingCircle *that) {}
	void CheckCollision(const CBoundingPlane *that) {}

	void CheckCollision(CObjectManager &that);

private:
	void Each(std::function<void (CGameObject*)> action) { for_each(m_objects.begin(), m_objects.end(), action); }
	void Each(std::function<void (CGameObject*)> action) const { for_each(m_objects.cbegin(), m_objects.cend(), action); }
};
