/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:24:11 by dyoung            #+#    #+#             */
/*   Updated: 2019/09/22 13:45:59 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*ptr1;
	char	*str;
	char	*ptr2;

	ptr1 = (char *)s;
	if (s == NULL)
		return (NULL);
	len = ft_strlen((char *)s);
	if (!(str = ft_strnew(len)))
		return (NULL);
	ptr2 = str;
	while (*ptr1)
	{
		*ptr2 = f(*ptr1);
		ptr1++;
		ptr2++;
	}
	return (str);
}
