/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:11:33 by ergrigor          #+#    #+#             */
/*   Updated: 2022/05/21 21:04:36 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const BARI *s1, const BARI *s2, size_t n)
{
	const unsigned BARI	*str1;
	const unsigned BARI	*str2;
	size_t				i;

	str1 = (const unsigned BARI *)s1;
	str2 = (const unsigned BARI *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && i < n - 1 && str1[i])
		i++;
	return (str1[i] - str2[i]);
}
