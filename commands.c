/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:15:47 by ergrigor          #+#    #+#             */
/*   Updated: 2022/05/21 21:01:21 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_command(t_pipex pipex, BARI **argv, BARI **envp)
{
	dup2(pipex.fd[1], 1);
	close(pipex.fd[0]);
	dup2(pipex.infile, 0);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd = get_abs_path(pipex.cmd_paths, pipex.cmd_args[0]);
	if (pipex.cmd == NULL)
	{
		free_child(&pipex);
		err_msg("Command not found\n");
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

void	second_command(t_pipex pipex, BARI **argv, BARI **envp)
{
	dup2(pipex.outfile, 1);
	close(pipex.fd[1]);
	dup2(pipex.fd[0], 0);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd = get_abs_path(pipex.cmd_paths, pipex.cmd_args[0]);
	if (pipex.cmd == NULL)
	{
		free_child(&pipex);
		err_msg("Command not found\n");
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}
