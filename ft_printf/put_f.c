/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 18:38:54 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/05 12:22:16 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long double	get_number(t_printf *pf)
{
	long double	i;

	if (pf->length[4] == TRUE)
		i = (long double)va_arg(pf->lst, long double);
	else
		i = (double)va_arg(pf->lst, double);
	i = (long double)i;
	return (i);
}

static void			ft_width_nb(t_printf *pf, char *str)
{
	pf->width -= (int)ft_strlen(str);
	if (pf->flag[1] || pf->flag[2])
		pf->width -= 1;
	if ((pf->precision - (int)ft_strlen(str)) > 0)
		pf->width -= (pf->precision - (int)ft_strlen(str));
	if (ft_atoi(str) < 0 && pf->flag[0] == FALSE && (pf->flag[2] == TRUE \
		|| pf->flag[1]))
		pf->width += 1;
	if (pf->precision == 0 && pf->flag[4] == TRUE)
		pf->width -= 1;
	if (pf->flag[0] == TRUE && pf->flag[1] == TRUE && ft_atoi(str) < 0)
		pf->width += 1;
	if (ft_atoi(str) < 0 && pf->flag[2] == TRUE && pf->flag[0] == TRUE)
		pf->width += 1;
}

static void			front_padding_nb(t_printf *pf, long double i, char *str)
{
	int len;

	len = (int)ft_strlen(str);
	if (ft_atoi(str) < 0)
		len -= 1;
	if (pf->width > 0 && pf->flag[0] == FALSE)
	{
		if (pf->flag[3] == TRUE && (pf->precision - len) < 0 \
			&& pf->precision != -3)
		{
			put_spacing(pf, (long long)i);
			while (pf->width--)
				pf->len += ft_len_putchar('0', pf->fd);
		}
		else
		{
			while (pf->width--)
				pf->len += ft_len_putchar(' ', pf->fd);
			put_spacing(pf, (long long)i);
		}
	}
}

static int			nb_start(t_printf *pf, long double i, char *str)
{
	int	ignore;

	ignore = 0;
	if (pf->width <= 0 || pf->flag[0] == TRUE)
		put_spacing(pf, (long long)i);
	if ((long long)i < 0 && ((pf->width <= 0 && pf->precision > 0) ||
		(pf->flag[3] == TRUE)))
	{
		pf->len += ft_len_putchar('-', pf->fd);
		ignore = 1;
	}
	front_padding_nb(pf, i, str);
	if (ft_atoi(str) < 0 && pf->precision >= 0 && !ignore)
	{
		pf->len += ft_len_putchar('-', pf->fd);
		ignore = 1;
	}
	return (ignore);
}

void				put_f(t_printf *pf)
{
	long double nb;
	char		*str;
	int			ignore;

	nb = get_number(pf);
	if (pf->precision == -1)
		pf->precision = 6;
	if (pf->precision == -2 || pf->precision == -3)
		pf->precision = 0;
	if ((str = ft_dtoa(nb, pf->precision)) == 0)
		return ;
	ft_width_nb(pf, str);
	ignore = nb_start(pf, nb, str);
	pf->len += ft_len_putstr(str, ignore, pf->fd);
	if (pf->precision == 0 && pf->flag[4] == TRUE)
		pf->len += ft_len_putchar('.', pf->fd);
	if (pf->width > 0 && pf->flag[0] == TRUE)
		while (pf->width--)
			pf->len += ft_len_putchar(' ', pf->fd);
	free(str);
}
