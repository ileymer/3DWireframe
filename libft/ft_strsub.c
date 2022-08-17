/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 20:59:46 by dyoung            #+#    #+#             */
/*   Updated: 2019/09/20 21:38:11 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (s == NULL)
		return (NULL);
	if (!(sub = ft_strnew(len)))
		return (NULL);
	sub = ft_strncpy(sub, (char*)s + start, len);
	return (sub);
}
