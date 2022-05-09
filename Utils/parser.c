#include "pipex.h"

// execve("/bin/bash", ["bash", "-ls", "-asdf" NULL], envp);

int get_path(char **envp, char *cmd)
{
    int i = -1;
    while(envp[++i])
        if(ft_strncmp(envp[i], cmd, ft_strlen(cmd)) == 0)
            return (i);
    return (-1);
}

static void free_paths(char **paths)
{
    int i;
 
    i = 0;
    while (paths[i])
        free(paths[i++]);
    free(paths);
}

char *get_abs_path(char *cmd, char **envp)
{
    char *abs_path;
    char *reserv;
    char **paths;
    int i;
    int flag;

    paths = ft_split(envp[get_path(envp, "PATH=")], ':');
    i = 0;
    while (paths[i]) {

        reserv = ft_strjoin(paths[i], "/");
        abs_path = ft_strjoin(reserv, cmd);
        free(reserv);

        if((access(abs_path, X_OK)) == 0) {
            //printf("abs_path = %s\n", abs_path);
            free_paths(paths);
            return (abs_path);
        }
        i++;
        free(abs_path);
    }
    free_paths(paths);
    return (NULL);
}
