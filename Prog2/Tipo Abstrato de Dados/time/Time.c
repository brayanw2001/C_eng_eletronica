#include<stdlib.h>
#include<stdio.h>
#include"Time.h"

struct Time
{
    int hour;
    int minutes;
    int seconds;
};

Time SumTime(Time t1, Time t2)
{
    int newHour = t1.hour + t2.hour;
    int newMinutes = t1.minutes + t2.minutes;
    int newSeconds = t1.seconds + t2.seconds;

    if(newSeconds >= 60)
    {
        newMinutes++;
        newSeconds -= 60;
    }
    
    if(newMinutes >= 60)
    {
        newHour++;
        newMinutes -= 60;
    }

    Time newTime = {newHour, newMinutes, newSeconds};

    return newTime;
};

Time TimeDiff (Time t1, Time t2)
{
    Time newTime;

    newTime.hour = abs(t1.hour-t2.hour);
    newTime.minutes = abs(t1.minutes-t2.minutes);
    newTime.seconds = abs(t1.seconds - t2.seconds);

    return newTime;
}

int TimeToSeconds(Time t)
{
    if (t.hour == NULL)
        t.hour = 0;

    if (t.minutes == NULL)
        return t.seconds;

    return (t.hour*60) + (t.minutes*60) + (t.seconds);
}
