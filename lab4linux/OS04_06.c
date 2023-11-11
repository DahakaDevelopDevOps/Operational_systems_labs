#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    while (1) {
        printf("Идентификатор процесса: %d\n", getpid());
        sleep(5); // Задержка в секундах
    }
    return 0;
}

