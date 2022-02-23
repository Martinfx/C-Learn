#include <stdio.h>
#include <time.h>

int main()
{
    time_t now_time;
    struct tm tm_time = {0};
    double seconds = 0;

    tm_time.tm_hour = 0;
    tm_time.tm_min = 0;
    tm_time.tm_sec = 0;
    tm_time.tm_mon = 0;
    tm_time.tm_year = 0;
    tm_time.tm_mday = 1;


    time(&now_time);
    seconds = difftime(now_time, mktime(&tm_time));


    printf("current time: %s", ctime(&now_time));
    printf("difftime: %f", seconds);


    return 0;
}
