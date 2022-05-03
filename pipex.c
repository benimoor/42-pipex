#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void    pipex(int f1, int f2, char **av)
{
    int end[2];

    pipe(end);  
}

int main(int ac, char **av){
    int file1;
    int file2;
    if(ac == 5){
        file1 = open(av[1], O_RDONLY);
        file2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
        if (file1 < 0 || file2 < 0)
          return (-1);
        pipex(file1, file2, av);
    }
    printf("\n");
    return 0;
}