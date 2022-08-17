/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:04:04 by dyoung            #+#    #+#             */
/*   Updated: 2019/09/23 17:35:05 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	if (n == 0 || src == dest)
		return (dest);
	i = 0;
	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dest);
}
