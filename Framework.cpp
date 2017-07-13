#include "stdafx.h"
#include "Framework.h"
#include "TitleScene.h"
#include "MainScene.h"
#include "LoadingScene.h"

#define TITLE_LENGTH	50
CGameFramework::CGameFramework()
{
	LoadString(m_hInst, IDS_APP_TITLE, m_captionTitle, TITLE_LENGTH);

	lstrcat(m_captionTitle, TEXT(" ("));
	m_titleLength = lstrlen(m_captionTitle);
	SetWindowText(m_hWnd, m_captionTitle);
}


CGameFramework::~CGameFramework()
{
	if (m_hBuffer)
		::DeleteObject(m_hBuffer);

	::SelectObject(m_hDC, NULL);
	if (m_hDC)
		::DeleteDC(m_hDC);
}

bool CGameFramework::OnCreate(HWND hWnd, HINSTANCE hInst)
{
	m_hWnd = hWnd;
	m_hInst = hInst;

	InitViewPort();
	InitBuffer();

	m_curScene = new CTitleScene();
	m_curScene->OnCreate(this);

	m_timer.Tick();
	return true;
}

void CGameFramework::ChangeScene(SceneTag tag)
{
	CScene *newScene;
	switch (tag)
	{
	case SceneTag::Main:
		newScene = new CMainScene();
		break;
	case SceneTag::Loading:
		newScene = new CLoadingScene();
		break;
	case SceneTag::Title:
		newScene = new CTitleScene();
		break;
	default:
		assert(!"잘못된 장면 전환 시도");
		break;
	}
	newScene->OnCreate(this);
	delete m_curScene;
	m_curScene = newScene;
}

void CGameFramework::ProcessInput()
{
}

void CGameFramework::FrameAdvance()
{
	int loopCount = 0;
	m_timer.Tick();
	m_timeLag += m_timer.getTimeElapsed();
	
	while (m_timeLag >= MS_PER_UPDATE && loopCount < LOOP_LIMIT)
	{
		m_timeLag -= MS_PER_UPDATE;
		loopCount += 1;
		Update();
		
	}
	
	// 업데이트 및 따라잡기가 끝나면 렌더링
	InitBuffer();
	InvalidateRect(m_hWnd, &m_viewPort, FALSE);
	float fps = m_timer.getFrameRate();

	_itow_s(fps,  m_captionTitle + m_titleLength, TITLE_LENGTH - m_titleLength, 10);
	wcscat_s(m_captionTitle + m_titleLength, TITLE_LENGTH - m_titleLength, TEXT(" FPS)"));
	SetWindowText(m_hWnd, m_captionTitle);
}

void CGameFramework::Update()
{
	m_curScene->Update(MS_PER_UPDATE);
}

void CGameFramework::Draw(HDC hdc)
{
	m_curScene->Draw(m_hDC);

	::BitBlt(hdc, m_viewPort.left, m_viewPort.top, m_viewPort.right, m_viewPort.bottom,
		m_hDC, 0, 0, SRCCOPY);
}

LRESULT CGameFramework::ProcessingWindowMessage(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_LBUTTONDOWN:
	case WM_LBUTTONUP:
	case WM_RBUTTONDOWN:
	case WM_RBUTTONUP:
	case WM_MOUSEMOVE:
	{
		//OnProcessingMouseMessage(hWnd, iMsg, wParam, lParam);
		break;
	}
	case WM_KEYDOWN:
	case WM_KEYUP:
	{
		ProcessingKeyboardMessage(hWnd, iMsg, wParam, lParam);
		break;
	}
	case WM_COMMAND:
		//m_pCurScene->OnProcessingWindowMessage(hWnd, iMsg, wParam, lParam);
		break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = ::BeginPaint(hWnd, &ps);

		Draw(hdc);

		::EndPaint(hWnd, &ps);
		break;
	}
	}
	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}

LRESULT CGameFramework::ProcessingKeyboardMessage(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	std::cout << "press key" << std::endl;
	return m_curScene->ProcessingKeyboardMessage(hWnd, iMsg, wParam, lParam);
}

LRESULT CGameFramework::ProcessingMouseMessage(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	return LRESULT();
}

void CGameFramework::InitBuffer()
{
	if (m_hDC)			//기존에 디바이스 컨텍스트가 생성되어 있다면 초기화합니다.
	{
		::SelectObject(m_hDC, NULL);
		::DeleteDC(m_hDC);
	}

	if (m_hBuffer)	//기존에 버퍼가 생성되어 있다면 초기화합니다.
	{
		::DeleteObject(m_hBuffer);
	}

	HDC hdc = ::GetDC(m_hWnd);
	m_hDC = ::CreateCompatibleDC(hdc);
	m_hBuffer = ::CreateCompatibleBitmap(hdc, m_viewPort.right, m_viewPort.bottom);
	::SelectObject(m_hDC, m_hBuffer);
	::FillRect(m_hDC, &m_viewPort, (HBRUSH)GetStockObject(WHITE_BRUSH));
	ReleaseDC(m_hWnd, hdc);
}

void CGameFramework::InitViewPort()
{
	::GetClientRect(m_hWnd, &m_viewPort);
}
