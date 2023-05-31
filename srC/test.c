#include <stdio.h>
#include "solution.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>


int main(int argc, char *argv[]) {


    int option;
    int nbMots;
    char *input;

    // Process command-line arguments using getopt
    while ((option = getopt(argc, argv, "c:t:")) != -1) {
        switch (option) {
            case 'c':
                nbMots = atoi(optarg);  // Convert string to integer
                break;
            case 't':
                input = optarg;
                break;
            default:
                nbMots =  8;
                input = "Il fait beau aujourd’hui comme en aout";
        }
    }

    if (nbMots == 0 || input == NULL){
        nbMots =  8;
        input = "Il fait beau aujourd’hui comme en aout";
    }


    int tailleOrdre =  26;
    char ordre[] =  {'f', 'I', 'z', 'u', 'k', 'a', 'b', 'o', 'c', 'd', 'e', 'g', 'h', 'i', 'j', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y'};
    char* result[nbMots];

    struct timespec begin, end;
    clock_gettime(CLOCK_REALTIME, &begin);

    solution(result, nbMots, input, ordre, tailleOrdre);
    clock_gettime(CLOCK_REALTIME, &end);
    printf("Word count = %d\n", nbMots);
    printf("Input string lenght = %ld\n", strlen(input));

    long nanoseconds = end.tv_nsec - begin.tv_nsec;
    printf("Time taken: %ld nanoseconds\n", nanoseconds);
    printf("Time per word: %ld nanoseconds\n", nanoseconds/nbMots);
    //for (int i=0; i<nbMots-1;i++)
    //printf("%s ",result[i]);
}