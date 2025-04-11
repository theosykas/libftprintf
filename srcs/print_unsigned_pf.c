/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_pf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:51:42 by theo              #+#    #+#             */
/*   Updated: 2025/04/11 20:55:56 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	count_digits(unsigned int n)
{
	int	count;

	count = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*uitoa(unsigned int n)
{
	char	*str;
	long	nb;
	int		len;

	nb = n;
	if (nb == 0)
		return (ft_strdup("0"));
	len = count_digits(nb);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (len > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

int	print_unsigned_pf(unsigned int n)
{
	char	*conv;
	int		len;

	conv = uitoa(n);
	if (!conv)
		return (0);
	len = 0;
	while (conv[len])
		write (1, &conv[len++], 1);
	free (conv);
	return (len);
}
