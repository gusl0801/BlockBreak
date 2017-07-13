#include "stdafx.h"
#include "TitleScene.h"


CTitleScene::CTitleScene()
{
}


CTitleScene::~CTitleScene()
{
	//m_bgImage.Destroy();
}

void CTitleScene::OnCreate(CGameFramework * framework)
{
	CScene::OnCreate(framework);
	m_bgImage.Load(TEXT("resource/title.jpg"));
}

void CTitleScene::Draw(HDC hdc)
{
	m_bgImage.StretchBlt(hdc, 0, 0, CLIENT_WIDTH, CLIENT_HEIGHT, 0, 0, m_bgImage.GetWidth(), m_bgImage.GetHeight());
}

void CTitleScene::Update(float deltaTime)
{
}

void CTitleScene::ProcessInput()
{
}

LRESULT CTitleScene::ProcessingKeyboardMessage(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
	case VK_SPACE:
		ChangeScene("Loading");
	}
	return FALSE;
}

LRESULT CTitleScene::ProcessingMouseMessage(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	return FALSE;
}
