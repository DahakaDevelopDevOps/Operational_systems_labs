#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* OS04_07_T1(void* arg) {
    for (int i = 0; i < 75; i++) {
        printf("Поток T1, Идентификатор процесса: %d\n", getpid());
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t thread;
    if (pthread_create(&thread, NULL, OS04_07_T1, NULL) != 0) {
        perror("Ошибка при создании потока");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 100; i++) {
        printf("Основной процесс, Идентификатор процесса: %d\n", getpid());
        sleep(1);
    }

    pthread_join(thread, NULL);
    
    return 0;
}

