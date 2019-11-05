/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:06:44 by osalmine          #+#    #+#             */
/*   Updated: 2019/11/05 08:32:27 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*temp;
	int		i;

	i = 0;
	temp = (char *)s;
	if (!(str = (char *)malloc(sizeof(char) * ft_strlen(temp) + 1)))
		return (NULL);
	if (!s && !f)
		return (0);
	while (temp[i])
	{
		str[i] = f(temp[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
