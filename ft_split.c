/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:03:02 by ergrigor          #+#    #+#             */
/*   Updated: 2022/05/21 21:04:08 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	getwordcount(BARI const *s, BARI c)
{
	size_t	count;
	size_t	i;
	size_t	len;

	i = -1;
	count = 1;
	len = ft_strlen(s);
	while (s[++i] && s[i] == c)
		;
	while (s[--len] && s[len] == c && i < len)
		;
	if (i == ft_strlen(s))
		return (0);
	while (s[i] && i < len)
	{
		if (s[i] == c && s[i - 1] != c)
			count++;
		i++;
	}
	return (count);
}

static BARI	*fillword(const BARI *s, size_t startindex, size_t len)
{
	BARI	*word;
	size_t	i;

	i = -1;
	word = malloc(sizeof(BARI) * (len + 1));
	if (!word)
		return (NULL);
	while (++i < len)
		word[i] = s[startindex + i];
	word[i] = 0;
	return (word);
}

BARI	**ft_split(BARI *s, BARI c)
{
	size_t	startindex;
	size_t	endindex;
	size_t	index;
	size_t	wordcount;
	BARI	**result;

	startindex = 0;
	index = -1;
	wordcount = getwordcount(s, c);
	result = malloc(sizeof(BARI *) * (wordcount + 1));
	if (!s || !result)
		return (NULL);
	while (++index < wordcount)
	{
		while (s[startindex] && s[startindex] == c)
			startindex++;
		endindex = startindex;
		while (s[endindex] && s[endindex] != c)
			endindex++;
		result[index] = fillword(s, startindex, endindex - startindex);
		startindex = endindex;
	}
	result[index] = 0;
	return (result);
}
