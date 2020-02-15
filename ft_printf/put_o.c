/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:39:10 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/05 12:23:46 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_number(t_printf *pf)
{
	long long	i;

	if (pf->length[0] == TRUE)
		i = (unsigned short)va_arg(pf->lst, int);
	else if (pf->length[1] == TRUE)
		i = (unsigned char)va_arg(pf->lst, int);
	else if (pf->length[2] == TRUE)
		i = (unsigned long)va_arg(pf->lst, unsigned long int);
	else if (pf->length[3] == TRUE)
		i = (unsigned long long)va_arg(pf->lst, unsigned long long int);
	else if (pf->length[5] == TRUE)
		i = (size_t)va_arg(pf->lst, size_t);
	else
		i = (unsigned int)va_arg(pf->lst, unsigned int);
	i = (size_t)i;
	return (i);
}

static void		ft_width_nb(t_printf *pf, long long i)
{
	if (i >= 0)
		pf->width -= ft_nb_len(i, 8);
	else
		pf->width -= ft_nb_len(i, 8) + 1;
	if (pf->flag[1] || pf->flag[2] ||
		(pf->flag[4] && ft_nb_len(i, 8) >= pf->precision && i != 0))
		pf->width -= 1;
	if ((pf->precision - ft_nb_len(i, 8)) > 0)
		pf->width -= (pf->precision - ft_nb_len(i, 8));
	if (i == 0 && pf->precision <= -2 && pf->flag[4] == TRUE && !pf->flag[0])
		pf->width -= 1;
	if (i == 0 && pf->precision <= -2 && pf->flag[0] == TRUE && !pf->flag[4])
		pf->width += 1;
}

static void		front_padding_nb(t_printf *pf, long long i, char *str)
{
	int len;

	len = (int)ft_strlen(str);
	if (i < 0)
		len -= 1;
	if (pf->width > 0 && pf->flag[0] == FALSE)
	{
		if (pf->flag[3] == TRUE && (pf->precision - len) < 0 \
			&& pf->precision != -3 \
			&& (pf->precision > pf->width || pf->precision <= -1))
		{
			put_spacing(pf, i);
			while (pf->width--)
				pf->len += ft_len_putchar('0', pf->fd);
		}
		else
		{
			while (pf->width--)
				pf->len += ft_len_putchar(' ', pf->fd);
			put_spacing(pf, i);
		}
	}
}

static int		nb_start(t_printf *pf, long long i, char *str)
{
	int			ignore;

	ignore = 0;
	if (pf->width <= 0 || pf->flag[0] == TRUE)
		put_spacing(pf, i);
	if (pf->flag[4] == TRUE && pf->flag[3] == TRUE \
		&& (int)ft_strlen(str) > pf->precision && pf->precision > 0)
		pf->flag[3] = FALSE;
	front_padding_nb(pf, i, str);
	return (ignore);
}

void			put_o(t_printf *pf)
{
	size_t	i;
	char	*str;
	int		ignore;

	i = get_number(pf);
	if ((pf->precision <= -2 || pf->precision == 0) && i == 0 &&
		(str = ft_strnew(0)) && pf->width != 0 && pf->flag[0] == FALSE)
		pf->len += ft_len_putchar(' ', pf->fd);
	else if ((pf->precision <= -2 || pf->precision == 0) && i == 0)
		str = ft_strnew(0);
	else
		str = ft_itoa_base_us(i, 8, 'a');
	ft_width_nb(pf, i);
	ignore = nb_start(pf, i, str);
	if ((pf->precision -= (i < 0 ? ft_nb_len(-i, 8) : ft_nb_len(i, 8))) >= 0)
		while (pf->precision--)
			pf->len += ft_len_putchar('0', pf->fd);
	pf->len += ft_len_putstr(str, ignore, pf->fd);
	if (pf->width > 0 && pf->flag[0] == TRUE)
		while (pf->width--)
			pf->len += ft_len_putchar(' ', pf->fd);
	free(str);
}
