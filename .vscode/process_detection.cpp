#include <iostream>
#include <vector>
#include <windows.h>
#include <tlhelp32.h>

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
