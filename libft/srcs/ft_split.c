/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:44:51 by theo              #+#    #+#             */
/*   Updated: 2025/04/09 16:29:15 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	counts_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void	seg_cpy(char *tab, char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
}

static void	tab_completion(char **tab, char const *s, char c)
{
	size_t	count;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		count = 0;
		while (s[i + count] && s[i + count] != c)
			count++;
		if (count > 0)
		{
			tab[j] = malloc(sizeof(char) * (count + 1));
			if (!tab[j])
				return ;
			seg_cpy(tab[j], (s + i), c);
			j++;
			i = i + count;
		}
		else
			i++;
	}
	tab[j] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;

	i = counts_words(s, c);
	res = malloc(sizeof(char *) * (i + 1));
	if (!res)
		return (NULL);
	tab_completion(res, s, c);
	return (res);
}
