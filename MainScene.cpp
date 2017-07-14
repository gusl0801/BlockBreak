#include "stdafx.h"
#include "MainScene.h"


CMainScene::CMainScene()
{
	std::cout << "CMain() " << std::endl;
}


CMainScene::~CMainScene()
{
}

void CMainScene::Draw(HDC hdc)
{
	float width = CLIENT_WIDTH / 7;
	float height = CLIENT_HEIGHT / 7 * 0.5f;

	for (int i = 0; i < 7; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			Rectangle(hdc, width * i, height *j, width * (i + 1), height * (j + 1));
		}
	}

}

void CMainScene::Update(float deltaTime)
{
}

void CMainScene::ProcessInput()
{
}

LRESULT CMainScene::ProcessingKeyboardMessage(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	return LRESULT();
}

LRESULT CMainScene::ProcessingMouseMessage(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	return LRESULT();
}
