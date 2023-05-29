#include <stdio.h>
#include "solution.h"
int main() {
   char test[] =  {'a','J','C'};
   int tailleTest = 2;
   char* result[tailleTest];
   solution(result, tailleTest, "Coucou JMB", test, 3);
   for (int i=0; i<tailleTest;i++)
    printf("%s\n",result[i]);
}