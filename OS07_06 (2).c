#include <stdio.h>
#include <time.h>

int main() {
  int i = 0;
  struct timespec start, end;
  double real_time;

  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
  clock_gettime(CLOCK_REALTIME, &start);

  while (1) {
    i++;
    if (clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end) == -1) {
      perror("clock_gettime");
      return 1;
    }

    if (clock_gettime(CLOCK_REALTIME, &end) == -1) {
      perror("clock_gettime");
      return 1;
    }

    real_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    if (end.tv_sec - start.tv_sec >= 2) {
      printf("i = %d, real_time = %.3f, cpu_time = %lu\n", i, real_time, (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1e6);
      break;
    }
  }

  return 0;
}
