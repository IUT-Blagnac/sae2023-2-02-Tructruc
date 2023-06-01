#include <stdlib.h>
#include <string.h>

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
    char*** arrayLists = (char***)malloc((tailleOrdre + 1) * sizeof(char*));
    for (int i = 0; i < tailleOrdre + 1; i++) {
        arrayLists[i] = (char**)malloc(sizeof(char*)*tailleOutput);
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
                char* word = (char*)malloc((end - start + 1) * sizeof(char));

                // copie le mot dans word, string + start est l'adresse du premier caractère du mot (on avance dans la chaine de caractère) et end - start est la longueur du mot
                strncpy(word, input + start, end - start);

                // ajoute le caractère de fin de chaine
                word[end - start] = '\0';

                // ajoute le mot à la liste correspondante
                arrayLists[ordrePreprocessed[word[0]]][word_count[ordrePreprocessed[word[0]]]] = word;
                word_count[ordrePreprocessed[word[0]]]++;
            }
            start = end + 1;
        }
        end++;
    }
    // ajoute le dernier mot (si il n’est pas vide)
    if (end - start > 0) {
        char* word = (char*)malloc((end - start + 1) * sizeof(char));

        // copie le mot dans word, string + start est l'adresse du premier caractère du mot (on avance dans la chaine de caractère) et end - start est la longueur du mot
        strncpy(word, input + start, end - start);

        // ajoute le caractère de fin de chaine
        word[end - start] = '\0';

        // ajoute le mot à la liste correspondante
        arrayLists[ordrePreprocessed[word[0]]][word_count[ordrePreprocessed[word[0]]]] = word; // ajoute le mot à la liste
        word_count[ordrePreprocessed[word[0]]]++;
    }

    // Ajoute les mots dans l'ordre dans le tableau de sortie
    int index = 0;
    for (int i = 0; i < tailleOrdre + 1; i++) {
        for (int j = 0; j < word_count[i]; j++) {

            output[index] = arrayLists[i][j];
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