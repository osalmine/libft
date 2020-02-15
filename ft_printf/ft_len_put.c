/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 11:28:55 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/24 11:32:17 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_len_putchar(char c, int fd)
{
	ft_putchar_fd(c, fd);
	return (1);
}

int		ft_len_putstr(char *str, int ignore, int fd)
{
	int len;
	int i;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && ignore == 1)
			i++;
		len += ft_len_putchar(str[i], fd);
		i++;
	}
	return (len);
}

void	put_spacing(t_printf *pf, long long i)
{
	if (i >= 0)
	{
		if (pf->flag[1] == TRUE && pf->type != 'u' \
			&& pf->type != 'x' && pf->type != 'X')
			pf->len += ft_len_putchar('+', pf->fd);
		if (pf->flag[2] == TRUE && pf->flag[1] == FALSE && pf->type != 'u')
			pf->len += ft_len_putchar(' ', pf->fd);
		if (pf->flag[4] == TRUE && pf->type == 'o' && i != 0
			&& (pf->precision - ft_nb_len_ll(i, 8)) <= 0)
			pf->len += ft_len_putchar('0', pf->fd);
		if (pf->flag[4] && pf->type == 'o' && i == 0 && pf->precision <= -2)
			pf->len += ft_len_putchar('0', pf->fd);
		if (pf->flag[4] == TRUE && pf->type == 'x' && i != 0)
			pf->len += ft_len_putstr("0x", 0, pf->fd);
		if (pf->flag[4] == TRUE && pf->type == 'X' && i != 0)
			pf->len += ft_len_putstr("0X", 0, pf->fd);
	}
}

int		ft_nb_len(size_t nb, size_t base)
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

int		ft_nb_len_ll(long long nb, long long base)
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
