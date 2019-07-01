#include <windows.h>

#define HIBA_00 TEXT("ERROR:Program initialisation process.")
HINSTANCE hInstGlob;
int SajatiCmdShow;
char szClassName[] = "WindowsApp";
HWND Form1;///Ablak kezelõje
LRESULT CALLBACK WndProc0(HWND, UINT, WPARAM, LPARAM);

///***************************
///A windows program belépési pontja
///***************************
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("StdWinClassName");///Winddow Class name
	HWND hwnd;
	MSG msg;
	WNDCLASS wndclass0;
	SajatiCmdShow = iCmdShow;
	hInstGlob = hInstance;

	///***************************
	///Ablak osztálypéldány elõkészítése
	///***************************

	wndclass0.style = CS_HREDRAW | CS_VREDRAW;
	wndclass0.lpfnWndProc = WndProc0;
	wndclass0.cbClsExtra = 0;
	wndclass0.cbWndExtra = 0;
	wndclass0.hInstance = hInstance;
	wndclass0.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass0.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass0.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
	wndclass0.lpszMenuName = NULL;
	wndclass0.lpszClassName = TEXT("WIN0");

	///***************************
	///Ablak osztálypéldány regisztrációja
	///***************************

	if (!RegisterClass(&wndclass0))
	{
		MessageBox(NULL, HIBA_00, TEXT("Program Start"), MB_ICONERROR);
		return 0;
	}

	///***************************
	///Ablak létrehozása
	///***************************

	Form1 = CreateWindow(TEXT("WIN0"),
		TEXT("FORM1"),
		(WS_OVERLAPPED | WS_SYSMENU | WS_THICKFRAME | WS_MAXIMIZEBOX | WS_MINIMIZEBOX),
		50,
		50,
		400,
		300,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	///***************************
	///Ablak megjelenítése
	///***************************

	ShowWindow(Form1, SajatiCmdShow);
	UpdateWindow(Form1);

	///***************************
	///Ablak üzenetküldésének aktiválása
	///***************************

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

///***************************
///Az ablak callback függvénye: eseménykezelés
///***************************

LRESULT CALLBACK WndProc0(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (message)
	{
		///***************************
		///Ablak létrehozásakor közvetlenül
		///***************************
	case WM_CREATE:
		/**Init**/
		return 0;
		///***************************
		///Ablak kliens területének újrarajzolása
		///***************************
	case WM_PAINT:
		HBRUSH hBrush;
		RECT rect;
		hdc = GetDC(hwnd);
		BeginPaint(hwnd, &ps);
		hBrush = CreateSolidBrush(RGB(255, 0, 0));
		SetRect(&rect, 0, 0, 800, 600);
		FillRect(hdc, &rect, hBrush);
		MoveToEx(hdc, 10, 10, NULL);
		LineTo(hdc, 50, 70);


		EndPaint(hwnd, &ps);
		DeleteObject(hBrush);
		ReleaseDC(hwnd, hdc);
		return 0;
		///***************************
		///Ablak bezárása
		///***************************
	case WM_CLOSE:
		DestroyWindow(hwnd);
		return 0;
		///***************************
		///Ablak megsemmisítése
		///***************************
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}



















