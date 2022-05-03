/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:14:09 by ergrigor          #+#    #+#             */
/*   Updated: 2022/04/06 19:54:08 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char x)
{	
	char	*hex;
	int		count;

	count = 0;
	hex = "abcdef";
	if (n < 10)
		count += ft_putchar(n + '0');
	else if (n < 16 && x == 'X')
		count += ft_putchar((char)(ft_toupper(hex[n - 10])));
	else if (n < 16 && x == 'x')
		count += ft_putchar(hex[n - 10]);
	else
	{
		count += ft_puthex(n / 16, x);
		count += ft_puthex(n % 16, x);
	}
	return (count);
}
