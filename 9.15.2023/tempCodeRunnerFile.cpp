#include <windows.h>

// Global variables
HWND g_hWnd;
HWND g_hButton;
HWND g_hText;

// Function declarations
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void CreateControls(HWND hWnd);
void ToggleTextVisibility();

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) {
    // Register the window class.
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    // Create the window.
    g_hWnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Windows App with Text and Button", // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, 500, 300,

        NULL,       // Parent window
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );

    if (g_hWnd == NULL) {
        return 0;
    }

    ShowWindow(g_hWnd, nCmdShow);

    // Run the message loop.
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_CREATE:
        CreateControls(hWnd);
        break;
    case WM_COMMAND:
        if (LOWORD(wParam) == BN_CLICKED && (HWND)lParam == g_hButton) {
            ToggleTextVisibility();
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

void CreateControls(HWND hWnd) {
    // Create a button
    g_hButton = CreateWindowEx(0, L"BUTTON", L"Toggle Text", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        10, 10, 100, 30, hWnd, NULL, NULL, NULL);

    // Create a static text control
    g_hText = CreateWindowEx(0, L"STATIC", L"Desired Text", WS_VISIBLE | WS_CHILD | SS_LEFT,
        10, 50, 200, 100, hWnd, NULL, NULL, NULL);
}

void ToggleTextVisibility() {
    // Get the current visibility state of the text control
    BOOL isVisible = IsWindowVisible(g_hText);

    // Toggle the visibility of the text control
    ShowWindow(g_hText, isVisible ? SW_HIDE : SW_SHOW);
}
