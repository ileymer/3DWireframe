/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:42:38 by dyoung            #+#    #+#             */
/*   Updated: 2020/02/06 03:45:45 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_isspace(int c)
{
	return (c == '\t' ||
			c == '\n' ||
			c == '\v' ||
			c == '\f' ||
			c == '\r' ||
			c == ' ');
}

static int	ft_isdigit_base(char c, int base)
{
	const char	*digits = "0123456789ABCDEF";
	int			i;

	i = 0;
	while (i < base)
	{
		if (digits[i] == ft_toupper(c))
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_check16(char *str, int base)
{
	size_t i;

	i = 0;
	if (base == 16)
	{
		if (str[i++] != '0')
			return (0);
		if (str[i] == 'x' || str[i] == 'X')
			return (1);
	}
	return (0);
}

int			ft_isnumber(char *str, int base)
{
	size_t i;
	size_t digits;

	i = 0;
	digits = 0;
	while (ft_isspace(str[i]))
		i++;
	if (base != 10 && !ft_check16(&str[i], base))
		return (0);
	if (base == 16)
		i += 2;
	else if (base == 10 && (str[i] == '-' || str[i] == '+'))
		i++;
	while (ft_isdigit_base(str[i], base) >= 0)
	{
		i++;
		digits++;
	}
	return ((!str[i] && digits) ? 1 : 0);
}

int			ft_atoi_16(char *str)
{
	unsigned long	result;
	size_t			i;

	result = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (!ft_check16(&str[i], 16))
		return (0);
	i += 2;
	while (ft_isdigit_base(str[i], 16) >= 0)
		result = result * 16 + ft_isdigit_base(str[i++], 16);
	return ((int)result);
}
