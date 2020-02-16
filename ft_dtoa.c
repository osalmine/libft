/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:03:12 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/24 13:17:34 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long double	ft_fmod(long double nb, long double div)
{
	long double	ret;
	int			sign;

	sign = nb < 0 ? -1 : 1;
	if (div == 0)
		return (0);
	ret = nb - (div * (long long)(nb / div));
	if (ret * sign < 0)
		ret *= -1;
	ret += 0.00001;
	return (ret);
}

static long double	ft_round(long double ld, int precision)
{
	long double	round;

	round = 0.5;
	if (ld < 0)
		round *= -1;
	while (precision--)
		round /= 10.0;
	return (round);
}

static void			ft_decimals(long double ld, int precision, char **s, int i)
{
	long long	tmp;
	int			pr;

	ld *= 10;
	(*s)[i++] = '.';
	pr = precision;
	while (precision--)
	{
		tmp = (((long long)ld != 9
				&& (long long)(ft_fmod((ld * 100), 10.0)) != 9)
				? (long long)(ld + 0.01) : (long long)ld);
		if (precision == 0 && (int)ld != tmp)
			tmp = (int)ld;
		if (pr >= 20 && precision == 0 && (long long)(ld * 10) % 10 >= 5)
			tmp++;
		if ((int)tmp == 0)
			(*s)[i++] = '0';
		if ((int)tmp != 0)
			(*s)[i++] = (char)(tmp + '0');
		if ((ld - tmp) < 0)
			ld = (ld - (tmp - 1)) * 10;
		else
			ld = (ld - tmp) * 10;
	}
}

static char			*end(int neg, char *str)
{
	char *tmp;

	if (neg == 1)
	{
		tmp = ft_strdup(str);
		free(str);
		str = ft_strjoin("-", tmp);
		free(tmp);
	}
	return (str);
}

char				*ft_dtoa(long double n, int precision)
{
	char		*str;
	long double	ld;
	long long	i;
	int			neg;

	neg = 0;
	n += ft_round(n, precision);
	if (n < 0 && (neg = 1) == 1)
		n = -n;
	if (!(str = \
		ft_strnew(precision + 1 + ft_nbs_base_ll((long long)n, 10) + neg)))
		return (0);
	ft_strclr(str);
	i = (long long)n;
	ld = n - (long double)i;
	ft_itoa_base_s(i, 10, 'a', &str);
	i = (int)ft_strlen(str);
	if (precision > 0)
		ft_decimals(ld, precision, &str, i);
	return (end(neg, str));
}
