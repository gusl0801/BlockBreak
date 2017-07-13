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
