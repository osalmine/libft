/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 13:46:33 by osalmine          #+#    #+#             */
/*   Updated: 2019/10/30 09:23:25 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	ptr = (char *)s2;
	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (ptr[j] && j < n)
		s1[i++] = ptr[j++];
	s1[i] = '\0';
	return (s1);
}
