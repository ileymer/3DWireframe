/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:38:28 by dyoung            #+#    #+#             */
/*   Updated: 2019/09/22 19:11:55 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;

	if (s1 && s2)
		len = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	else if (s1 && s2 == NULL)
		len = ft_strlen((char*)s1);
	else if (s1 == NULL && s2)
		len = ft_strlen((char*)s2);
	else
		return (NULL);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (s1)
		str = ft_strcpy(str, (char *)s1);
	else
		str = ft_strcpy(str, (char *)s2);
	if (s1 && s2)
		ft_strcat(str, (char*)s2);
	return (str);
}
