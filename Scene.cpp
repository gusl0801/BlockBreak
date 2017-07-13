#include "stdafx.h"
#include "Scene.h"
#include "Framework.h"

const std::unordered_map<string, SceneTag> CScene::sceneNameToTag = {
	{"Title" ,  SceneTag::Title },
	{"Loading", SceneTag::Loading },
	{"Main",    SceneTag::Main }
};

CScene::CScene()
{
}


CScene::~CScene()
{
}

void CScene::OnCreate(CGameFramework * framework)
{
	m_framework = framework;
}

void CScene::ChangeScene(string sceneName)
{
	assert(sceneNameToTag.find(sceneName) != sceneNameToTag.end());
	m_framework->ChangeScene(sceneNameToTag.at(sceneName));
}
