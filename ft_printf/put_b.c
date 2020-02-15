/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:08:43 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/05 12:23:38 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_number(t_printf *pf)
{
	long long	i;

	if (pf->length[0] == TRUE)
		i = (short)va_arg(pf->lst, int);
	else if (pf->length[1] == TRUE)
		i = (signed char)va_arg(pf->lst, int);
	else if (pf->length[2] == TRUE)
		i = (long)va_arg(pf->lst, long int);
	else if (pf->length[3] == TRUE)
		i = (long long int)va_arg(pf->lst, long long int);
	else if (pf->length[5] == TRUE)
		i = (size_t)va_arg(pf->lst, size_t);
	else
		i = (int)va_arg(pf->lst, int);
	i = (long long)i;
	return (i);
}

static void		ft_width_nb(t_printf *pf, long long i)
{
	if (i >= 0)
		pf->width -= ft_nb_len(i, 2);
	else
		pf->width -= ft_nb_len(i, 2) + 1;
	if (pf->flag[1] || pf->flag[2] ||
		(pf->flag[4] && ft_nb_len(i, 2) >= pf->precision && i != 0))
		pf->width -= 1;
	if ((pf->precision - ft_nb_len(i, 2)) > 0)
		pf->width -= (pf->precision - ft_nb_len(i, 2));
	if (i == 0 && pf->precision <= -2 && pf->flag[4] == TRUE && !pf->flag[0])
		pf->width -= 1;
	if (i == 0 && pf->precision <= -2 && pf->flag[0] == TRUE && !pf->flag[4])
		pf->width += 1;
}

static void		front_padding_nb(t_printf *pf, long long i, char *str, int neg)
{
	int len;

	len = (int)ft_strlen(str);
	if (neg)
		len -= 1;
	if (pf->width > 0 && pf->flag[0] == FALSE)
	{
		if (pf->flag[3] == TRUE && (pf->precision - len) < 0 \
			&& pf->precision != -3 \
			&& (pf->precision > pf->width || pf->precision <= -1))
		{
			put_spacing(pf, (neg ? (i * -1) : i));
			while (pf->width--)
				pf->len += ft_len_putchar('0', pf->fd);
		}
		else
		{
			while (pf->width--)
				pf->len += ft_len_putchar(' ', pf->fd);
			put_spacing(pf, (neg ? (i * -1) : i));
		}
	}
}

static int		nb_start(t_printf *pf, long long i, char *str, int neg)
{
	int	ignore;

	ignore = 0;
	if (pf->width <= 0 || pf->flag[0] == TRUE)
		put_spacing(pf, (neg ? (i * -1) : i));
	if (neg && ((pf->width <= 0 && pf->precision > 0) ||
		(pf->flag[3] == TRUE && pf->width <= 0) ||
		(pf->flag[3] == TRUE && pf->precision == -1)))
	{
		pf->len += ft_len_putchar('-', pf->fd);
		ignore = 1;
	}
	front_padding_nb(pf, i, str, neg);
	if (neg && !ignore)
	{
		pf->len += ft_len_putchar('-', pf->fd);
		ignore = 1;
	}
	return (ignore);
}

/*
**	BONUS: Prints int as binary (base 2). Puts '-' in front of negative numbers,
**	otherwise works the same as %o flag
*/

void			put_b(t_printf *pf)
{
	long long	i;
	char		*str;
	int			ignore;
	int			neg;

	i = get_number(pf);
	neg = 0;
	i < 0 ? (neg = 1) : neg;
	if ((pf->precision <= -2 || pf->precision == 0) && i == 0 &&
		(str = ft_strnew(0)) && pf->width != 0 && pf->flag[0] == FALSE)
		pf->len += ft_len_putchar(' ', pf->fd);
	else if ((pf->precision <= -2 || pf->precision == 0) && i == 0)
		str = ft_strnew(0);
	else
		str = ft_itoa_base_us((neg ? i * -1 : i), 2, 'a');
	ft_width_nb(pf, (neg ? i * -1 : i));
	ignore = nb_start(pf, (neg ? i * -1 : i), str, neg);
	if ((pf->precision -= (neg == 1 ? ft_nb_len(-i, 2) : ft_nb_len(i, 2))) >= 0)
		while (pf->precision--)
			pf->len += ft_len_putchar('0', pf->fd);
	pf->len += ft_len_putstr(str, ignore, pf->fd);
	if (pf->width > 0 && pf->flag[0] == TRUE)
		while (pf->width--)
			pf->len += ft_len_putchar(' ', pf->fd);
	free(str);
}
