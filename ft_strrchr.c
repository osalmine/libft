/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 14:27:39 by osalmine          #+#    #+#             */
/*   Updated: 2019/11/04 09:43:50 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *pos;

	pos = NULL;
	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	if (s)
	{
		while (*s)
		{
			if (*s == (char)c)
				pos = (char *)s;
			s++;
		}
	}
	return (pos);
}
