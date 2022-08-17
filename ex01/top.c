/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 07:24:27 by dyoung            #+#    #+#             */
/*   Updated: 2020/02/06 08:12:45 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	d1(int absx[8], int x0, int y0)
{
	absx[0] = absx[9] - y0;
	absx[1] = x0 - absx[8];
	if (abs(absx[0]) > abs(absx[1]))
		absx[2] = 1;
	else
		absx[2] = -1;
	if (absx[0] < 0)
		absx[3] = -1;
	else
		absx[3] = 1;
	if (absx[1] < 0)
		absx[4] = -1;
	else
		absx[4] = 1;
	absx[5] = 0;
	absx[6] = x0;
	absx[7] = y0;
}

static void	d2(int absx[10], int y1, int x1, t_adds *mass)
{
	int i;

	i = 1;
	while ((absx[6] != x1 || absx[7] != y1) || i == 1)
	{
		i = 0;
		absx[5] += absx[0] * absx[3];
		if (absx[5] > 0)
		{
			absx[5] -= absx[1] * absx[4];
			absx[7] += absx[3];
		}
		absx[6] -= absx[4];
		mlx_pixel_put(mass->mlx_ptr, mass->win_ptr, \
		absx[6] + mass->move, absx[7] + mass->movey, mass->color2);
	}
}

void		d(t_adds *mass, int m[2], int x1, int y1)
{
	int absx[10];
	int i;

	absx[8] = x1;
	absx[9] = y1;
	d1(absx, m[0], m[1]);
	i = 1;
	if (absx[2] == -1)
		d2(absx, y1, x1, mass);
	else
	{
		while ((absx[6] != x1 || absx[7] != y1) || i == 1)
		{
			i = 0;
			absx[5] += absx[1] * absx[4];
			if (absx[5] > 0)
			{
				absx[5] -= absx[0] * absx[3];
				absx[6] -= absx[4];
			}
			absx[7] += absx[3];
			mlx_pixel_put(mass->mlx_ptr, mass->win_ptr, \
			absx[6] + mass->move, absx[7] + mass->movey, mass->color2);
		}
	}
}
