/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 03:54:52 by theo              #+#    #+#             */
/*   Updated: 2025/03/30 14:53:53 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}

/*
int	main(void)
{
	char	s1[] = "tok";
	char	s2[] = "tok";
	size_t	n = 1;

	int		res = ft_strncmp(s1, s2, n);
	printf("comparaison de la str %s et de la str %s : %d\n", s1, s2, res);
	return (0);
}*/