/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:51:39 by theo              #+#    #+#             */
/*   Updated: 2025/04/10 16:17:46 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

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
	char	*new;
	int		i;

	new = ft_itoa(n);
	if (!new)
		return (0);
	i = 0;
	while (new[i] != '\0')
	{
		write (1, &new[i], 1);
		i++;
	}
	free (new);
	return (i);
}
