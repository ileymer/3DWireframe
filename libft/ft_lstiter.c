/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:02:45 by dyoung            #+#    #+#             */
/*   Updated: 2019/11/16 19:30:48 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *tmp;

	if (!(lst || f))
		return ;
	tmp = lst;
	while (tmp != NULL)
	{
		f(tmp);
		tmp = tmp->next;
	}
}
