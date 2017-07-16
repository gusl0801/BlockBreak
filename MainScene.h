#pragma once
#include "Scene.h"

#include "ObjectManager.h"

class CBoard;

class CMainScene :
	public CScene
{
private:
	CObjectManager	m_ballManager;
	CObjectManager	m_obstacleManager;
	CObjectManager  m_boardManager;

public:
	CMainScene();
	~CMainScene();

	virtual void OnCreate(CGameFramework *framework) override;
public:
	virtual void Draw(HDC hdc) override;
	virtual void Update(float deltaTime) override;
	virtual void ProcessInput() override;

	virtual LRESULT ProcessingKeyboardMessage(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
	virtual LRESULT ProcessingMouseMessage(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

private:
	void BuildObjects();
};

