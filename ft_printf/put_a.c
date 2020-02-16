/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:44:53 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/24 10:57:24 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static void	put_str(t_printf *pf, char *str)
{
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

/*
**	BONUS: Prints a NULL-terminated 2d char array (can be done with ft_strsplit)
**	Use the l specifier to put spaces instead of new lines between the
**	strings (%la). Precision and all other flags are applied to every string.
*/

void		put_a(t_printf *pf)
{
	int			i;
	char		**arr;
	t_printf	pf_copy;

	arr = va_arg(pf->lst, char**);
	i = 0;
	while (arr[i])
	{
		pf_copy = *pf;
		put_str(&pf_copy, arr[i]);
		i++;
		if (arr[i] == NULL)
			break ;
		if (pf->length[2] == TRUE)
			pf->len += ft_len_putchar(' ', pf->fd);
		else
			pf->len += ft_len_putchar('\n', pf->fd);
	}
}
