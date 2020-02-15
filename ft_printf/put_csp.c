/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_csp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 18:42:52 by osalmine          #+#    #+#             */
/*   Updated: 2020/02/05 12:23:37 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		put_c(t_printf *pf)
{
	char c;

	c = va_arg(pf->lst, unsigned long);
	pf->width -= 1;
	if (pf->width > 0 && pf->flag[0] == FALSE)
	{
		if (pf->flag[3] == TRUE)
			while (pf->width--)
				pf->len += ft_len_putchar('0', pf->fd);
		else
			while (pf->width--)
				pf->len += ft_len_putchar(' ', pf->fd);
	}
	pf->len += ft_len_putchar(c, pf->fd);
	if (pf->width > 0 && pf->flag[0] == TRUE)
		while (pf->width--)
			pf->len += ft_len_putchar(' ', pf->fd);
}

static void	ft_width_s(t_printf *pf, char *str)
{
	int len;

	len = (int)ft_strlen(str) - ((int)ft_strlen(str) - pf->precision);
	if (pf->width > 0)
	{
		if (pf->precision > 0 && pf->precision > pf->width \
				&& pf->precision < len)
			pf->width = pf->width - pf->precision + (int)ft_strlen(str);
		else if (pf->precision > 0 && pf->precision < pf->width \
				&& pf->precision >= (int)ft_strlen(str))
			pf->width -= (int)ft_strlen(str);
		else if (pf->precision > 0 && pf->precision < pf->width \
				&& pf->precision < (int)ft_strlen(str))
			pf->width -= pf->precision;
		else
			pf->width -= ft_strlen(str);
	}
}

static void	start_s(t_printf *pf)
{
	if (pf->width > 0 && pf->flag[0] == FALSE)
	{
		if (pf->flag[3] == TRUE)
			while (pf->width--)
				pf->len += ft_len_putchar('0', pf->fd);
		else
			while (pf->width--)
				pf->len += ft_len_putchar(' ', pf->fd);
	}
}

void		put_s(t_printf *pf)
{
	char *str;

	str = va_arg(pf->lst, char*);
	if (!str)
		str = "(null)";
	if (pf->precision <= -2)
		str = "";
	ft_width_s(pf, str);
	start_s(pf);
	if (pf->precision >= 0)
		while (pf->precision-- && *str)
			pf->len += ft_len_putchar(*str++, pf->fd);
	else
		pf->len += ft_len_putstr(str, 0, pf->fd);
	if (pf->width > 0 && pf->flag[0] == TRUE)
		while (pf->width--)
			pf->len += ft_len_putchar(' ', pf->fd);
}

void		put_p(t_printf *pf)
{
	size_t	p;
	char	*str;

	p = (size_t)va_arg(pf->lst, unsigned long);
	str = ft_itoa_base_us(p, 16, 'a');
	pf->width -= ft_strlen(str) + 2;
	if (pf->width > 0 && pf->flag[0] == FALSE)
		while (pf->width--)
			pf->len += ft_len_putchar(' ', pf->fd);
	pf->len += ft_len_putstr("0x", 0, pf->fd);
	if (pf->precision > 0 && pf->precision - (int)ft_strlen(str) > -2)
		pf->precision -= ft_strlen(str);
	else if (pf->precision > 0 && pf->precision - (int)ft_strlen(str) <= -2)
		pf->precision = -1;
	if (pf->precision > 0)
		while (pf->precision--)
			pf->len += ft_len_putchar('0', pf->fd);
	if (pf->precision > -2)
		pf->len += ft_len_putstr(str, 0, pf->fd);
	if (pf->width > 0 && pf->flag[0] == TRUE)
		while (pf->width--)
			pf->len += ft_len_putchar(' ', pf->fd);
	free(str);
}
