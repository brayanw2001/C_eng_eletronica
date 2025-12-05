#include "Time.h";
#include "Time.c";

int main() {
    Time t1 = {2, 58, 40};
    Time t2 = {3, 49, 23};

    Time t3 = SumTime(t1, t2);
    Time t4 = TimeDiff(t1, t2);
    int seconds = TimeToSeconds(t1);

    printf("Tempo somado: %d:%d:%d", t3.hour, t3.minutes, t3.seconds);
    printf("Diferença de tempo: %d:%d:%d", t4.hour, t4.minutes, t4.seconds);
    printf("Tempo convertido para segundos: %d", seconds);

    return 0;
}