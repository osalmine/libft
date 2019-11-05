/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:21:26 by osalmine          #+#    #+#             */
/*   Updated: 2019/10/28 17:25:49 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	char *temp1;
	char *temp2;

	temp1 = (char *)s1;
	temp2 = (char *)s2;
	if (!(ft_strcmp(temp1, temp2)))
		return (1);
	return (0);
}
