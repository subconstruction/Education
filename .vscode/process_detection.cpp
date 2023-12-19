#include <iostream>
#include <vector>
#include <windows.h>
#include <tlhelp32.h>

bool UnmuteVolume() {
    HRESULT hr;
    IMMDeviceEnumerator* pEnumerator = nullptr;
    IMMDevice* pDevice = nullptr;
    IAudioEndpointVolume* pVolume = nullptr;

    // Initialize COM library
    CoInitialize(nullptr);

    // Create the device enumerator
    hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), nullptr, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator), (void**)&pEnumerator);

    if (SUCCEEDED(hr)) {
        // Get the default audio endpoint
        hr = pEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &pDevice);
    }

    if (SUCCEEDED(hr)) {
        // Activate the audio endpoint volume interface
        hr = pDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_ALL, nullptr, (void**)&pVolume);
    }

    if (SUCCEEDED(hr)) {
        // Unmute the volume
        hr = pVolume->SetMute(FALSE, nullptr);
    }

    // Release COM objects
    if (pVolume) {
        pVolume->Release();
    }

    if (pDevice) {
        pDevice->Release();
    }

    if (pEnumerator) {
        pEnumerator->Release();
    }

    // Uninitialize COM library
    CoUninitialize();

    return SUCCEEDED(hr);
}

// Function to check if a process with the specified name is running
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
                return true; // Process found
            }
        } while (Process32Next(hSnapshot, &pe32));
    }

    CloseHandle(hSnapshot);
    return false; // Process not found
}

int main() {
    // Specify the process names to detect
    std::vector<std::wstring> processNames = { L"notepad.exe", L"explorer.exe", L"chrome.exe" };

    // Check if each process is running
    for (const auto& processName : processNames) {
        if (IsProcessRunning(processName)) {
            std::wcout << processName << " is running." << std::endl;
        } else {
            std::wcout << processName << " is not running." << std::endl;
        }
    }

    return 0;
}
