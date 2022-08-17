/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xryak.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 07:23:50 by dyoung            #+#    #+#             */
/*   Updated: 2020/02/06 08:13:40 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fxi(int xy[5], t_adds *mass, int i, int j)
{
	xy[4] = xy[3] + mass->zoom;
	if (i != 0)
		while (xy[3] < xy[4])
		{
			if (mass->z_copy[i][j] != 0 || mass->z_copy[i - 1][j] != 0)
				mlx_pixel_put(mass->mlx_ptr, mass->win_ptr, coss(xy[2], \
				xy[3], mass) + mass->move, sinn(xy[2], xy[3], \
				mass, 0) + mass->movey, mass->color2);
			else
				mlx_pixel_put(mass->mlx_ptr, mass->win_ptr, \
				coss(xy[2], xy[3], mass) + mass->move, sinn(xy[2], \
				xy[3], mass, 0) + mass->movey, mass->color1);
			xy[3]++;
		}
	return (xy[3]);
}

int		fyi(int xy[5], t_adds *mass, int i, int j)
{
	xy[4] = xy[2] + mass->zoom;
	if (i != 0)
		while (xy[2] < xy[4])
		{
			if (mass->z_copy[j][i] != 0 || mass->z_copy[j][i - 1] != 0)
				mlx_pixel_put(mass->mlx_ptr, mass->win_ptr, coss(xy[2], \
				xy[3], mass) + mass->move, sinn(xy[2], xy[3], mass, 0) + \
				mass->movey, mass->color2);
			else
				mlx_pixel_put(mass->mlx_ptr, mass->win_ptr, coss(xy[2], \
				xy[3], mass) + mass->move, sinn(xy[2], xy[3], mass, 0) + \
				mass->movey, mass->color1);
			xy[2]++;
		}
	return (xy[2]);
}

double	coss(int x, int y, t_adds *mass)
{
	if (mass->k == 0)
		return (x);
	return (x - y) * cos(mass->angle);
}

double	sinn(int x, int y, t_adds *mass, int l)
{
	if (mass->k == 0)
		return (y + l);
	return ((x + y) * sin(mass->angle));
}
