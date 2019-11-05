/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:26:21 by osalmine          #+#    #+#             */
/*   Updated: 2019/10/28 17:28:52 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char *temp1;
	char *temp2;

	temp1 = (char *)s1;
	temp2 = (char *)s2;
	if (!(ft_strncmp(temp1, temp2, n)))
		return (1);
	return (0);
}
