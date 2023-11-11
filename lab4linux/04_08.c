#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Function for OS04_08_T1 thread
void *OS04_08_T1(void *arg) {
    for (int i = 1; i <= 75; ++i) {
        printf("OS04_08_T1 - Iteration %d\n", i);
        sleep(1);

        if (i == 50) {
            printf("OS04_08_T1 - Sleeping for 10 seconds\n");
            sleep(10);
        }
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t thread;

    // Create OS04_08_T1 thread
    if (pthread_create(&thread, NULL, OS04_08_T1, NULL)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    // Main thread
    for (int i = 1; i <= 100; ++i) {
        printf("Main Thread - Iteration %d\n", i);
        sleep(1);

        if (i == 30) {
            printf("Main Thread - Sleeping for 15 seconds\n");
            sleep(15);
        }
    }

    // Wait for OS04_08_T1 thread to finish
    pthread_join(thread, NULL);

    return 0;
}

