#include <stdio.h>
#include "2-efficacite-meilleur.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>


int main(int argc, char *argv[]) {
    int option;
    int nbMots;
    int tailleOrdre;


    // TEST 1

    char *input1 = "666, the number of the beast";
    nbMots =  6;
    char ordre1[] = {'6', 't', 'n', 'o', 'b'};
    char* result1[nbMots];
    tailleOrdre =  5;

    solution(result1,nbMots, input1, ordre1, tailleOrdre);
    char* expected[] = {"666", "the", "the", "number", "of", "beast"};
    for (int i=0; i<nbMots-1;i++) {
        if (strcmp(result1[i], expected[i]) != 0) {
            printf("\033[31mErreur: %s != %s\n\033[0m", result1[i], expected[i]);
            return 1;
        }
    }
    printf("\033[32mTest 1: OK\n\033[0m");

    // TEST 2
    char *input2 = "Il fait beau aujourd’hui comme en aout";
    nbMots =  8;
    char ordre2[] =  {'f', 'I', 'z', 'u', 'k', 'a', 'b', 'o'};
    char* result2[nbMots];
    tailleOrdre =  8;

    solution(result2,nbMots, input2, ordre2, tailleOrdre);
    char* expected2[] = {"fait", "Il", "aujourd", "aout", "beau", "hui","comme", "en", ""};
    for (int i=0; i<nbMots-1;i++) {
        if (strcmp(result2[i], expected2[i]) != 0) {

            printf("\033[31mErreur: %s != %s\n\033[0m", result2[i], expected2[i]);
            for (int j=0; j<nbMots-1;j++) {
                printf("%s ", result2[j]);
            }
            printf("\n");
            return 1;
        }
    }
    printf("\033[32mTest 2: OK\n\033[0m");



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
                nbMots =  100;
                input = "rockets floweret suits reentrance nankins robotizing sulfur wedgies earthen potiches canyon subclaim helotage polliwog knobbed nucleoids postilion flambe sasin lysine touchwood handsets camouflagic valances mutants myologists pans victim pupfishes soberest twined odometer isallobar figurine southeasters ochre misdevelop chopsockies duumvir throatily bricked cinch sinkers hypnogogic musette squirrelly effendi sostenutos dunams dory umbilicals laughable maxims acclaimed saturniid unharnessed acetaldehyde comparableness friskier thornily majuscules paid cowboyed singers nestles aliya fabler scrolling blowpipe pipelining monomaniacal ken deaerated lucidity engorge bethorns refeeding unreflective harpooner oorali rerisen shtickier metaplasm averaged aerosolization algometer narcotically rimmers vitiating dolabrate heliotropism missenses shadowless mesenteron giving urination mendigos heptameters fraises toluol";
        }
    }

    if (nbMots == 0 || input == NULL){
        nbMots =  100;
        input = "rockets floweret suits reentrance nankins robotizing sulfur wedgies earthen potiches canyon subclaim helotage polliwog knobbed nucleoids postilion flambe sasin lysine touchwood handsets camouflagic valances mutants myologists pans victim pupfishes soberest twined odometer isallobar figurine southeasters ochre misdevelop chopsockies duumvir throatily bricked cinch sinkers hypnogogic musette squirrelly effendi sostenutos dunams dory umbilicals laughable maxims acclaimed saturniid unharnessed acetaldehyde comparableness friskier thornily majuscules paid cowboyed singers nestles aliya fabler scrolling blowpipe pipelining monomaniacal ken deaerated lucidity engorge bethorns refeeding unreflective harpooner oorali rerisen shtickier metaplasm averaged aerosolization algometer narcotically rimmers vitiating dolabrate heliotropism missenses shadowless mesenteron giving urination mendigos heptameters fraises toluol";
    }


    tailleOrdre =  26;
    char ordre[] =  {'f', 'I', 'z', 'u', 'k', 'a', 'b', 'o', 'c', 'd', 'e', 'g', 'h', 'i', 'j', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y'};
    char* result[nbMots];




    // Speed test
    struct timespec begin, end;
    clock_gettime(CLOCK_REALTIME, &begin);

    solution(result, nbMots, input, ordre, tailleOrdre);
    clock_gettime(CLOCK_REALTIME, &end);

    printf("\nTest de Vitesse\n");
    printf("Word count = %d\n", nbMots);
    printf("Input string lenght = %ld\n", strlen(input));

    long nanoseconds = end.tv_nsec - begin.tv_nsec;
    printf("Time taken: %ld nanoseconds\n", nanoseconds);
    printf("Time per word: %ld nanoseconds\n", nanoseconds/nbMots);
    //for (int i=0; i<nbMots-1;i++)
    //printf("%s ",result[i]);
}