#include <stdio.h>
#include <time.h>
#include <string.h>

int sleep(unsigned long ms) {
    clock_t stampTime = clock(), currentTime;
    do {
        if ((currentTime = clock()) < stampTime) {
            //不应该出现这种情况
            return 0;
        }
    } while (1000ul * (currentTime - stampTime) / CLOCKS_PER_SEC < ms);
    return 1;
}

int main() {

    char name[] = "123456";
    int count = 0;
    int nameLen = (int) strlen(name);
    while (1) {
        putchar('\r');
        for (int i = 0; i < nameLen; i++) {
            if (count + i < nameLen) {
                putchar(name[count + i]);
            } else {
                putchar(name[count + i - nameLen]);
            }
        }
        fflush(stdout);
        sleep(1000);
        if (count <= nameLen - 1) {
            count++;
        } else {
            break;
        }
    }
    return 0;
}