#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    //ex 01
    // int massiv[4][4];

    // int num = 0;

    // for (int i = 0; i < 4; i++)
    // {
    //     for (int o = 0; o < 4; o++)
    //     {
    //       massiv[i] [o] = num +1;
    //       num++; 
    //     }
        
    // }
    // for (int i = 3; i >= 0; i--)
    // {
    //     for (int o = 3; o  >=0; o--)
    //     {
    //       printf("%d\n" , massiv[i][o]) ;
    //     }
        
    // }


    //ex 02
    // int massiv[3][3];

    // int qator1_y = 0;
    // int qator2_y = 0;
    // int qator3_y = 0;
    // int num = 0;

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int o = 0; o < 3; o++){
    //       if(i == 0){
    //           massiv[i][o] = num +1;
    //           printf("%d", massiv[i][o]);
    //           qator1_y +=massiv[i][o];
    //           num++;
    //       }else if(i == 1){
    //           massiv[i][o] = num +1;
    //           printf("%d", massiv[i][o]);
    //           qator2_y +=massiv[i][o];
    //           num++;
    //       }else if(i == 2){
    //           massiv[i][o] = num +1;
    //           printf("%d", massiv[i][o]);
    //           qator3_y +=massiv[i][o];
    //           num++;
    //       }  
    //     }
        
    // }
   
    
    // printf("\n1 qatordagi elementlar yig'indisi %d\n2 qatordagi elementlar yig'indisi %d\n3 qatordagi elementlar yig'indisi %d",qator1_y,qator2_y,qator3_y);

    



    //ex 03
      // srand(time(NULL));
      // int massiv[5][3];
      // int orta_qiymat = 0 ;
      // float on = 10, oo =0;
      // for (int  i = 0; i < 5; i++)
      // {
      //   for (int o = 0; o < 3; o++)
      //   {
            
      //       //srand(time(NULL));
        
      //       int randomNumber = rand() % 100;
      //       printf("massiv[%d][%d] = %d\n", i,o,randomNumber);
      //       massiv[i][o] = randomNumber;
      //       orta_qiymat += randomNumber;
      //   }
        
      // }
      
      // oo += orta_qiymat;
      // oo /= 10;

      // printf("orta qiymati = %g",oo);

    //ex 04

    int massiv[3][3];

    int num = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int o = 0; o < 3; o++)
        {
          massiv[i] [o] = num ;
          printf("%d\n",massiv[i][o]);
          num++; 
        }
        
    }
    for (int i = 0; i < 3; i++)
    {
        for (int o = 0; o < 3; o++)
        {
          if (massiv[i][o] % 2 == 0&& massiv[i][o] != 0)
          {
            massiv[i][o] =massiv[i][o]*massiv[i][o];
            printf("kvadrat : %d\n",massiv[i][o]);
          }
          
        }
        
    }


    return 0;
}