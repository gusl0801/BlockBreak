#include "stdafx.h"
#include "LoadingScene.h"


CLoadingScene::CLoadingScene()
{
	m_bOnRoading = true;
	std::cout << "CLoadingScene()" << std::endl;
}


CLoadingScene::~CLoadingScene()
{
}

void CLoadingScene::OnCreate(CGameFramework * framework)
{
	CScene::OnCreate(framework);
	int width = 161;
	int height = 161;
	int ver = 4;
	int hor = 6;
	m_loadingImage.Init(TEXT("resource/loading_image.png"), { width, height }, { hor, ver }, RGB(255,0,255));
	result = std::async(&CLoadingScene::ReadFromFile, this, "data/user.data");

	t.Load(TEXT("resource/title.jpg"));
}

void CLoadingScene::Draw(HDC hdc)
{
	t.StretchBlt(hdc, 0, 0, CLIENT_WIDTH, CLIENT_HEIGHT, 0, 0, t.GetWidth(), t.GetHeight());

	m_loadingImage.DrawAlphaBlend(hdc, CLIENT_WIDTH * 0.5f - 161 * 0.5f, CLIENT_HEIGHT * 0.5f - 161 * 0.5f);
	//m_loadingImage.DrawTransparent(hdc, CLIENT_WIDTH * 0.5f - 161 * 0.5f, CLIENT_HEIGHT * 0.5f - 161 * 0.5f);
	
	TCHAR text[50];
	SetBkMode(hdc, TRANSPARENT);

	lstrcpy(text, TEXT("Now loading"));

	for (int i = 0; i < test; ++i)
	{
		if (test != 0)
			int c = 0;
		lstrcat(text, TEXT("."));
	}
	::TextOut(hdc, CLIENT_WIDTH * 0.4f - strlen("Now loading") , CLIENT_HEIGHT * 0.57f + 20, text, lstrlen(text));
}

void CLoadingScene::Update(float deltaTime)
{
	if (!m_bOnRoading)
	{
		ChangeScene("Main");
		return;
	}
	m_loadingImage.Update(deltaTime);
	static int i = 0;
	i += 1;
	if (i > 50)
	{
		i = 0;
		test += 1;
		if (test >10)
			test = 0;
	}
}

void CLoadingScene::ProcessInput()
{
}

LRESULT CLoadingScene::ProcessingKeyboardMessage(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	return LRESULT();
}

LRESULT CLoadingScene::ProcessingMouseMessage(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	return LRESULT();
}

void CLoadingScene::ReadFromFile(string fileName)
{
	std::fstream fIn(fileName);
	string buffer;

	while (fIn >> buffer)
	{
	}
	std::cout << "읽기 완료" << std::endl;
	m_bOnRoading = false;
}
