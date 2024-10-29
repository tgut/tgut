/*
 * @Descripttion: 
 * @version: 
 * @Author: tgut
 * @Date: 2024-07-30 16:44:10
 * @LastEditors: tgut
 * @LastEditTime: 2024-07-30 17:24:11
 */

#if 0

/*1.signal to do timer function */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handle_sigalrm(int sig) {
    printf("Alarm received!\n");
    // 执行定时任务
}

int main() {
    signal(SIGALRM, handle_sigalrm); // 设置信号处理函数

    alarm(5); // 设置5秒后发出SIGALRM信号
    printf("Waiting for alarm to go off...\n");

    pause(); // 等待信号到来

    return 0;
}
#endif

#if 0
/* 使用itimerval来实现*/
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <signal.h>

void handle_sigalrm(int sig) {
    printf("Timer tick\n");
    // 执行定时任务
}

int main() {
    struct itimerval timer;

    memset(&timer, 0, sizeof(timer));
    timer.it_value.tv_sec = 5;      // 首次定时时间
    timer.it_interval.tv_sec = 2;   // 定时周期

    signal(SIGALRM, handle_sigalrm);
    setitimer(ITIMER_REAL, &timer, NULL);

    while (1) {
        pause(); // 循环等待信号
    }

    return 0;
}
#endif

/*使用select poll 来实现*/
#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>

int main() {
    struct timeval tv;
    int res;

    tv.tv_sec = 5;
    tv.tv_usec = 0;

    res = select(0, NULL, NULL, NULL, &tv);
    if (res == 0) {
        printf("Timer expired\n");
        // 执行定时任务
    } else if (res == -1) {
        perror("select");
    }

    return 0;
}