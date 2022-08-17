/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bon.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 07:22:38 by dyoung            #+#    #+#             */
/*   Updated: 2020/02/06 08:05:52 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		bon3(int key, t_adds *param)
{
	if (key == 125)
		param->movey = param->movey + 20;
	if (key == 126)
		param->movey = param->movey - 20;
	if (key == 123)
		param->move = param->move - 20;
	if (key == 124)
		param->move = param->move + 20;
}

static void		bon(int key, t_adds *param)
{
	if (key == 2)
	{
		if (param->angle > 0 && param->k != 0)
		{
			param->angle = param->angle - 0.05;
			param->movey = param->movey + 40;
		}
	}
	else if (key == 126 || key == 123 || key == 125 || key == 124)
	{
		bon3(key, param);
	}
	else if (key == 36)
	{
		if (param->k == 1)
			param->k = 0;
		else
			param->k = 1;
	}
}

static void		bon2(int key, t_adds *param)
{
	if (key == 24 || key == 69)
	{
		param->zoom = param->zoom + 3;
	}
	else if (key == 27 || key == 78)
	{
		if (param->zoom - 3 > 1)
			param->zoom = param->zoom - 3;
	}
	else if (key == 18 || key == 19 || key == 20 || key == 26 || \
			key == 21 || key == 23 || key == 22 || key == 29)
		param->color1 = color1(key);
	else if (key == 83 || key == 84 || key == 85 || key == 86 || \
			key == 87 || key == 88 || key == 82 || key == 89)
		param->color2 = color2(key);
	if (key == 1 || key == 13)
		hight(param, key);
	else if (key == 0)
		if (param->angle <= 3.1 && param->k != 0)
		{
			param->angle = param->angle + 0.05;
			param->movey = param->movey - 40;
		}
}

int				deal_key(int key, t_adds *param)
{
	if (key == 29 || key == 18 || key == 19 || key == 20 || key == 21 \
			|| key == 23 || key == 22 || key == 26 || key == 82 || \
			key == 83 || key == 84 || key == 85 || key == 86 || \
			key == 87 || key == 88 || key == 89 || key == 53 || \
			key == 126 || key == 125 || key == 124 || key == 123 || \
			key == 24 || key == 27 || key == 69 || key == 78 || \
			key == 0 || key == 2 || key == 13 || key == 1 || key == 36)
	{
		mlx_clear_window(param->mlx_ptr, param->win_ptr);
		print_menu(param);
		if (key == 53)
		{
			mlx_destroy_window(param->mlx_ptr, param->win_ptr);
			free(param);
			exit(0);
		}
		bon(key, param);
		bon2(key, param);
		gore(param);
	}
	return (0);
}
