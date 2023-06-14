#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Prétraite l'ordre pour éviter de faire une boucle à chaque fois
 * @param ordre  ordre à prétraiter
 * @param tailleOrdre taille de l'ordre
 * @return tableau de taille 128, avec pour chaque caractère, sa position dans l'ordre (si il n'est pas dans l'ordre, on met a la taille maximale)
 */
int* preprocessOrdre(char* ordre, int tailleOrdre){
    int* ordrePreprocess = (int*)malloc(sizeof(int)*128);

    for (int i = 0; i < 128; i++) {
        ordrePreprocess[i] = tailleOrdre;
    }
    for (int i = 0; i < tailleOrdre; i++) {
        ordrePreprocess[ordre[i]] = i;
    }

    return ordrePreprocess;
}

void solution(char** output, int tailleOutput, char* input, char* ordre, int tailleOrdre) {
    // Initialisation de la liste de listes de mots
    int** arrayLists = (int**)malloc((tailleOrdre + 1) * sizeof(int*));
    for (int i = 0; i < tailleOrdre + 1; i++) {
        arrayLists[i] = (int*)malloc(sizeof(int)*tailleOutput*2);
    }
    int* word_count = (int*)calloc((tailleOrdre + 1), sizeof(int)); // Nombre de mots par liste

    // Prétraitement de l'ordre, pour éviter de faire une boucle à chaque fois
    int* ordrePreprocessed = preprocessOrdre(ordre, tailleOrdre);

    // Initialisation des variables de parcours de la chaine de caractères
    int start = 0;
    int end = 0;
    int length = strlen(input);

    while (end < length) {
        // si le caractère n'est pas une lettre
         if ((input[end] < 'a' || input[end] > 'z') && (input[end] < 'A' || input[end] > 'Z') && (input[end] < '0' || input[end] > '9')) {
            if (end - start > 0) { // empèche les mots vides

                // ajoute le mot à la liste correspondante
                arrayLists[ordrePreprocessed[input[start]]][word_count[ordrePreprocessed[input[start]]]*2] = start; // ajoute l'adresse du premier caractère du mot à la liste
                arrayLists[ordrePreprocessed[input[start]]][word_count[ordrePreprocessed[input[start]]]*2+1] = end ; // ajoute la longueur du mot à la liste
                word_count[ordrePreprocessed[input[start]]]++;
            }
            start = end + 1;
        }
        end++;
    }
    // ajoute le dernier mot (si il n’est pas vide)
    if (end - start > 0) {
        arrayLists[ordrePreprocessed[input[start]]][word_count[ordrePreprocessed[input[start]]]*2] = start; // ajoute l'adresse du premier caractère du mot à la liste
        arrayLists[ordrePreprocessed[input[start]]][word_count[ordrePreprocessed[input[start]]]*2+1] = end ; // ajoute la longueur du mot à la liste
        word_count[ordrePreprocessed[input[start]]]++;
    }

    // Ajoute les mots dans l'ordre dans le tableau de sortie
    int index = 0;
    for (int i = 0; i < tailleOrdre + 1; i++) {
        for (int j = 0; j < word_count[i]; j++) {
            output[index] = (char*)malloc(sizeof(char)*(arrayLists[i][j*2+1] - arrayLists[i][j*2] +1));

            strncpy(output[index], input + arrayLists[i][j*2], arrayLists[i][j*2+1] - arrayLists[i][j*2]);

            output[index][arrayLists[i][j*2+1] - arrayLists[i][j*2]] = '\0';

            index++;
        }
    }

    // Libère la mémoire
    for (int i = 0; i < tailleOrdre + 1; i++) {
        free(arrayLists[i]);
    }
    free(arrayLists);
    free(word_count);
    free(ordrePreprocessed);

}