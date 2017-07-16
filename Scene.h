#pragma once
class CGameFramework;

enum class SceneTag
{
	Title,
	Loading,
	Main
};


class CScene
{
private:
	static const std::unordered_map<string, SceneTag> sceneNameToTag;

private:
	CGameFramework *m_framework;
	
public:
	CScene();
	virtual ~CScene();

	virtual void OnCreate(CGameFramework *framework);

public:
	virtual void Draw(HDC hdc) {}
	virtual void Update(float deltaTime) {}
	virtual void ProcessInput() {}

	virtual LRESULT ProcessingKeyboardMessage(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam) { return FALSE; }
	virtual LRESULT ProcessingMouseMessage(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam) { return FALSE; }

protected:
	void ChangeScene(string sceneName);
};

