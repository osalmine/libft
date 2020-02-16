/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_empty.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 12:21:19 by osalmine          #+#    #+#             */
/*   Updated: 2020/01/23 13:23:54 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_empty(t_printf *pf)
{
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
}
