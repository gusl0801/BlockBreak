#include "stdafx.h"
#include "Timer.h"


CGameTimer::CGameTimer()
{
	m_basicTimer.currentTime = std::chrono::system_clock::now();
}


CGameTimer::~CGameTimer()
{
}

void CGameTimer::Tick()
{
	m_basicTimer.timeElapsed = std::chrono::system_clock::now() - m_basicTimer.currentTime;
	m_basicTimer.currentTime = std::chrono::system_clock::now();
}

CFrameTimer::CFrameTimer()
	:CGameTimer()
{
	m_timeSum = 0;
	m_nSumCount = 0;
}

double CFrameTimer::getFrameRate()
{
	// 지정된 시간이 경과 했다면
	if (m_timeChecker.timeElapsed.count() > FPS_UPDATE_LIMIT)
	{
		// fps 갱신
		Update();
	}
	else // 경과 하지 않았다면
	{
		// 경과 시간 갱신
		m_timeChecker.timeElapsed = std::chrono::system_clock::now() - m_timeChecker.currentTime;
		
		m_timeSum += getTimeElapsed();
		++m_nSumCount;
	}
	return m_fps;
}

void CFrameTimer::Update()
{
	m_fps = 1.0f / (m_timeSum / m_nSumCount);
	m_timeSum = 0;
	m_nSumCount = 0;

	m_timeChecker.currentTime = std::chrono::system_clock::now();
	m_timeChecker.timeElapsed = m_timeChecker.currentTime - m_timeChecker.currentTime;
}

