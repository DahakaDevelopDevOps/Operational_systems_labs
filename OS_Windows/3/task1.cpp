#include <iostream>
#include <windows.h>

int main() {
    DWORD processID = GetCurrentProcessId();

    for (int i = 0; i < 100; i++) {
        std::cout << "Process ID: " << processID << std::endl;
        Sleep(1000); // Задержка в 1 секунду
    }

    return 0;
}
