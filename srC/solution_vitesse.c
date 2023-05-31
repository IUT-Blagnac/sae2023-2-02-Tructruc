#include <stdlib.h>
#include <string.h>

typedef struct ArrayList {
    char** array;
    int size;
} ArrayList;

ArrayList** createArrayListArray(int length) {
    ArrayList** array = (ArrayList**)malloc((length + 1) * sizeof(ArrayList*));
    for (int i = 0; i < length + 1; i++) {
        array[i] = (ArrayList*)malloc(sizeof(ArrayList));
        array[i]->array = NULL;
        array[i]->size = 0;
    }
    return array;
}

void addString(ArrayList* arrayList, const char* string) {
    arrayList->size++;
    arrayList->array = (char**)realloc(arrayList->array, arrayList->size * sizeof(char*));
    arrayList->array[arrayList->size - 1] = strdup(string);
}

void destroyArrayList(ArrayList* arrayList) {
    for (int i = 0; i < arrayList->size; i++) {
        free(arrayList->array[i]);
    }
    free(arrayList->array);
    free(arrayList);
}

int getOrdreInder(char* ordre, int tailleOrdre, const char c) {
    for (int i = 0; i < tailleOrdre; i++) {
        if (ordre[i] == c)
            return i;
    }
    return tailleOrdre;
}

void solution(char** output, int tailleOutput, char* input, char* ordre, int tailleOrdre) {
    ArrayList** arrayLists = createArrayListArray(tailleOrdre+1);

    int start = 0;
    int end = 0;
    int length = strlen(input);

    while (end < length) {
        if ((input[end] < 'a' || input[end] > 'z') && (input[end] < 'A' || input[end] > 'Z')) { // si le caractère n'est pas une lettre
            if (end - start > 0) { // empèche les mots vides
                char* word = (char*)malloc((end - start + 1) * sizeof(char));
                strncpy(word, input + start, end - start); // copie le mot dans word, string + start est l'adresse du premier caractère du mot (on avance dans la chaine de caractère) et end - start est la longueur du mot
                word[end - start] = '\0'; // ajoute le caractère de fin de chaine
                addString(arrayLists[getOrdreInder(ordre, tailleOrdre, word[0])], word); // ajoute le mot à la liste
            }
            start = end + 1;
        }
        end++;
    }
    if (end - start > 0) {
        char* word = (char*)malloc((end - start + 1) * sizeof(char));
        strncpy(word, input + start, end - start);
        word[end - start] = '\0';
        addString(arrayLists[getOrdreInder(ordre, tailleOrdre, word[0])], word);
    }



    int index =0;
    for(int i = 0; i<tailleOrdre+1; i++) {
        for (int j = 0; j < arrayLists[i]->size; ++j) {
            output[index] = strdup(arrayLists[i]->array[j]);
            index++;
        }
    }


    for (int i = 0; i<tailleOrdre+1; i++)
        destroyArrayList(arrayLists[i]);

}