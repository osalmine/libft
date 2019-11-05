/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:49:41 by osalmine          #+#    #+#             */
/*   Updated: 2019/10/30 17:34:58 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*temp1;
	char	*temp2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp1 = (char *)s1;
	temp2 = (char *)s2;
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(temp1)
						+ ft_strlen(temp2)) + 1)))
		return (NULL);
	while (temp1[i])
	{
		str[i] = temp1[i];
		i++;
	}
	while (temp2[j])
	{
		str[i++] = temp2[j];
		j++;
	}
	str[i] = '\0';
	return (str);
}
