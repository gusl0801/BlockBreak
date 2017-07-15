#include "stdafx.h"
#include "MainScene.h"

#include "Ball.h"
#include "Board.h"
#include "Obstacle.h"

CMainScene::CMainScene()
{
	std::cout << "CMain() " << std::endl;
}


CMainScene::~CMainScene()
{
}

void CMainScene::OnCreate(CGameFramework * framework)
{
	CScene::OnCreate(framework);

	BuildObjects();
}

void CMainScene::Draw(HDC hdc)
{
	m_ballManager.Draw(hdc);
	m_obstacleManager.Draw(hdc);
	m_boardManager.Draw(hdc);
}

void CMainScene::Update(float deltaTime)
{
	m_ballManager.Update(deltaTime);
	m_obstacleManager.Update(deltaTime);
	m_boardManager.Update(deltaTime);
}

void CMainScene::ProcessInput()
{
}

LRESULT CMainScene::ProcessingKeyboardMessage(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch(wParam)
	{
	case VK_LEFT:
		m_boardManager.Move({ -5, 0 });
		break;
	case VK_RIGHT:
		m_boardManager.Move({ 5,0 });
		break;
	}
	return LRESULT();
}

LRESULT CMainScene::ProcessingMouseMessage(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	return LRESULT();
}

void CMainScene::BuildObjects()
{
	CBall *ball;
	int xPos = CLIENT_WIDTH * 0.5f;
	int yPos = CLIENT_HEIGHT * 0.5f;
	int xSize = 50;
	int ySize = 10;
	double radius = 10.0f;

	ball = new CBall({ xPos, yPos }, radius);
	m_ballManager.Add(ball);

	yPos = CLIENT_HEIGHT * 0.9f;
	CBoard *board = new CBoard({ xPos - xSize, yPos - ySize, xPos + xSize, yPos + ySize });
	m_boardManager.Add(board);
}
