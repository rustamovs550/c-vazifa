#include <stdio.h>
#include <unistd.h>

int main(){
    char tmp[100];
    char c;
    int flag = 1;
    int i = 0;

    while (( flag = read(0,&c,1)) >0)
    {
        if (c == '\n')
        {
            break;
        }

        tmp[i++] = c;
        
    }
    tmp[i] = '\0';
    if (flag == 0) return 0;
    
    
    printf("%s",tmp); 

    return 0;

}
