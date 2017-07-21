// reflect_test.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
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
// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 들어 있는 함수의 정방향 선언입니다.
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
	std::cout << "충돌 " << std::endl;
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

	if (flag)	// 가로 면
	{
		pos.x = ball.x;
		pos.y = a.y;
	}
	else		// 세로 면
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

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_REFLECT_TEST, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 응용 프로그램 초기화를 수행합니다.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_REFLECT_TEST));

    MSG msg;

    // 기본 메시지 루프입니다.
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
//  함수: MyRegisterClass()
//
//  목적: 창 클래스를 등록합니다.
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
//   함수: InitInstance(HINSTANCE, int)
//
//   목적: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   설명:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

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
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  목적:  주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 응용 프로그램 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
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
            // 메뉴 선택을 구문 분석합니다.
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
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다.
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

// 정보 대화 상자의 메시지 처리기입니다.
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
