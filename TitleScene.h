#pragma once
#include "Scene.h"
class CTitleScene :
	public CScene
{
public:
	CTitleScene();
	~CTitleScene();

	virtual void OnCreate(CGameFramework *framework) override;

public:
	virtual void Draw(HDC hdc) override;
	virtual void Update(float deltaTime) override;
	virtual void ProcessInput() override;

	virtual LRESULT ProcessingKeyboardMessage(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
	virtual LRESULT ProcessingMouseMessage(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

private:
	CImage m_bgImage;
};

