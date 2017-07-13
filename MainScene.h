#pragma once
#include "Scene.h"


class CMainScene :
	public CScene
{
public:
	CMainScene();
	~CMainScene();

public:
	virtual void Draw(HDC hdc) override;
	virtual void Update(float deltaTime) override;
	virtual void ProcessInput() override;

	virtual LRESULT ProcessingKeyboardMessage(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
	virtual LRESULT ProcessingMouseMessage(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
};

