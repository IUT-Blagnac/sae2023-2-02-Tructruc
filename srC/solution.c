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


void split(ArrayList* arrayList, const char* string, const char* delimiter) {
    char* stringCopy = strdup(string);
    char* token = strtok(stringCopy, delimiter);
    while (token != NULL) {
        addString(arrayList, token);
        token = strtok(NULL, delimiter);
    }
    free(stringCopy);
}


void solution(char** output, int tailleOutput, char* input, char* ordre, int tailleOrdre) {
    ArrayList** arrayLists = createArrayListArray(tailleOrdre+1);

    ArrayList* splitedInput = (ArrayList*)malloc(sizeof(ArrayList));

    split(splitedInput, input, " ");


    ArrayList* notFound = (ArrayList*)malloc(sizeof(ArrayList));
    int found;
    for(int i = 0; i < splitedInput->size; i++) {
        found = 0;
        for (int j = 0; j < tailleOrdre; ++j) {
            if (splitedInput->array[i][0]==ordre[j]) {
                addString(arrayLists[j], splitedInput->array[i]);
                found = 1;
                break;
            }
        }
        if (!found) {
            addString(notFound, splitedInput->array[i]);
        }
    }


    int index =0;
    for(int i = 0; i<tailleOrdre; i++) {
        for (int j = 0; j < arrayLists[i]->size; ++j) {
            output[index] = strdup(arrayLists[i]->array[j]);
            index++;
        }
    }
    for (int i = 0; i < notFound->size;i++){
        output[index] = strdup(notFound->array[i]);
        index++;
    }



    destroyArrayList(splitedInput);
    destroyArrayList(notFound);
    for (int i = 0; i<tailleOrdre+1; i++)
        destroyArrayList(arrayLists[i]);

}