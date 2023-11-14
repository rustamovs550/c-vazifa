#include <stdio.h>
#include <stdlib.h>

void swap(int* num1 , int* num2){
    // printf("num1 = %d\n num2 = %d" , &num1,&num2);
    // int temp = *num1;
    // *num1 = *num2;
    // *num2 = temp;
    // printf("num1 = %d\n num2 = %d" ,&num1,&num2);

}

int main(){
    // int* num1 = 10;
    // int* num2 = 20;
    // swap(num1,num2);
    int massiv[10];
    int o = 0;
    for ( int i = 0; i < sizeof(massiv); i++)
    {
        massiv[i] = o;
        printf("%d" ,o);
        o++;
    }
    

    return 0;
}