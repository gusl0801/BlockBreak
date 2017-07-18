#pragma once
#include "Timer.h"
#include "Scene.h"
using VIEW_PORT = RECT;

class CGameFramework
{
private:
	HWND					m_hWnd;
	HINSTANCE				m_hInst;

	HDC						m_hDC;		// ���� ȭ�鿡 �׸��� ���� �ʿ��� ����̽� ���ؽ�Ʈ�Դϴ�.
	HBITMAP					m_hBuffer;	// ȭ�鿡 �׸��� ���� �׷��� ���� �Դϴ�.

	VIEW_PORT				m_viewPort;	// �׷��� ȭ�� ���� ũ��

	CScene					*m_curScene;// ���� �������� ���

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
	// ���� �Է� ó��
	void ProcessFunc();

	// �⺻ �Է� ó��
	LRESULT ProcessingWindowMessage(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
	LRESULT ProcessingKeyboardMessage(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
	LRESULT ProcessingMouseMessage(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

public:
	VIEW_PORT getViewPort() const { return m_viewPort; }

private:
	void InitBuffer();
	void InitViewPort();
};

