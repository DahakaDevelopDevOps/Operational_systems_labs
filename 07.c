#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>

int main() {
  pid_t pid = getpid();
  printf("[OS08_07] PID = %d\n", pid);
  sleep(10);

  // Create a file to back the memory mapping
  int fd = open("data.bin", O_RDWR | O_CREAT, 0644);
  if (fd < 0) {
    perror("open");
    exit(1);
  }

  // Set the file size to the desired memory size
  if (ftruncate(fd, 1024 * 1024 * 256) < 0) {
    perror("ftruncate");
    close(fd);
    exit(1);
  }

  // Map the file to the process's address space
  void* memr = mmap(NULL, 1024 * 1024 * 256, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (memr == MAP_FAILED) {
    perror("mmap");
    close(fd);
    exit(1);
  }

  printf("memr(1024 * 1024) = %p\n", memr);

  int* arr = (int*) memr;
  for (int i = 0; i < 256; i++) {
    arr[i] = i;
  }

  sleep(20);

  // Unmap the memory from the process's address space
  if (munmap(memr, 1024 * 1024 * 256) < 0) {
    perror("munmap");
  }

  // Close the file
  close(fd);

  exit(0);
}
