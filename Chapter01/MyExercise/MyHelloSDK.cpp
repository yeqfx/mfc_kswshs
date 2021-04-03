#include <Windows.h>
#include <tchar.h>
#include <stdio.h>
#include <cstring>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASS wndclass;
    HWND hwnd;
    MSG msg;

    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = WndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = TEXT("HelloClass");
    if (!RegisterClass(&wndclass)) return 1;

    hwnd = CreateWindow(TEXT("HElloClass"), TEXT("HelloSDK"),
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
        CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
    ShowWindow(hwnd, nCmdShow);

    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    const TCHAR* str = TEXT("hello, SDK");
    char* p_buf = new char[50];

    switch (message) {
    case WM_CREATE:
        delete p_buf;
        return 0;
    case WM_LBUTTONDOWN:
        wsprintf(p_buf, "%d", SW_MAXIMIZE);
        MessageBox(hwnd, TEXT(p_buf), TEXT("마우스 메시지"), MB_OK);
        delete p_buf;
        return 0;
    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        TextOut(hdc, 100, 100, str, lstrlen(str));
        delete p_buf;
        EndPaint(hwnd, &ps);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        delete p_buf;
        return 0;
    }

    return DefWindowProc(hwnd, message, wParam, lParam);
}