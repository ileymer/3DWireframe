/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:18:55 by dyoung            #+#    #+#             */
/*   Updated: 2019/11/16 18:51:45 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;

	if (!(lst || f))
		return (NULL);
	new = f(lst);
	if (lst->next && new)
		(new->next = ft_lstmap(lst->next, f));
	return (new);
}
