/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:32:51 by dyoung            #+#    #+#             */
/*   Updated: 2019/11/15 20:16:11 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(void const *content, size_t size)
{
	void	*str;
	size_t	i;

	i = 0;
	if (!(str = malloc(size)))
		return (NULL);
	while (i < size)
	{
		((char*)str)[i] = ((char*)content)[i];
		i++;
	}
	return (str);
}
