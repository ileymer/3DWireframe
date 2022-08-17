/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 20:25:31 by dyoung            #+#    #+#             */
/*   Updated: 2019/09/23 14:27:46 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	length_number(unsigned int nb)
{
	unsigned int	len;

	len = 1;
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static void			sign_number(int n, unsigned int *len)
{
	if (n < 0)
		*len += 1;
}

char				*ft_itoa(int n)
{
	char			*str;
	unsigned int	nb;
	unsigned int	i;
	unsigned int	len;

	if (n < 0)
		nb = (unsigned int)(n * -1);
	else
		nb = (unsigned int)n;
	len = length_number(nb);
	sign_number(n, &len);
	i = 0;
	if (!(str = ft_strnew(len)))
		return (NULL);
	i = len - 1;
	while (nb >= 10)
	{
		str[i] = (char)(nb % 10 + '0');
		nb /= 10;
		i--;
	}
	str[i] = (char)(nb % 10 + '0');
	if (n < 0)
		str[0] = '-';
	return (str);
}
