#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

void birinchi_Elementni_qirqish(char* massiv[], int* uzunlik) {
    for (int i = 0; i < *uzunlik - 1; i++) {
        massiv[i] = massiv[i + 1];
    }
    (*uzunlik)--;
}

bool harf_massivni_ichida_bormi(char qidirilyotgan_qiymat, char* massiv) {
    int massiv_uzunligi = strlen(massiv);
    for (int i = 0; i < massiv_uzunligi; i++) {
        if (massiv[i] == qidirilyotgan_qiymat) {
            return true;
        }
    }
    return false;
}


int harf_massivni_ichida_necha_marta_takrorlangan(char qidirilyotgan_qiymat, char* massiv) {
    int qiymat = 0;
    int massiv_uzunligi = strlen(massiv);
    for (int i = 0; i < massiv_uzunligi; i++) {
        if (massiv[i] == qidirilyotgan_qiymat) {
            qiymat += 1;
        }
    }
    return qiymat;
}




char* satrlarni_boglash(char *oraliq, char *satrlar_royxati[], int satrlar_raqami) {
    size_t umumiy_uzunlik = 0;
    for (int i = 0; i < satrlar_raqami; i++) {
        umumiy_uzunlik += strlen(satrlar_royxati[i]);
    }
    char* natija = (char *)malloc((umumiy_uzunlik + satrlar_raqami) * sizeof(char));
    memset(natija, 0, umumiy_uzunlik + satrlar_raqami);

    for (int i = 0; i < satrlar_raqami; i++) {
        if (i != 0) {
            strcat(natija, oraliq);
        }
        strcat(natija, satrlar_royxati[i]);
    }
    return natija;
}


int main(int ac, char **av){
    birinchi_Elementni_qirqish(av, &ac);
    char* joinedString = satrlarni_boglash("", av, ac);


    int satr_uzunligi = strlen(joinedString), i, j;
    for (i = 0; i < satr_uzunligi; i++) {
        for (j = 0; j < satr_uzunligi - i - 1; j++) {
            if (joinedString[j] > joinedString[j + 1]) {
                char temp = joinedString[j];
                joinedString[j] = joinedString[j + 1];
                joinedString[j + 1] = temp;
            }
        }
    }

    int matn_uzunligi = strlen(joinedString);
    char *massiv_harflari = (char *)malloc((matn_uzunligi + 1) * sizeof(char));
    memset(massiv_harflari, 0, matn_uzunligi + 1);

    int harfning_harflar_massividagi_indeksi = 0;
    for (int i = 0; i < matn_uzunligi; i++) {
        if (!harf_massivni_ichida_bormi(joinedString[i], massiv_harflari)) {
            massiv_harflari[harfning_harflar_massividagi_indeksi] = joinedString[i];
            int qiymatlar = harf_massivni_ichida_necha_marta_takrorlangan(joinedString[i], joinedString);
            if (qiymatlar > 0) {
                printf("%c:%d\n", joinedString[i], qiymatlar);
                harfning_harflar_massividagi_indeksi += 1;
            }
        }
    }

    free(massiv_harflari);
    free(joinedString);
    
    return 0;
}