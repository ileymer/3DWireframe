/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 16:00:30 by dyoung            #+#    #+#             */
/*   Updated: 2020/02/06 08:09:24 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>

typedef struct	s_adds
{
	int		**z;
	int		**z_copy;
	int		**color;
	int		n;
	int		m;
	int		k;
	int		zoom;
	double	angle;
	int		movey;
	int		move;
	int		color1;
	int		color2;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_adds;

t_adds			*read_map(char *file);
void			print_error(int err);
void			free_split(char **part);
void			d(t_adds *mass, int m[2], int x1, int y1);
int				fxi(int xy[5], t_adds *mass, int i, int j);
int				fyi(int xy[5], t_adds *mass, int i, int j);
double			coss(int x, int y, t_adds *mass);
double			sinn(int x, int y, t_adds *mass, int l);
int				deal_key(int key, t_adds *param);
int				color1(int k);
int				color2(int k);
void			hight(t_adds *m, int k);
int				ft_atoi_16(char *str);
int				ft_isnumber(char *str, int base);
void			print_menu(t_adds *param);
int				gore(t_adds *mass);

#endif
