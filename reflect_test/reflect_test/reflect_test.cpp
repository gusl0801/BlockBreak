// reflect_test.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "reflect_test.h"
#include <algorithm>
#include <iostream>
#define MAX_LOADSTRING 100

#ifdef _DEBUG
#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif
#endif
// ���� ����:
HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.

// �� �ڵ� ��⿡ ��� �ִ� �Լ��� ������ �����Դϴ�.
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

typedef struct _point
{
	double x;
	double y;
	_point() :x(0), y(0) {}
	//_point(double x, double y) : x(x), y(y) {}
	_point(LONG x_, LONG y_) { x = static_cast<double>(x_), y = static_cast<double>(y_); }
}Point;
Point getNormal(const Point &a, const Point &b)
{
	LONG x = b.x - a.x;
	LONG y = b.y - a.y;
	return Point{-y, x};
}
double dot(const Point &a, const Point &b)
{
	return { a.x * b.x + a.y * b.y };
}
void reflect(Point &p, const Point &n)
{
	std::cout << "�浹 " << std::endl;
	Point r;
	LONG x = (LONG)-p.x, y = (LONG)-p.y;
	double dot_ = dot({ x,y }, n);
	r.x = p.x + 2 * n.x * dot_;
	r.y = p.y + 2 * n.y * dot_;

	p = r;
}
void normalize(Point &vec)
{
	double length = std::sqrt(vec.x * vec.x + vec.y * vec.y);
	vec.x /= length;
	vec.y /= length;
}

bool isCollide(const Point &ball, const Point &a, const Point &b, bool flag)
{
	Point pos;
	double distance;
	double radius = 10;

	if (flag)	// ���� ��
	{
		pos.x = ball.x;
		pos.y = a.y;
	}
	else		// ���� ��
	{
		pos.x = a.x;
		pos.y = ball.y;
	}
	distance = std::sqrt((std::pow(ball.x - pos.x, 2) + std::pow(ball.y - pos.y, 2)));
	return distance <= radius;
}
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: ���⿡ �ڵ带 �Է��մϴ�.

    // ���� ���ڿ��� �ʱ�ȭ�մϴ�.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_REFLECT_TEST, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ���� ���α׷� �ʱ�ȭ�� �����մϴ�.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_REFLECT_TEST));

    MSG msg;

    // �⺻ �޽��� �����Դϴ�.
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  �Լ�: MyRegisterClass()
//
//  ����: â Ŭ������ ����մϴ�.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_REFLECT_TEST));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= NULL;//MAKEINTRESOURCEW(IDC_REFLECT_TEST);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   �Լ�: InitInstance(HINSTANCE, int)
//
//   ����: �ν��Ͻ� �ڵ��� �����ϰ� �� â�� ����ϴ�.
//
//   ����:
//
//        �� �Լ��� ���� �ν��Ͻ� �ڵ��� ���� ������ �����ϰ�
//        �� ���α׷� â�� ���� ���� ǥ���մϴ�.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ����:  �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND  - ���� ���α׷� �޴��� ó���մϴ�.
//  WM_PAINT    - �� â�� �׸��ϴ�.
//  WM_DESTROY  - ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static RECT client;
	static Point ballPos;
	static Point ballDir;
	static HDC	 backDC;
	static HBITMAP backBuffer;
	static Point normals[4];

    switch (message)
    {
	case WM_CREATE:
		::GetClientRect(hWnd, &client);
		ballDir.x = 5;
		ballDir.y = 5;
		ballPos.x = client.right * 0.5f;
		ballPos.y = client.bottom * 0.5f;

		//top 
		normals[0] = getNormal({ 0,0 }, {client.right,0});
		//right;
		normals[1] = getNormal({ client.right,0 }, { client.right, client.bottom });
		//bottom
		normals[2] = getNormal({ client.right, client.bottom }, { 0, client.bottom });
		//left;
		normals[3] = getNormal({ 0, client.bottom }, { 0,0 });
		std::for_each(std::begin(normals), std::end(normals), [](Point &normal) { normalize(normal); });

		SetTimer(hWnd, 0, 17, NULL);
		break;
	case WM_TIMER:
		ballPos.x += ballDir.x;
		ballPos.y += ballDir.y;

		//top
		if (isCollide(ballPos, { 0,0 }, { client.right,0 }, true))
			reflect(ballDir, normals[0]);
		
		//right
		else if (isCollide(ballPos, {client.right,0}, {client.right, client.bottom}, false))
			reflect(ballDir, normals[1]);
		
		//bottom
		else if (isCollide(ballPos, {0,client.bottom}, {client.right, client.bottom}, true))
			reflect(ballDir, normals[2]);
		
		//left
		else if (isCollide(ballPos, {0,0}, {0,client.bottom}, false))
			reflect(ballDir, normals[3]);
		
		InvalidateRect(hWnd, &client, FALSE);
		break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // �޴� ������ ���� �м��մϴ�.
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�.
			backDC = ::CreateCompatibleDC(hdc);
			backBuffer = ::CreateCompatibleBitmap(hdc, client.right, client.bottom);
			::SelectObject(backDC, backBuffer);
			::FillRect(backDC, &client, (HBRUSH)GetStockObject(WHITE_BRUSH));
			
			::Ellipse(backDC, ballPos.x - 10, ballPos.y - 10, ballPos.x + 10, ballPos.y + 10);

			BitBlt(hdc, 0, 0, client.right, client.bottom, backDC, 0, 0, SRCCOPY);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// ���� ��ȭ ������ �޽��� ó�����Դϴ�.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
