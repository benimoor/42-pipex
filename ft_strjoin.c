/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:09:35 by ergrigor          #+#    #+#             */
/*   Updated: 2022/05/21 21:04:18 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

BARI	*ft_strjoin(BARI const *s1, BARI const *s2)
{
	BARI	*joined_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	joined_str = (BARI *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joined_str)
		return (NULL);
	while (s1[i] != '\0')
	{
		joined_str[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		joined_str[j] = s2[i];
		j++;
		i++;
	}
	joined_str[j] = '\0';
	return (joined_str);
}
