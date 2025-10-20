/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhaled <rakhaled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:42:16 by rakhaled          #+#    #+#             */
/*   Updated: 2025/10/06 14:43:04 by rakhaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (c == '\0')
	{
		return ((char *)&s[i]);
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*ch;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[len])
	{
		len++;
	}
	ch = (char *)malloc(sizeof(char) * (len + 1));
	if (!ch)
	{
		return (NULL);
	}
	while (i < len)
	{
		ch[i] = s[i];
		i++;
	}
	ch[i] = '\0';
	return (ch);
}
