/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:04:34 by ergrigor          #+#    #+#             */
/*   Updated: 2022/04/06 22:04:38 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_putstr(const char *str);
size_t	ft_strlen(const char *str);
int		ft_putnbr(int n);
int		ft_puthex(unsigned int n, char x);
int		ft_toupper(int c);
int		counter(int n);
int		ft_putuint(unsigned int n);
int		ft_putptr(void *x);
int		ft_printf(const char *s, ...);

#endif