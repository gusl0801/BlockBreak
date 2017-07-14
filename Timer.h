#pragma once

#define MAX_FPS 80.0f
#define MS_PER_UPDATE 1.0f / MAX_FPS
#define LOOP_LIMIT 15
#define FPS_UPDATE_LIMIT 0.5

template <class Ty>
struct _TimerVal
{
	std::chrono::system_clock::time_point currentTime;
	std::chrono::duration<Ty> timeElapsed;
};
using TimerVal = _TimerVal<double>;
	
class CGameTimer
{
public:
	CGameTimer();
	~CGameTimer();

public:
	double getTimeElapsed() const { return m_basicTimer.timeElapsed.count(); }
	void Tick();
	
private:
	TimerVal m_basicTimer;
};

/*
이전 호출에서부터 현재 호출까지의 경과 시간을 FPS로 표현 1.0f / timeElapsed;
최소 경과 시간이 흘렀다면 fps 갱신
방식 
1. fps 갱신 시까지의 fps를 누적
2. 갱신 시에만 fps 계산
현재는 2번 방식으로 구현
*/
class CFrameTimer : public CGameTimer
{
public:
	CFrameTimer();
	
	double getFrameRate();
private:
	void Update();

private:
	TimerVal m_timeChecker;

	double m_timeSum;
	int m_nSumCount;

	double m_fps;
};