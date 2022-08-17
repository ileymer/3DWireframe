/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:20:37 by dyoung            #+#    #+#             */
/*   Updated: 2019/11/16 20:07:32 by dyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_word(char const *s, char ch)
{
	int	size;

	size = 0;
	while (s[size] && (s[size] != ch))
		size++;
	return (size);
}

static int	ft_sum_words(char const *s, char c)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			word++;
		i++;
	}
	if (s[0])
		word++;
	return (word);
}

static char	*ft_malloc_word(char const *s, char c, int *i)
{
	char	*str;
	int		k;

	k = 0;
	if (!(str = (char *)malloc(sizeof(char) * (ft_size_word(s + *i, c) + 1))))
		return (NULL);
	while (s[*i] != c && s[*i])
	{
		str[k] = s[*i];
		k++;
		*i += 1;
	}
	str[k] = '\0';
	while (s[*i] == c && s[*i])
		*i += 1;
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		w;
	char	**ptr;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	w = ft_sum_words(s, c);
	if (!(ptr = (char **)malloc(sizeof(char *) * (w + 1))))
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	while (j < w && s[i] && ptr != NULL)
	{
		if ((ptr[j++] = ft_malloc_word(s, c, &i)) == NULL)
		{
			while (--j >= 0)
				free(ptr[j]);
			free(ptr);
		}
	}
	ptr[j] = NULL;
	return (ptr);
}
