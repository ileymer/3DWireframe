/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bon2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 07:37:44 by dyoung            #+#    #+#             */
/*   Updated: 2020/02/06 08:07:13 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		color1(int k)
{
	if (k == 18)
		return (0xFF0000);
	if (k == 19)
		return (0xFF8C00);
	if (k == 20)
		return (0xFFFF00);
	if (k == 21)
		return (0x00FF00);
	if (k == 23)
		return (0x00FFFF);
	if (k == 22)
		return (0x0000FF);
	if (k == 29)
		return (0xFFFFFF);
	return (0x4B0082);
}

int		color2(int k)
{
	if (k == 83)
		return (0xFF0000);
	if (k == 84)
		return (0xFF8C00);
	if (k == 85)
		return (0xFFFF00);
	if (k == 86)
		return (0x00FF00);
	if (k == 87)
		return (0x00FFFF);
	if (k == 88)
		return (0x0000FF);
	if (k == 82)
		return (0xFFFFFF);
	return (0x4B0082);
}

void	hight(t_adds *m, int k)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->m)
	{
		j = 0;
		while (j < m->n)
		{
			if (m->z_copy[i][j] != 0)
			{
				if (k == 13)
					m->z[i][j] = m->z[i][j] + 10;
				if (k == 1)
					m->z[i][j] = m->z[i][j] - 10;
			}
			j++;
		}
		i++;
	}
}
