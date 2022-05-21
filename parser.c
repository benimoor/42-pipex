/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:59:56 by ergrigor          #+#    #+#             */
/*   Updated: 2022/05/21 21:04:47 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

BARI	*get_paths(BARI **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

BARI	*get_abs_path(BARI **paths, BARI *cmd)
{
	int		i;
	BARI	*temp;

	i = 0;
	if (access(cmd, X_OK | R_OK) == 0)
		return (cmd);
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		temp = ft_strjoin(temp, cmd);
		if (access(temp, X_OK | R_OK) == 0)
			return (temp);
		free (temp);
		i++;
	}
	return (NULL);
}
