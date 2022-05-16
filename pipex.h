/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:45:32 by ergrigor          #+#    #+#             */
/*   Updated: 2022/05/16 14:30:15 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct pipex_s
{
	pid_t	pid1;
	pid_t	pid2;
	int		infile;
	int		outfile;
	int		fd[2];
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}	t_pipex;

size_t	ft_strlen(const char *str);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_abs_path(char **paths, char *cmd);
char	*get_paths(char **envp);
void	first_command(t_pipex pipex, char **argv, char **envp);
void	second_command(t_pipex pipex, char **argv, char **envp);
void	free_parent(t_pipex *pipex);
void	free_child(t_pipex *pipex);
void	close_pipes(t_pipex *pipex);
void	err_msg(char *err);

#endif