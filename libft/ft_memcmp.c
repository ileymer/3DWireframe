/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:58:39 by dyoung            #+#    #+#             */
/*   Updated: 2019/09/20 15:24:16 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (n == 0)
		return (0);
	i = 0;
	ptr1 = (unsigned char *)buf1;
	ptr2 = (unsigned char *)buf2;
	while (i < n - 1 && ptr1[i] == ptr2[i])
		i++;
	return ((unsigned char)ptr1[i] - (unsigned char)ptr2[i]);
}
