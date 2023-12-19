#include <iostream>
#include <vector>
#include <Windows.h>

bool isProcessRunning(const std::wstring& processName) {
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (snapshot == INVALID_HANDLE_VALUE) {
        return false;
    }

    PROCESSENTRY32 processEntry;
    processEntry.dwSize = sizeof(PROCESSENTRY32);

    if (Process32First(snapshot, &processEntry)) {
        do {
            if (_wcsicmp(processEntry.szExeFile, processName.c_str()) == 0) {
                CloseHandle(snapshot);
                return true; // Process found
            }
        } while (Process32Next(snapshot, &processEntry));
    }

    CloseHandle(snapshot);
    return false; // Process not found
}

int main() {
    std::vector<std::wstring> processesToDetect = {L"notepad.exe", L"explorer.exe", L"chrome.exe"};

    for (const auto& processName : processesToDetect) {
        if (isProcessRunning(processName)) {
            std::wcout << processName << " is running." << std::endl;
        } else {
            std::wcout << processName << " is not running." << std::endl;
        }
    }

    return 0;
}
