#include "benchmark.h"
#include <stdio.h>
#include <string.h>


void benchmark_start(benchmark_t* b, const char* name)
{
    strncpy(b->name, name, (BENCHMAKR_MAX_STRING_LENGTH-1));
    b->name[(BENCHMAKR_MAX_STRING_LENGTH-1)]='\0';
    b->start = millis();
}

void benchmark_stop(benchmark_t* b)
{
    b->stop = millis();
}

void benchmark_tostr(benchmark_t* b, char* str)
{
    char tmp[16];

    strcpy(str, "benchmark: ");
    strcat(str, b->name);
    strcat(str, " ");
    sprintf(tmp, "%u", b->stop - b->start);
    //itoa(b->stop - b->start, tmp, 10);
    strcat(str, tmp);
    strcat(str, " ms\r\n");
}