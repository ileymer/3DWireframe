/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 19:12:41 by dyoung            #+#    #+#             */
/*   Updated: 2020/01/12 19:22:41 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_meand			*listik(int fd)
{
	t_meand *list;

	if (!(list = (t_meand *)malloc(sizeof(t_meand))))
		return (NULL);
	list->m = ft_strnew(BUFF_SIZE);
	list->next = NULL;
	list->fd = fd;
	return (list);
}

t_oie			*listik2(void)
{
	t_oie *list;

	if (!(list = (t_oie *)malloc(sizeof(t_oie))))
		return (NULL);
	list->m = ft_strnew(BUFF_SIZE);
	list->next = NULL;
	return (list);
}

int				stroka(t_oie *k[3], char **line, int irg[3], t_meand *l2)
{
	if (irg[2] < 0)
		return (-1);
	if (irg[0] <= BUFF_SIZE)
	{
		free(l2->m);
		l2->m = ft_strsub(k[1]->m, irg[0], (BUFF_SIZE - irg[0]));
		if (irg[0])
			k[1]->m[--irg[0]] = '\0';
	}
	*line = ft_strnew(irg[1] * BUFF_SIZE);
	while (k[0] != NULL)
	{
		if (k[0]->m)
			ft_strcat(*line, k[0]->m);
		k[2] = k[0]->next;
		ft_strdel(&k[0]->m);
		free(k[0]);
		k[0] = k[2];
	}
	if ((int)(ft_strlen(*line) - 1) < 0 && irg[2] == 0)
		return (0);
	if (line[0][(int)(ft_strlen(*line) - 1)] == '\n')
		line[0][(int)(ft_strlen(*line) - 1)] = '\0';
	return (1);
}

int				perevod(int fd, char **line, t_meand *l2)
{
	int		irg[3];
	t_oie	*k[3];

	irg[2] = 1;
	irg[1] = 1;
	k[0] = listik2();
	k[1] = k[0];
	ft_strcpy(k[1]->m, l2->m);
	while (irg[2] > 0)
	{
		irg[0] = 0;
		if (ft_strlen(k[1]->m) == 0 || irg[1] != 1)
			if (!(irg[2] = read(fd, k[1]->m, BUFF_SIZE)))
				break ;
		while (irg[0] < BUFF_SIZE)
			if (k[1]->m[irg[0]++] == '\n')
				break ;
		if (k[1]->m[irg[0] - 1] == '\n')
			break ;
		k[1]->next = listik2();
		k[1] = k[1]->next;
		irg[1]++;
	}
	return (stroka(k, line, irg, l2));
}

int				get_next_line(const int fd, char **line)
{
	static t_meand	*l;
	t_meand			*l2;

	if (fd < 0 || line == 0)
		return (-1);
	if (!l)
		l = listik(fd);
	l2 = l;
	while (l2 != NULL)
	{
		if (l2->fd == fd)
			break ;
		if (l2->next != NULL)
			l2 = l2->next;
		else
		{
			l2->next = listik(fd);
			l2 = l2->next;
		}
	}
	return (perevod(fd, line, l2));
}
