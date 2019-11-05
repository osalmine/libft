/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 13:49:53 by osalmine          #+#    #+#             */
/*   Updated: 2019/10/30 09:37:26 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src,
		size_t dstsize)
{
	size_t i;
	size_t j;
	size_t res;

	res = 0;
	i = 0;
	while (dst[i])
		i++;
	while (src[res])
		res++;
	if (i >= dstsize)
		res += dstsize;
	else
		res += i;
	j = 0;
	while (src[j] && i + 1 < dstsize)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (res);
}
