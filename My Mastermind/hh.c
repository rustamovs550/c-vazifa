// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
// #include "functions.h"






void togri_va_notogri_joylar(char* taxminiy_kod,char* togri_kod , int* togri_joylar,int*xato_joylar ){
        int taxminiy_toplam[10] = {0} , togri_toplam[10] = {0};

        *togri_joylar=0; 
        *xato_joylar =0;


        int o ;
        while(o < 4){
            if(taxminiy_kod[o] == togri_kod[o]){
                *togri_joylar +=1;
            }
            else {
                togri_toplam[togri_kod[o] - '0']++;
                taxminiy_toplam[taxminiy_kod[o] - '0']++;
            }
            o++;
        }
        int y ;
        while(y < 4){
            if(taxminiy_toplam[y] > togri_toplam[y]){
                *xato_joylar += togri_toplam[y];
            }
            else {
                *xato_joylar += taxminiy_toplam[y];
            }
            y++;
        }


}
int main() {
    srand(time(NULL));  // Rastgelelik için zamanı kullanarak tohumlama yapılır

    char secret_code[5] = {'1', '2', '3', '4', '\0'};  // Gizli kod
    char guess[5];  // Tahmin edilen kod
    int correct_places = 0;  // Doğru yerdeki rakam sayısı
    int incorrect_places = 0;  // Yanlış yerdeki rakam sayısı

    printf("Kodunuzu tahmin edin (4 rakam girin):\n");
    scanf("%4s", guess);  // Kullanıcıdan kodu al

    togri_va_notogri_joylar(guess, secret_code, &correct_places, &incorrect_places);

    printf("togri joyları: %d\n", correct_places);
    printf("xato orinlarsı: %d\n", incorrect_places);

    return 0;
}