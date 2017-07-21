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

	CheckCollsion();
}

void CMainScene::ProcessInput()
{
	static UCHAR pKeyBuffer[256];
	DWORD dwDirection = 0;

	if (::GetKeyboardState(pKeyBuffer))
	{
		if (pKeyBuffer[VK_LEFT] & 0xF0)
		{
			dwDirection |= DIR_LEFT;
		}
		if (pKeyBuffer[VK_RIGHT] & 0xF0)
		{
			dwDirection |= DIR_RIGHT;
		}
		if (pKeyBuffer[VK_SPACE] & 0xF0) {
			//std::cout << "press space" << std::endl;
			//m_pScene->AddBullets(m_pPlayer);
		}
	}

	//마우스 또는 키 입력이 있으면 플레이어를 이동하거나(dwDirection) 회전한다.
	if ((dwDirection != 0))
	{
		if (dwDirection)
		{
			 m_boardManager.Move(dwDirection, 5.0f);
		}
	}
}

LRESULT CMainScene::ProcessingKeyboardMessage(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch(wParam)
	{
	case VK_LEFT:
		//m_boardManager.Move({ -5, 0 });
		break;
	case VK_RIGHT:
		//m_boardManager.Move({ 5,0 });
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
	double xPos = CLIENT_WIDTH * 0.5f;
	double yPos = CLIENT_HEIGHT * 0.5f;
	double xSize = 50;
	double ySize = 10;
	double radius = 10.0f;

	ball = new CBall({ xPos, yPos }, radius);
	m_ballManager.Add(ball);

	yPos = CLIENT_HEIGHT * 0.9f;
	CBoard *board = new CBoard({ xPos - xSize, yPos - ySize, xPos + xSize, yPos + ySize });
	m_boardManager.Add(board);

	CBoundingPlane top{ { 0,0 }, { static_cast<double>(m_viewPort.right), 0 }};
	CBoundingPlane bottom{ { 0, static_cast<double>(m_viewPort.bottom) }, { static_cast<double>(m_viewPort.right),  static_cast<double>(m_viewPort.bottom) },WindingOrder::CCW };
	CBoundingPlane left{{ 0,0 }, { 0,  static_cast<double>(m_viewPort.bottom) }, WindingOrder::CCW };
	CBoundingPlane right{ { static_cast<double>(m_viewPort.right),0 }, { static_cast<double>(m_viewPort.right),  static_cast<double>(m_viewPort.bottom) } };

	m_wallPlanes[0] = top;	
	m_wallPlanes[1] = bottom;
	m_wallPlanes[2] = left;
	m_wallPlanes[3] = right;
}

void CMainScene::CheckCollsion()
{
	m_boardManager.CheckCollision(m_ballManager);
	m_ballManager.CheckCollision(m_obstacleManager);
	
	std::for_each(m_wallPlanes.begin(), m_wallPlanes.end(),
		[&ballManager = m_ballManager](const CBoundingPlane &plane) {ballManager.CheckCollision(plane); });
}
