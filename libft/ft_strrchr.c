/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:11:11 by dyoung            #+#    #+#             */
/*   Updated: 2019/09/18 16:20:52 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t	i;
	char	*ptr;

	ptr = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)ch)
			ptr = ((char *)str + i);
		i++;
	}
	if (ptr)
		return (ptr);
	if (ch == '\0')
		return ((char *)str + i);
	return (0);
}
