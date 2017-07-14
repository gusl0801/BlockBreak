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
���� ȣ�⿡������ ���� ȣ������� ��� �ð��� FPS�� ǥ�� 1.0f / timeElapsed;
�ּ� ��� �ð��� �귶�ٸ� fps ����
��� 
1. fps ���� �ñ����� fps�� ����
2. ���� �ÿ��� fps ���
����� 2�� ������� ����
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