#include <Windows.h>

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
    int answer;

    switch (message) {
    case WM_CREATE:
        return 0;
    case WM_LBUTTONDOWN:
        // ���콺 ���� ��ư�� ������ '�����Ͻðڽ��ϱ�?' �޽����� �ְ�,
        // <Ȯ��>/<���> ��ư�� �ִ� �޽��� ���ڰ� ��Ÿ������ ����
        // <Ȯ��> ��ư�� Ŭ���ϸ� ���α׷��� ����
        answer = MessageBox(hwnd, TEXT("�����Ͻðڽ��ϱ�?"), TEXT("���콺 �޽���"), MB_OKCANCEL | MB_ICONQUESTION);
        if (answer == IDOK) PostQuitMessage(0);
        return 0;
    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);
        TextOut(hdc, 100, 100, str, lstrlen(str));
        EndPaint(hwnd, &ps);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd, message, wParam, lParam);
}