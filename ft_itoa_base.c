/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:07:59 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/05 12:24:52 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		ft_calculate_char(int mod, char c)
{
	char	return_char;

	if (mod > 36)
		return (0);
	return_char = '0';
	while (mod--)
	{
		return_char++;
		if (return_char == ':')
			return_char = c;
	}
	return (return_char);
}

void			ft_itoa_base_s(long long num, long long base, char u, char **s)
{
	int		size;
	int		minus;

	minus = 0;
	if (num < 0 && base == 10)
		minus = 1;
	size = ft_nbs_base_ll(num, base) + minus;
	if (minus)
		(*s)[0] = '-';
	while (size > minus)
	{
		(*s)[(size--) - 1] = ft_calculate_char(ft_abs(num % base), u);
		num /= base;
	}
}

char			*ft_itoa_base(long long num, long long base, char up_lo)
{
	char	*str;
	int		size;
	int		minus;

	if (num == 0)
	{
		if (!(str = ft_strnew(1)))
			return (NULL);
		*str = '0';
		return (str);
	}
	minus = 0;
	if (num < 0 && base == 10)
		minus = 1;
	size = ft_nbs_base_ll(num, base) + minus;
	if (!(str = ft_strnew(size + 1)))
		return (NULL);
	if (minus)
		str[0] = '-';
	while (size > minus)
	{
		str[(size--) - 1] = ft_calculate_char(ft_abs(num % base), up_lo);
		num /= base;
	}
	return (str);
}

char			*ft_itoa_base_us(size_t num, size_t base, char up_lo)
{
	char	*str;
	int		size;

	if (num == 0)
	{
		if (!(str = ft_strnew(1)))
			return (NULL);
		*str = '0';
		return (str);
	}
	size = ft_nbs_base(num, base);
	if (!(str = ft_strnew(size)))
		return (NULL);
	while (num)
	{
		str[(size--) - 1] = ft_calculate_char(ft_abs(num % base), up_lo);
		num /= base;
	}
	return (str);
}
