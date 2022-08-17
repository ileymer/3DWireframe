/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 14:03:04 by dyoung            #+#    #+#             */
/*   Updated: 2019/11/16 19:07:34 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *tmp_next;

	if (!(alst || del))
		return ;
	tmp = *alst;
	tmp_next = *alst;
	while (tmp != NULL)
	{
		del(tmp->content, tmp->content_size);
		tmp = tmp_next->next;
		free(tmp_next);
		tmp_next = tmp;
	}
	*alst = NULL;
}
