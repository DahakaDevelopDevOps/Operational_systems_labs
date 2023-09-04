#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int i;
    pid_t pid = getpid(); // получаем идентификатор процесса
    for (i = 1; i <= 1000; i++) // цикл от 1 до 1000
    {
        printf("PID: %d, сообщение: %d\n", pid, i); // выводим сообщение на консоль
        sleep(2); // ждем 2 секунды
    }
    return 0;
}
