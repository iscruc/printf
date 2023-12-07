/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icruces- < icruces-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:49:05 by icruces-          #+#    #+#             */
/*   Updated: 2023/12/07 20:54:22 by icruces-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_putchar(char str, int *len)
{
	*len += write(1, &str, 1);
}

static void	ft_putnbr_fd(int n, int fd, int *len)
{
	int	num;

	num = n;
	if (n == -2147483648)
	{
		*len += write(fd, "-2147483648", 11);
		return ;
	}
	if (num < 0)
	{
		ft_putchar('-', len);
		num *= -1;
	}
	if (num < 10)
		ft_putchar((char)(num + '0'), len);
	else
	{
		ft_putnbr_fd((num / 10), fd, len);
		ft_putnbr_fd((num % 10), fd, len);
	}
}

void	ft_putstr(char const *str, int *len)
{
	while (*str)
	{
		*len += write(1, str, 1);
		str++;
	}	
}

void ft_type(char const *str, int *len, va_list ap)
{
	if (*str == 's')
		ft_putstr(va_arg(ap, char *), len);
	else if (*str == 'c')
		ft_putchar(va_arg(ap, int), len);
	else if (*str == 'p')
		ft_putchar(va_arg(ap, unsigned long), len);
	else if (*str == 'd')
		ft_putnbr_fd(va_arg(ap, int), 1, len);
	else if (*str == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1, len);
	else if (*str == '%')
		ft_putchar(*str, len);
}