/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:44:55 by theo              #+#    #+#             */
/*   Updated: 2025/04/09 10:30:54 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *source)
{
	char	*str;
	size_t	i;

	if (!source)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(source) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (source[i])
	{
		str[i] = source[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
