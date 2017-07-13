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
	double getTimeElapsed() const { return m_timeElapsed.count(); }
	void Tick();
	
private:
	std::chrono::system_clock::time_point m_currentTime;
	std::chrono::duration<double> m_timeElapsed;
};

class CFrameTimer : public CGameTimer
{
public:
	CFrameTimer();
	
	double getFrameRate();
private:
	
private:
};