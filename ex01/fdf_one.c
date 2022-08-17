/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_one.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 07:22:19 by dyoung            #+#    #+#             */
/*   Updated: 2020/02/06 08:10:40 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		eix(int xy[5], int i, int j, t_adds *mass)
{
	int w;
	int m[2];

	w = mass->zoom;
	m[0] = coss(xy[2], xy[3], mass);
	m[1] = sinn(xy[2], xy[3], mass, mass->z[i - 1][j]) - mass->z[i - 1][j];
	if (mass->z[i][j] > mass->z[i - 1][j] && mass->z[i - 1][j] == 0)
	{
		m[0] = coss(xy[2], xy[3], mass);
		m[1] = sinn(xy[2], xy[3], mass, 0);
		d(mass, m, coss(xy[2], xy[3] + w, mass), \
		sinn(xy[2], xy[3] + w, mass, mass->z[i][j]) - mass->z[i][j]);
	}
	else if (mass->z[i][j] == 0)
	{
		d(mass, m, coss(xy[2], xy[3] + w, mass), \
		sinn(xy[2], xy[3] + w, mass, mass->z[i][j]));
	}
	else if (mass->z[i][j] >= mass->z[i - 1][j])
		d(mass, m, coss(xy[2], xy[3] + w, mass), \
		sinn(xy[2], xy[3] + w, mass, mass->z[i][j]) - mass->z[i][j]);
	else if (mass->z[i][j] < mass->z[i - 1][j])
		d(mass, m, coss(xy[2], xy[3] + w, mass), \
		sinn(xy[2], xy[3] + w, mass, mass->z[i][j]) - mass->z[i][j]);
	return (xy[3] + mass->zoom);
}

static int		eiy(int xy[5], int i, int j, t_adds *mass)
{
	int w;
	int m[2];

	w = mass->zoom;
	m[0] = coss(xy[2], xy[3], mass);
	m[1] = sinn(xy[2], xy[3], mass, mass->z[j][i - 1]) - mass->z[j][i - 1];
	if (mass->z[j][i] > mass->z[j][i - 1] && mass->z[j][i - 1] == 0)
	{
		m[0] = coss(xy[2], xy[3], mass);
		m[1] = sinn(xy[2], xy[3], mass, 0);
		d(mass, m, coss(xy[2] + w, xy[3], mass), \
		sinn(xy[2] + w, xy[3], mass, mass->z[j][i]) - mass->z[j][i]);
	}
	else if (mass->z[j][i] == 0)
		d(mass, m, coss(xy[2] + w, xy[3], mass), \
		sinn(xy[2] + w, xy[3], mass, mass->z[j][i]));
	else if (mass->z[j][i] >= mass->z[j][i - 1])
		d(mass, m, coss(xy[2] + w, xy[3], mass), \
		sinn(xy[2] + w, xy[3], mass, mass->z[j][i]) - mass->z[j][i]);
	else if (mass->z[j][i] < mass->z[j][i - 1])
		d(mass, m, coss(xy[2] + w, xy[3], mass), \
		sinn(xy[2] + w, xy[3], mass, mass->z[j][i]) - mass->z[j][i]);
	return (xy[2] + w);
}

static void		fx(int xy[5], t_adds *mass)
{
	int i;
	int j;
	int r;
	int w;

	i = 0;
	j = 0;
	r = mass->z[0][0];
	w = mass->zoom;
	while (j < mass->n)
	{
		i = 0;
		xy[3] = xy[1];
		while (i < mass->m)
		{
			if (mass->z[i][j] == r && mass->z[i][j] == 0)
				xy[3] = fxi(xy, mass, i, j);
			else if (i != 0)
				xy[3] = eix(xy, i, j, mass);
			r = mass->z[i][j];
			i++;
		}
		r = mass->z[0][j++];
		xy[2] = xy[2] + w;
	}
}

static void		fy(int xy[5], t_adds *mass)
{
	int i;
	int j;
	int r;
	int w;

	i = 0;
	j = 0;
	r = mass->z[0][0];
	w = mass->zoom;
	while (j < mass->m)
	{
		i = 0;
		xy[2] = xy[0];
		while (i < mass->n)
		{
			if (mass->z[j][i] == r && mass->z[j][i] == 0)
				fyi(xy, mass, i, j);
			else if (i != 0)
				xy[2] = eiy(xy, i, j, mass);
			r = mass->z[j][i];
			i++;
		}
		r = mass->z[j++][0];
		xy[3] = xy[3] + w;
	}
}

int				gore(t_adds *mass)
{
	int xy[5];

	xy[0] = 400;
	xy[1] = 300;
	xy[2] = xy[0];
	xy[3] = xy[1];
	fx(xy, mass);
	xy[2] = xy[0];
	xy[3] = xy[1];
	fy(xy, mass);
	return (0);
}
