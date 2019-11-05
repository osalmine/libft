/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:30:42 by osalmine          #+#    #+#             */
/*   Updated: 2019/10/29 12:02:03 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	char	*temp;

	temp = (char *)s;
	i = 0;
	if (!s || !(str = ft_memalloc(len + 1)))
		return (NULL);
	str = ft_strncpy(str, s + start, len);
	return (str);
}
