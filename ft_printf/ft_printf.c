/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 08:33:29 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/23 14:07:02 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_types(t_printf *pf)
{
	if (pf->type == 'c')
		put_c(pf);
	if (pf->type == 's')
		put_s(pf);
	if (pf->type == 'p')
		put_p(pf);
	if (pf->type == 'f')
		put_f(pf);
	if (pf->type == 'd' || pf->type == 'i')
		put_di(pf);
	if (pf->type == 'o')
		put_o(pf);
	if (pf->type == 'u')
		put_u(pf);
	if (pf->type == 'x' || pf->type == 'X')
		put_x(pf);
	if (pf->type == '%')
		put_pros(pf);
	if (pf->type == 0)
		put_empty(pf);
	if (pf->type == 'b')
		put_b(pf);
	if (pf->type == 'a')
		put_a(pf);
}

t_printf	*init_pf(char *str, t_printf *pf)
{
	pf->str = str;
	pf->i = 0;
	pf->flag[0] = FALSE;
	pf->flag[1] = FALSE;
	pf->flag[2] = FALSE;
	pf->flag[3] = FALSE;
	pf->flag[4] = FALSE;
	pf->precision = -1;
	pf->width = 0;
	pf->length[0] = FALSE;
	pf->length[1] = FALSE;
	pf->length[2] = FALSE;
	pf->length[3] = FALSE;
	pf->length[4] = FALSE;
	return (pf);
}

void		pf_start(t_printf *pf, char *str)
{
	while (*str)
	{
		if (*str == '%')
		{
			++str;
			if (*str == 0)
				break ;
			pf = init_pf(str, pf);
			ft_parse(pf);
			if (!*(str + pf->i))
				break ;
			str += pf->i;
		}
		else
			pf->len += ft_len_putchar(*str, pf->fd);
		str++;
	}
}

int			ft_printf(const char *format, ...)
{
	t_printf	*pf;
	char		*str;
	int			len;

	str = (char *)format;
	len = 0;
	if (!(pf = (t_printf*)malloc(sizeof(t_printf))))
		return (0);
	pf->len = 0;
	pf->fd = 1;
	va_start(pf->lst, format);
	if (format)
		pf_start(pf, str);
	va_end(pf->lst);
	len = pf->len;
	free(pf);
	return (len);
}

int			ft_fprintf(int fd, const char *format, ...)
{
	t_printf	*pf;
	char		*str;
	int			len;

	str = (char *)format;
	len = 0;
	if (!(pf = (t_printf*)malloc(sizeof(t_printf))))
		return (0);
	pf->fd = fd;
	pf->len = 0;
	va_start(pf->lst, format);
	if (format)
		pf_start(pf, str);
	va_end(pf->lst);
	len = pf->len;
	free(pf);
	return (len);
}
