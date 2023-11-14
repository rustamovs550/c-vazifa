#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


int main(){
    char ch;
    int info = 0;
    int fd_in = open("example1",O_RDONLY);
    int fd_out = open("example2",O_RDONLY);
    int fd_merge = open("merge",O_WRONLY);

    

    // for(int i = 0 ;i <7;i++){
    //     read(fd ,&ch,1);
    //     if(i != 3){
    //         printf("%c\n", ch);
    //     }
    // }

    // while ((info = read(fd ,&ch,1))>0)
    // {
    //     printf("%c\n", ch);
    // }


     while ((info = read(fd_in ,&ch,1))>0)
    {
        write(fd_merge ,&ch,1);
    }

    while ((info = read(fd_out ,&ch,1))>0)
    {
                write(fd_merge ,&ch,1);

    }

    

    close(fd_in);
    close(fd_out);
    close(fd_merge);

    return 0;
}