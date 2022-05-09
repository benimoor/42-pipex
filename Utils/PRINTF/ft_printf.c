/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:02:23 by ergrigor          #+#    #+#             */
/*   Updated: 2022/04/06 22:04:25 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	norm_fix(const char *s, va_list *lst, int *i, int *count)
{
	if (s[*i] == '%')
		*count += ft_putchar('%');
	if (s[*i] == 'd' || s[*i] == 'i')
		*count += ft_putnbr(va_arg(*lst, int));
	if (s[*i] == 'u')
		*count += ft_putuint(va_arg(*lst, unsigned int));
	if (s[*i] == 'c')
		*count += ft_putchar(va_arg(*lst, int));
	if (s[*i] == 's')
		*count += ft_putstr(va_arg(*lst, char *));
	if (s[*i] == 'x')
		*count += ft_puthex(va_arg(*lst, unsigned int), 'x');
	if (s[*i] == 'X')
		*count += ft_puthex(va_arg(*lst, unsigned int), 'X');
	if (s[*i] == 'p')
		*count += ft_putptr(va_arg(*lst, void *));
}

int	ft_printf(const char *s, ...)
{
	va_list	lst;
	int		count;
	int		i;

	va_start(lst, s);
	i = -1;
	count = 0;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			i++;
			norm_fix(s, &lst, &i, &count);
		}
		else
			count += ft_putchar(s[i]);
	}
	va_end(lst);
	return (count);
}
