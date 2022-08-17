/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 19:24:44 by dyoung            #+#    #+#             */
/*   Updated: 2019/09/23 18:23:47 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr1;
	unsigned char		*ptr2;

	ptr1 = (unsigned char*)dest;
	ptr2 = (unsigned char*)src;
	if (n == 0 || ptr2 == ptr1)
		return (dest);
	if (ptr2 < ptr1)
	{
		ptr2 = (unsigned char *)src + n - 1;
		ptr1 = (unsigned char *)dest + n - 1;
		while (n--)
			*ptr1-- = *ptr2--;
	}
	else
	{
		while (n--)
			*ptr1++ = *ptr2++;
	}
	return (dest);
}
