#include <stdio.h>
#include <string.h>
#include <stdlib.h>




char*satrni_tartiblash_algaritimi(char* satr){
    char*saralangan_satr =(char *)malloc(strlen(satr) -1),temp;
    saralangan_satr = strdup(saralangan_satr);

    for (int i = 0,satr_uzunligi = strlen(satr); i < satr_uzunligi; i++) {
        for (int j = 0; j <satr_uzunligi; j++) {
            if (saralangan_satr[i] < saralangan_satr[j]) {
                temp = saralangan_satr[i];
                saralangan_satr[i] = saralangan_satr[j];
                saralangan_satr[j] = temp;
            }
        }
    }
    return saralangan_satr;
}



int main(/*int argc, char **argv*/){
    
    char matnlar[] = "sdjkhjhjhjhsjhdfjghfjhgjfhkfjhfjh";
    char *matnlari = satrni_tartiblash_algaritimi(matnlar);
    printf("%s",matnlar);


    return 0;
}