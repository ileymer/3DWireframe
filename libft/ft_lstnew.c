/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:03:47 by dyoung            #+#    #+#             */
/*   Updated: 2019/11/16 19:02:20 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_list;

	if (!(new_list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		new_list->content = NULL;
		new_list->content_size = 0;
	}
	else
	{
		if (!(new_list->content = ft_memdup(content, content_size)))
		{
			free(new_list);
			return (NULL);
		}
		new_list->content_size = content_size;
	}
	new_list->next = NULL;
	return (new_list);
}
