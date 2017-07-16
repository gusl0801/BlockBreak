#pragma once
#include "Scene.h"
#include "Animation.h"

class CLoadingScene :
	public CScene
{
private:
	int test = 0;
	std::future<void> result;
	string fileName;
	CImage t;
	CAnimator m_loadingImage;

	bool m_bOnRoading;
public:
	CLoadingScene();
	~CLoadingScene();

	virtual void OnCreate(CGameFramework *framework) override;

public:
	virtual void Draw(HDC hdc) override;
	virtual void Update(float deltaTime) override;
	virtual void ProcessInput() override;

	virtual LRESULT ProcessingKeyboardMessage(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
	virtual LRESULT ProcessingMouseMessage(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

private:
	void ReadFromFile(string fileName);
};

