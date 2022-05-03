/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:38:02 by ergrigor          #+#    #+#             */
/*   Updated: 2022/04/06 19:54:08 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	puthex(unsigned long long int n)
{	
	char	*hex;
	int		count;

	count = 0;
	hex = "abcdef";
	if (n < 10)
		count += ft_putchar(n + '0');
	else if (n < 16)
		count += ft_putchar(hex[n - 10]);
	else
	{
		count += puthex(n / 16);
		count += puthex(n % 16);
	}
	return (count);
}

int	ft_putptr(void *x)
{
	unsigned long long int	a;

	a = (unsigned long long int)x;
	if (!x)
	{
		write (1, "0x0", 3);
		return (3);
	}
	else
	{
		write (1, "0x", 2);
		return (puthex(a) + 2);
	}
}
