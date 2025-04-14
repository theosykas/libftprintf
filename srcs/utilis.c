/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:02:52 by theo              #+#    #+#             */
/*   Updated: 2025/04/14 20:32:00 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*conver_base(unsigned long n, const char *base)
{
	char			*res;
	int				len;
	unsigned long	tmp;

	len = 1;
	tmp = n;
	while (tmp / 16 != 0)
	{
		tmp /= 16;
		len++;
	}
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res[len] = '\0';
	while (len > 0)
	{
		res[--len] = base[n % 16];
		n /= 16;
	}
	return (res);
}
