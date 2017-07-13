#pragma once
class CAnimator
{
public:
	CAnimator();
	~CAnimator();

	void Init(LPCTSTR fileName, Vector2i size, Vector2i frame, COLORREF eraseColor);
	void Init(LPCTSTR fileName, int width, int height, int column, int row, COLORREF eraseColor);

public:
	void Update(float deltaTime);

	void Draw(HDC hdc, int x, int y);
	void DrawTransparent(HDC hdc, int x, int y);
	void DrawAlphaBlend(HDC hdc, int x, int y);
private:
	CImage m_image;

	Vector2i m_size;		// ��, ����
	Vector2i m_frame;		// �̹��� ��, �� ����
	Vector2i m_curFrame;	// ���� ����� �̹��� ��, �� ����

	COLORREF m_eraseColor;	// ���� ����
};

