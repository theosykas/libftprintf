/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:51:39 by theo              #+#    #+#             */
/*   Updated: 2025/04/16 18:59:18 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	count_digits(int n)
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

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		len;

	nb = n;
	if (nb == 0)
		return (ft_strdup("0"));
	len = count_digits(nb) + (n < 0);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		*str = '-';
		nb = -nb;
	}
	while (len-- > (n < 0))
	{
		str[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

int	print_signed_pf(int n)
{
	char	*conv;
	int		len;

	conv = ft_itoa(n);
	if (!conv)
		return (0);
	len = 0;
	while (conv[len])
		write (1, &conv[len++], 1);
	free (conv);
	return (len);
}

//str = malloc(sizeof(char) * (len + 1));