/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 18:21:44 by dyoung            #+#    #+#             */
/*   Updated: 2020/02/06 08:11:31 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static int		ft_sum_words(char const *str, char c)
{
	int i;
	int words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

static void		map_fill(char *line, t_adds *massiv, int y)
{
	char	**stroka;
	char	**part;
	int		x;

	x = 0;
	stroka = ft_strsplit(line, ' ');
	while (stroka[x])
	{
		part = ft_strsplit(stroka[x], ',');
		if (!(ft_isnumber(part[0], 10)))
			print_error(2);
		if (part[1] && !ft_isnumber(part[1], 16))
			print_error(2);
		massiv->z[y][x] = ft_atoi(part[0]);
		massiv->z_copy[y][x] = massiv->z[y][x];
		massiv->color[y][x] = part[1] ? ft_atoi_16(part[1]) : 0xFFFFFF;
		free_split(part);
		free(stroka[x]);
		x++;
	}
	free(stroka);
	free(line);
}

static t_adds	*ft_allocate(int i, int j, t_adds *new)
{
	int	j_copy;

	new->n = i;
	new->m = j;
	j_copy = j;
	if (!(new->z = (int **)malloc(sizeof(int *) * j)))
		return (NULL);
	while (j > 0)
		if (!(new->z[--j] = (int *)malloc(sizeof(int) * i)))
			return (NULL);
	j = j_copy;
	if (!(new->z_copy = (int **)malloc(sizeof(int *) * j_copy)))
		return (NULL);
	while (j_copy > 0)
		if (!(new->z_copy[--j_copy] = (int *)malloc(sizeof(int) * i)))
			return (NULL);
	if (!(new->color = (int **)malloc(sizeof(int *) * j)))
		return (NULL);
	while (j > 0)
		if (!(new->color[--j] = (int *)malloc(sizeof(int) * i)))
			return (NULL);
	return (new);
}

static t_adds	*map_size(char *file)
{
	int		i;
	int		j;
	int		fd;
	char	*line;
	t_adds	*new;

	if ((fd = open(file, O_RDONLY)) <= 0)
		print_error(-1);
	j = 0;
	if (get_next_line(fd, &line) > 0)
		j = 1;
	i = ft_sum_words(line, ' ');
	free(line);
	while (get_next_line(fd, &line) > 0)
	{
		j++;
		free(line);
	}
	free(line);
	close(fd);
	if (!(new = (t_adds *)malloc(sizeof(t_adds))))
		return (NULL);
	return (ft_allocate(i, j, new));
}

t_adds			*read_map(char *file)
{
	int		fd;
	char	*line;
	t_adds	*massiv;
	int		y;

	massiv = map_size(file);
	massiv->k = 1;
	massiv->zoom = 20;
	massiv->move = 300;
	massiv->movey = 330;
	massiv->angle = 0.6;
	massiv->color1 = 0x00FF00;
	massiv->color2 = 0x4B0082;
	massiv->mlx_ptr = mlx_init();
	massiv->win_ptr = mlx_new_window(massiv->mlx_ptr, 2000, 2000, "nax");
	if ((fd = open(file, O_RDONLY)) <= 0)
		print_error(-1);
	y = 0;
	while (get_next_line(fd, &line) > 0)
		map_fill(line, massiv, y++);
	free(line);
	close(fd);
	return (massiv);
}
