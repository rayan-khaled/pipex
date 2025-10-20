/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhaled <rakhaled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:13:00 by rakhaled          #+#    #+#             */
/*   Updated: 2025/10/03 18:51:11 by rakhaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	word_count(char *s, char c)
{
	int	count;
	int	in;

	count = 0;
	in = 0;
	while (*s)
	{
		if (*s != c && !in)
		{
			in = 1;
			count++;
		}
		else if (*s == c)
			in = 0;
		s++;
	}
	return (count);
}

int	word_len(char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

int	fill(char **result, const char *s, char c, int words)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (i < words)
	{
		while (s[j] == c)
			j++;
		len = word_len((char *)&s[j], c);
		result[i] = ft_substr(s, j, len);
		if (!result[i])
		{
			free_arr(result);
			return (0);
		}
		j += len;
		i++;
	}
	result[words] = NULL;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		words;

	if (!s)
		return (NULL);
	words = word_count((char *)s, c);
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	if (!fill(result, s, c, words))
		return (NULL);
	return (result);
}
