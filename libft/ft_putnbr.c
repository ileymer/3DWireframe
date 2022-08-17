/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:38:25 by dyoung            #+#    #+#             */
/*   Updated: 2019/09/18 18:21:06 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int nb;

	if (n < 0)
	{
		ft_putchar('-');
		nb = (unsigned int)(n * -1);
	}
	else
		nb = (unsigned int)n;
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar((char)(nb % 10 + '0'));
}
