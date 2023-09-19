#include <iostream>
#include <windows.h>
#include <process.h>

void printProcessIdAndSleep(int iterations) {
    DWORD processID = GetCurrentProcessId();
    for (int i = 0; i < iterations; i++) {
        std::cout << "Process ID: " << processID << std::endl;
        Sleep(1000); // Задержка в 1 секунду
    }
}

int main() {
    printProcessIdAndSleep(100);

    if (_spawnl(_P_NOWAIT, "OS03_02_1.exe", "OS03_02_1.exe", NULL) == -1) {
        std::cerr << "Error creating process OS03_02_1.exe" << std::endl;
    }

    if (_spawnl(_P_NOWAIT, "OS03_02_2.exe", "OS03_02_2.exe", NULL) == -1) {
        std::cerr << "Error creating process OS03_02_2.exe" << std::endl;
    }

    return 0;
}
