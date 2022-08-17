/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 07:21:51 by dyoung            #+#    #+#             */
/*   Updated: 2020/02/06 08:01:38 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_menu(t_adds *param)
{
	char *menu;

	menu = " A | D              Height change";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 10, 10, 0xFFFFFF, menu);
	menu = " W | S              Angle change";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 10, 40, 0xFFFFFF, menu);
	menu = " Up | Down          Vertical movement";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 10, 70, 0xFFFFFF, menu);
	menu = " Left | Right       Horizontal movement";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 10, 100, 0xFFFFFF, menu);
	menu = " 0 - 7 NumLock      Figure color change";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 10, 130, 0xFFFFFF, menu);
	menu = " 0 - 7 Keyboard     Map color change";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 10, 160, 0xFFFFFF, menu);
	menu = " + or -             Zoom in and out";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 10, 190, 0xFFFFFF, menu);
	menu = " ESC                Exit";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 10, 220, 0xFFFFFF, menu);
	menu = " Enter              Projection change";
	mlx_string_put(param->mlx_ptr, param->win_ptr, 10, 250, 0xFFFFFF, menu);
}

void	print_error(int err)
{
	if (err == 0)
		ft_putstr("usage: ./fdf map.fdf\n");
	else if (err == -1)
		ft_putstr("file not found\n");
	else if (err == 2)
		ft_putstr("error map\n");
	exit(1);
}

void	free_split(char **part)
{
	size_t i;

	i = 0;
	while (part[i])
		free(part[i++]);
	free(part);
}

int		main(int argc, char **argv)
{
	t_adds	*massiv;

	if (argc != 2)
		print_error(0);
	massiv = read_map(argv[1]);
	gore(massiv);
	print_menu(massiv);
	mlx_key_hook(massiv->win_ptr, deal_key, massiv);
	mlx_loop(massiv->mlx_ptr);
	return (0);
}
