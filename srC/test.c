#include <stdio.h>
#include "solution.h"
#include <time.h>


int main() {
    int tailleOrdre =  7;
    int nbMots =  8;
    char ordre[] =  {'f', 'I', 'z', 'u', 'k', 'a', 'b', 'o'};
    char input[] = "Il fait beau aujourd’hui comme en aout";
    char* result[nbMots];

    struct timespec begin, end;
    clock_gettime(CLOCK_REALTIME, &begin);

    solution(result, nbMots, input, ordre, tailleOrdre);
    clock_gettime(CLOCK_REALTIME, &end);
    long nanoseconds = end.tv_nsec - begin.tv_nsec;
    printf("Time taken: %ld nanoseconds\n", nanoseconds);
    for (int i=0; i<nbMots-1;i++)
    printf("%s\n",result[i]);
}