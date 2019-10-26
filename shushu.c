#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int scanff();
int main(void) {
    srand(time(NULL));
    int a, b, n, arr[100], i = 0;
    a = scanff();

    switch (a) {
    case 0: a = scanff();break;

    case 1: b = rand() % 10 + 0;   break;

    case 2: b = rand() % 100 + 0;   break;

    case 3: b = rand() % 1000 + 0;   break;

    case 4: b = rand() % 10000 + 0;   break;

    default: printf("输入难度不符合要求\n"); break;
    }

    printf("请输入想要猜的次数\n");
    scanf("%d", &n);

    for (; i < n; i++) {
        printf("请输入您猜测的数字\n");
        scanf("%d", arr + i);

        if (arr[i] == b) {
            printf("回答正确\n");
            n = i;
            break;
        } else { printf("回答错误\n"); }
    }

    for (int j = 0; j < n; j++) {
        printf("%d   %d   %d\n", j + 1, arr[j], arr[j] - b);
    }

    return 0;
}
int scanff() {
    int a;

    do {
        printf("请选择难度等级\n");
        printf("1.  0~9\n");
        printf("2.  0~99\n");
        printf("3.  0~999\n");
        printf("4.  0~9999\n");
        scanf("%d", &a);
    } while (a < 0 || a > 4);

    return a;
}





