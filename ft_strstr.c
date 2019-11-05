/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:50:50 by osalmine          #+#    #+#             */
/*   Updated: 2019/11/05 08:29:36 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	n_len;
	char	*ptr_h;

	n_len = ft_strlen(needle);
	ptr_h = (char *)haystack;
	if (!*needle)
		return ((char *)haystack);
	while (*ptr_h)
	{
		if (*ptr_h == *needle)
		{
			if (ft_strncmp(needle, ptr_h, n_len) == 0)
				return (ptr_h);
		}
		ptr_h++;
	}
	return (NULL);
}
