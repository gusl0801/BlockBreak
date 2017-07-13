#include "stdafx.h"
#include "Timer.h"


CGameTimer::CGameTimer()
{
	m_currentTime = std::chrono::system_clock::now();
}


CGameTimer::~CGameTimer()
{
}

void CGameTimer::Tick()
{
	m_timeElapsed = std::chrono::system_clock::now() - m_currentTime;
	m_currentTime = std::chrono::system_clock::now();
}

CFrameTimer::CFrameTimer()
	:CGameTimer()
{
}

double CFrameTimer::getFrameRate()
{
	return double{};
}

