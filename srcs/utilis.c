/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:02:52 by theo              #+#    #+#             */
/*   Updated: 2025/04/11 17:27:29 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*size_t	ft_strlen( const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}*/

/*char	*ft_strdup(const char *source)
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
}*/

char	*convert_base(unsigned int n, const char *base)
{
	char			*res;
	int				len_base;
	int				len;
	unsigned int	tmp;

	len_base = 0;
	while (base[len_base])
		len_base++;
	len = 1;
	tmp = n;
	while (tmp / len_base != 0)
	{
		tmp /= len_base;
		len++;
	}
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res[len] = '\0';
	while (len > 0)
	{
		res[--len] = base[n % len_base];
		n /= len_base;
	}
	return (res);
}
