/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:37:20 by osalmine          #+#    #+#             */
/*   Updated: 2019/11/04 14:24:13 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ptr;

	ptr = NULL;
	if (size)
	{
		if (!(ptr = malloc(size)))
			return (NULL);
		ft_bzero(ptr, size);
	}
	return (ptr);
}
