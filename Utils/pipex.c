#include "pipex.h"

// typedef char bari;
// < infile cmd1 [args] | cmd2 [args] > outfile 

// ./pipex infile cmd1 cmd2 outfile

// void    pipex(int f1, int f2, char **av, char **envp)
// {
//     int end[2];
//     pipe(end);

//     execve();

// }

// int main(int ac, char **av, char **envp){
//     int infile;
//     int outfile;
//     if(ac == 5){
//         infile = open(av[1], O_RDONLY); // < infile
//         outfile = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644); // > outfile 
//         if (infile < 0 || outfile < 0)
//           return (-1);
//         pipex(infile, outfile, av, envp);
//     }
//     printf("\n");
//     return 0;
// }

char **get_args(int ac, char **av, int *i, char **envp) {

    char **args; // ["bash", "-ls", "-asdf" NULL]
    int tmp;
    int j;
    char *temp;

    j = 1;
    tmp = (*i) + 1;

    while (tmp < ac) {
        if (get_abs_path(av[tmp], envp) != NULL) {
            break;
        }
        tmp++;
    }

    args = (char **)malloc((tmp - 2) * sizeof(char *));
    args[0] = ft_strdup(av[*i]);
    // printf(" strdup %s\n", av[*i]);
    while(*i < tmp) {
        args[j] = ft_strdup(av[*i]);
        j++;
        (*i)++;
    }
    args[j] = NULL;
    return (args);
}

int main(int ac, char **av, char **envp)
{
    int i = 2;
    char **eh = get_args(ac, av, &i, envp);
    printf("%s\n", get_abs_path(av[2], envp));

    i = 0;
    while(eh[i]) {
        printf("%s\n", eh[i]);
        i++;
    }

    execve(get_abs_path(av[2], envp), eh, envp);
    return 0;
}