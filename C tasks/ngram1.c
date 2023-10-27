#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
 

char *satrni_tartiblash_algaritimi(char *satr){
    char *saralangan_satr =(char *)malloc(strlen(satr) - 1),temp;
    saralangan_satr = strdup(satr);
     
 
    for (int i = 0,satr_uzunligi = strlen(satr); i < satr_uzunligi; i++){
        for (int j = 0; j < satr_uzunligi; j++){
            if (saralangan_satr[i] < saralangan_satr[j]){
                temp = saralangan_satr[i];
                saralangan_satr[i] = saralangan_satr[j];
                saralangan_satr[j] = temp;
            }
        }
    }
 
    return saralangan_satr;
}
// char* join(char *between, char *listStrings[], int numberStrings) {
//     size_t totalSize = 0;
//     for (int i = 0; i < numberStrings; i++) {
//         totalSize += strlen(listStrings[i]);
//     }
//     char* result = (char *)malloc((totalSize + numberStrings) * sizeof(char));
//     memset(result, 0, totalSize + numberStrings);

//     for (int i = 0; i < numberStrings; i++) {
//         if (i != 0) {
//             strcat(result, between);
//         }
//         strcat(result, listStrings[i]);
//     }
//     return result;
// }
 
int main(int argc, char **argv){
    
    if (argc == 1){
    }
    int i = 1 , j = 1;
    size_t umumiy_olcham = 0;
 
    while (1){
        if (argv[i] == NULL) {
            break;
        }
        umumiy_olcham = umumiy_olcham + strlen(argv[i]);
        i++;
    }
    char *soz = malloc(umumiy_olcham);
    while (1){
        if (argv[j] == NULL) {
            break;
        }
        strcat(soz, argv[j]);
        j++;
    }
    
    char * yangi_satr = satrni_tartiblash_algaritimi(soz);
    int element_soni = 0,matn_uzunligi = strlen(yangi_satr);
    char *saralangan_Matn = (char*)malloc(strlen(yangi_satr));
    for (int i = 0; i<matn_uzunligi; i++) {
        for (int j = 0; j < matn_uzunligi; j++) {
            if (strchr(saralangan_Matn, yangi_satr[i]) == NULL && (yangi_satr[i] == yangi_satr[j])) {
                element_soni++;    
            }
        }
        if(strchr(saralangan_Matn, yangi_satr[i]) == NULL){
            printf("%c:%d\n",yangi_satr[i],element_soni);
            element_soni =0;
        }
        saralangan_Matn[i] = yangi_satr[i];
    }
 
    return 0;
}