/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:00:39 by osalmine          #+#    #+#             */
/*   Updated: 2019/11/01 11:04:40 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ptr_h;
	size_t	i;
	size_t	n_len;
	size_t	ch_left;

	n_len = ft_strlen(needle);
	ptr_h = (char *)haystack;
	i = 0;
	ch_left = len;
	if (!*needle)
		return ((char*)haystack);
	while (*ptr_h && ch_left >= n_len)
	{
		if (*ptr_h == *needle)
		{
			if (ft_strncmp(needle, ptr_h, n_len) == 0)
				return (ptr_h);
		}
		i++;
		ptr_h++;
		ch_left--;
	}
	return (0);
}
