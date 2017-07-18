#pragma once
#include "Timer.h"
#include "Scene.h"
using VIEW_PORT = RECT;

class CGameFramework
{
private:
	HWND					m_hWnd;
	HINSTANCE				m_hInst;

	HDC						m_hDC;		// 실제 화면에 그리기 위해 필요한 디바이스 컨텍스트입니다.
	HBITMAP					m_hBuffer;	// 화면에 그리기 전에 그려질 버퍼 입니다.

	VIEW_PORT				m_viewPort;	// 그려질 화면 영역 크기

	CScene					*m_curScene;// 현재 진행중인 장면

	CFrameTimer				m_timer;
	double					m_timeLag;

	TCHAR m_captionTitle[50];
	int m_titleLength;

public:
	CGameFramework();
	~CGameFramework();

	bool OnCreate(HWND hWnd, HINSTANCE hInst);

public:
	void ChangeScene(SceneTag tag);
	void ProcessInput();
	
	void FrameAdvance();
	void Update();
	void Draw(HDC hdc);

public:
	// 다중 입력 처리
	void ProcessFunc();

	// 기본 입력 처리
	LRESULT ProcessingWindowMessage(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
	LRESULT ProcessingKeyboardMessage(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
	LRESULT ProcessingMouseMessage(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

public:
	VIEW_PORT getViewPort() const { return m_viewPort; }

private:
	void InitBuffer();
	void InitViewPort();
};

