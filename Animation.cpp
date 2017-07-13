#include "stdafx.h"
#include "Animation.h"


CAnimator::CAnimator()
{
}


CAnimator::~CAnimator()
{
}

void CAnimator::Init(LPCTSTR fileName, Vector2i size, Vector2i frame, COLORREF eraseColor)
{
	m_image.Load(fileName);
	m_size = size;
	m_frame = frame;
	m_eraseColor = eraseColor;
}

void CAnimator::Init(LPCTSTR fileName, int width, int height, int column, int row, COLORREF eraseColor)
{
	m_image.Load(fileName);
	m_size.x = width; m_size.y = height;
	m_frame.x = column; m_frame.y = row;
	m_eraseColor = eraseColor;
}

void CAnimator::Update(float deltaTime)
{
	static int t = 0;
	t += 1;
	if (t >= 15)
	{
		t = 0;
		m_curFrame.x += 1;
		if (m_curFrame.x >= m_frame.x)
		{
			m_curFrame.x = 0;
			m_curFrame.y = wrap(m_curFrame.y + 1, m_frame.y);
		}
	}
}

void CAnimator::Draw(HDC hdc, int x, int y)
{
	m_image.BitBlt(hdc, x, y, m_size.x, m_size.y, m_curFrame.x * m_size.x, m_curFrame.y * m_size.y);
}

void CAnimator::DrawTransparent(HDC hdc, int x, int y)
{
	m_image.TransparentBlt(hdc, x, y, m_size.x, m_size.y,
		m_curFrame.x * m_size.x, m_curFrame.y * m_size.y, m_size.x, m_size.y, m_eraseColor);
}

void CAnimator::DrawAlphaBlend(HDC hdc, int x, int y)
{
	// CImage m_image
	m_image.AlphaBlend(hdc, 
		x, y, m_size.x,m_size.y, 
		m_curFrame.x * m_size.x, m_curFrame.y * m_size.y, m_size.x,m_size.y,
		0xff, AC_SRC_OVER);
}
