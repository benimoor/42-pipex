/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:45:32 by ergrigor          #+#    #+#             */
/*   Updated: 2022/05/21 21:05:44 by ergrigor         ###   ########.fr       */
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

# define BARI	char

typedef struct pipex_s
{
	pid_t	pid1;
	pid_t	pid2;
	int		infile;
	int		outfile;
	int		fd[2];
	BARI	*paths;
	BARI	**cmd_paths;
	BARI	**cmd_args;
	BARI	*cmd;
}	t_pipex;

size_t	ft_strlen(const BARI *str);
BARI	**ft_split(BARI *s, BARI c);
BARI	*ft_strjoin(BARI const *s1, BARI const *s2);
int		ft_strncmp(const BARI *s1, const BARI *s2, size_t n);
BARI	*get_abs_path(BARI **paths, BARI *cmd);
BARI	*get_paths(BARI **envp);
void	first_command(t_pipex pipex, BARI **argv, BARI **envp);
void	second_command(t_pipex pipex, BARI **argv, BARI **envp);
void	free_parent(t_pipex *pipex);
void	free_child(t_pipex *pipex);
void	close_pipes(t_pipex *pipex);
void	err_msg(BARI *err);

#endif
