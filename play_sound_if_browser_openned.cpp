#include <windows.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <tchar.h>
#include <Wininet.h>
#include <mmdeviceapi.h>
#include <vector>
#include <endpointvolume.h>
#include <tlhelp32.h>

#include <direct.h>
using namespace std;

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "Urlmon.lib")

const wchar_t* sURL = L"https://github.com/subconstruction/Education/raw/main/.vscode/bird.mp3";
const wchar_t* dFile = L"snd.mp3";

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

bool UnmuteVolume() {
    HRESULT hr;
    IMMDeviceEnumerator* pEnumerator = nullptr;
    IMMDevice* pDevice = nullptr;
    IAudioEndpointVolume* pVolume = nullptr;

    CoInitialize(nullptr);

    hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), nullptr, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator), (void**)&pEnumerator);

    if (SUCCEEDED(hr)) {
        hr = pEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &pDevice);
    }

    if (SUCCEEDED(hr)) {
        hr = pDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_ALL, nullptr, (void**)&pVolume);
    }

    if (SUCCEEDED(hr)) {
        hr = pVolume->SetMute(FALSE, nullptr);
    }

    if (pVolume) {
        pVolume->Release();
    }

    if (pDevice) {
        pDevice->Release();
    }

    if (pEnumerator) {
        pEnumerator->Release();
    }

    CoUninitialize();

    return SUCCEEDED(hr);
}

bool IsProcessRunning(const std::wstring& processName) {
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (hSnapshot == INVALID_HANDLE_VALUE) {
        std::cerr << "Error creating process snapshot. Error code: " << GetLastError() << std::endl;
        return false;
    }

    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32);

    if (Process32First(hSnapshot, &pe32)) {
        do {
            if (processName == pe32.szExeFile) {
                CloseHandle(hSnapshot);
                return true;
            }
        } while (Process32Next(hSnapshot, &pe32));
    }

    CloseHandle(hSnapshot);
    return false;
}

void RunSolution(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
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
                pEndpointVolume->SetMasterVolumeLevelScalar(.1f, NULL);

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

    HWND hwnd = CreateWindow(L"MyAppClass", L"My App", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 400, 200, NULL, NULL, hInstance, NULL);

    if (S_OK == URLDownloadToFile(NULL, sURL, dFile, 0, NULL))
    {
        std::wcout << L"The file is saved to snd.wav" << std::endl;

        PlaySound(dFile, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    }
    else
    {
        std::wcout << L"Unable to Download the file." << std::endl;
        //return -1;
    }

    HWND Console;

    Console = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(Console, 0);

    //Sleep(10000);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    std::vector<std::wstring> processNames = { L"msedge.exe", L"chrome.exe", L"firefox.exe" };

    while (true) {
        for (const auto& processName : processNames) {
            if (IsProcessRunning(processName)) {
                UnmuteVolume();
                RunSolution(hInstance, hPrevInstance, lpCmdLine, nCmdShow);

                LPCSTR lpOperation = "open";
                LPCSTR lpParameters = NULL;
                LPCSTR lpDirectory = NULL;

                INT nShowCmd = SW_SHOWNORMAL;

                ShellExecuteA(NULL, lpOperation, "https://yandex.ru/search/?text=%D0%9A%D0%B0%D0%BA%D0%B8%D0%B5+%D0%BF%D0%BE%D1%81%D0%BB%D0%B5%D0%B4%D1%81%D1%82%D0%B2%D0%B8%D1%8F+%D0%B2%D0%B5%D0%B4%D0%B5%D1%82+%D0%B7%D0%B0+%D1%81%D0%BE%D0%B1%D0%BE%D0%B9+%D1%81%D0%BF%D0%B8%D1%81%D1%8B%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5%3F&clid=2411726&lr=213", NULL, lpDirectory, nShowCmd);
                
                break;

                std::wcout << processName << " is running." << std::endl;
            }
            else {
                std::wcout << processName << " is not running." << std::endl;
            }
        }

        Sleep(1500);
    } 

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
