#include <stdlib.h>
#include <string.h>


int getOrdreInder(char* ordre, int tailleOrdre, const char c) {
    for (int i = 0; i < tailleOrdre; i++) {
        if (ordre[i] == c)
            return i;
    }
    return tailleOrdre;
}

void solution(char** output, int tailleOutput, char* input, char* ordre, int tailleOrdre) {
    char*** arrayLists = (char***)malloc((tailleOrdre + 1) * sizeof(char*));
    int* word_count = (int*)malloc((tailleOrdre + 1) * sizeof(int));
    for (int i = 0; i < tailleOrdre + 1; i++) {
        arrayLists[i] = (char**)malloc(sizeof(char)*tailleOutput);
    }

    int start = 0;
    int end = 0;
    int length = strlen(input);

    while (end < length) {
        if ((input[end] < 'a' || input[end] > 'z') && (input[end] < 'A' || input[end] > 'Z')) { // si le caractère n'est pas une lettre
            if (end - start > 0) { // empèche les mots vides
                char* word = (char*)malloc((end - start + 1) * sizeof(char));
                strncpy(word, input + start, end - start); // copie le mot dans word, string + start est l'adresse du premier caractère du mot (on avance dans la chaine de caractère) et end - start est la longueur du mot
                word[end - start] = '\0'; // ajoute le caractère de fin de chaine
                word_count[getOrdreInder(ordre, tailleOrdre, word[0])]++;
                arrayLists[getOrdreInder(ordre, tailleOrdre, word[0])][word_count[getOrdreInder(ordre, tailleOrdre, word[0])]] = word; // ajoute le mot à la liste
            }
            start = end + 1;
        }
        end++;
    }
    if (end - start > 0) {
        char* word = (char*)malloc((end - start + 1) * sizeof(char));
        strncpy(word, input + start, end - start);
        word[end - start] = '\0';
        word_count[getOrdreInder(ordre, tailleOrdre, word[0])]++;
        arrayLists[getOrdreInder(ordre, tailleOrdre, word[0])][word_count[getOrdreInder(ordre, tailleOrdre, word[0])]] = word; // ajoute le mot à la liste
    }



    int index =0;
    for (int i = 0; i < tailleOrdre + 1; i++) {
        for (int j = 0; j < word_count[i]; j++) {
            output[index] = arrayLists[i][j];
            index++;
        }
    }

}