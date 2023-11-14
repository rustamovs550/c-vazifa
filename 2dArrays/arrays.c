#include <stdio.h>

int main() {
    int massiv[4][10] =  {
        {2,-1,3},
        {20,10,3},
        {2,-1,3},
        {2,-1,3}
    };

    int massiv2[4][10] =  {
        {2,-1,3},
        {9,-10,8},
        {20,-18,30},
        {25,-12,39}
    };
    int raqam = 0;

    


    // for(int i = 0; i <3;i++){
    //     for(int k = 0;k<10;k++){
    //         if(i == 0 && raqam <11){
    //             massiv[i][k] = raqam+1;
    //             printf("%d\n", massiv[i][k]);
    //             raqam++;
    //         }else if(i == 1){
    //             massiv[i][k] = raqam;
    //             printf("%d\n", massiv[i][k]);
    //             raqam--;
    //         }else if(i == 2){
    //             if(k <5){
    //                 massiv[i][k] = raqam+1;
    //                 printf("%d\n", massiv[i][k]);
    //                 raqam++;
    //             }else if(k >1){
    //                 massiv[i][k] = raqam;
    //                 printf("%d\n", massiv[i][k]);
    //                 raqam--;
    //             }
    //         }
    //     }
    // }
    

    int natija = 0;

    //ex 02
    // int natija = 0;
    // for(int i = 0 ;i <3 ;i++){
    //     for(int u = 0 ;u <3 ;u++){
    //     natija += massiv[i][u] *massiv[i][u];
    // }
    // }
    
    // printf("%d", natija);
    

    // ex 03

    // for(int i = 0; i <3; i++){
    //     for(int o = 0; o <3;o++){
    //         if (massiv[i][o] < 0)
    //         {
    //          natija += massiv[i][o];   
    //         }
            
    //     }
    // }
    // printf("%d", natija);

    // ex 04
    // int a = 3;
    // int count = 0;
    // for (int i = 0; i < 4; i++){
    //     for (int o = 0; o < 3; o++){
    //         if (massiv[i][o] == a)
    //         {
    //             count++;
    //         }
                
    //     }    
    // }
    // printf("berilgan %d soni massivda %d marta takrorlangan", a,count);

    //ex 05




    //ex 06
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int k = 0; k < 3; k++)
    //     {
    //         if (massiv[i][k] <0)
    //         {
    //             massiv[i][k] = massiv[i][k] *massiv[i][k];
    //             printf("%d\n",massiv[i][k]);
    //         }
            
    //     }
        
    // }


    //ex 07
    int i, j;
    int minElement = massiv[0][0];
    int maxElement = massiv[0][0];

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            if (massiv[i][j] < minElement) {
                minElement = massiv[i][j];
            }
            if (massiv[i][j] > maxElement) {
                maxElement = massiv[i][j];
            }
        }
    }
    
    printf("kattasi = %d", maxElement);
    

    return 0;
}