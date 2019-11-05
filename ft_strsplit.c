/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:27:09 by osalmine          #+#    #+#             */
/*   Updated: 2019/11/04 13:08:46 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int		i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**arr;

	j = 0;
	i = 0;
	if (!s || (!(arr = (char **)malloc(sizeof(char *) * (ft_words(s, c) + 1)))))
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s && *s != c)
		{
			if (!(arr[j] = (char *)malloc(sizeof(char) * ft_count(s, c) + 1)))
				return (NULL);
			while (*s != c && *s)
				arr[j][i++] = (char)*s++;
			arr[j][i] = '\0';
			j++;
			i = 0;
		}
	}
	arr[j] = NULL;
	return (arr);
}
