/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:03:46 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/24 13:20:29 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbs(unsigned int nb)
{
	unsigned int size;

	size = 1;
	while (nb >= 10)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}

int	ft_nbs_base(size_t nb, size_t base)
{
	int size;

	size = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= base;
		size++;
	}
	return (size);
}

int	ft_nbs_base_ll(long long nb, long long base)
{
	int size;

	size = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= base;
		size++;
	}
	return (size);
}
