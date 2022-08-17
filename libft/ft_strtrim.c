/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:25:03 by dyoung            #+#    #+#             */
/*   Updated: 2019/09/22 20:23:08 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
		len--;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		i++;
		len--;
	}
	if (len <= 0)
		len = 0;
	if (!(str = ft_strnew(len)))
		return (NULL);
	str = ft_strncpy(str, (char*)s + i, len);
	return (str);
}
