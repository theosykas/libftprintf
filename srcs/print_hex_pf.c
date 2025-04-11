/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:51:32 by theo              #+#    #+#             */
/*   Updated: 2025/04/11 20:55:19 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_hex_pf(unsigned int n, int uppercase)
{
	char	*res;
	char	*base;
	int		len;

	if (uppercase)
		base = HEX_BASE_UPPER;
	else
		base = HEX_BASE_LOWER;
	if (n == 0)
		return (write (1, "0", 1));
	res = conver_base(n, base);
	len = 0;
	while (res[len])
		write (1, &res[len++], 1);
	free (res);
	return (len);
}
