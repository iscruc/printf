/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icruces- < icruces-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:49:05 by icruces-          #+#    #+#             */
/*   Updated: 2024/01/10 20:33:08 by icruces-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_strlen(char const *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

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
static void ft_putnbr_base_fd(unsigned long n, char *base, int fd, int *len)
{
	unsigned long	num;
	unsigned long	base_len;

	base_len = ft_strlen(base);
	num = n;
	if (num < base_len)
		ft_putchar(base[num], len);
	else
	{
		ft_putnbr_base_fd((num / base_len), base, fd, len);
		ft_putnbr_base_fd((num % base_len), base, fd, len);
	}
}

void	ft_putstr(char const *str, int *len)
{	
	if (!str)
	{
		*len += write(1, "(null)", 6);
		return ;
	}
	while (*str)
	{
		*len += write(1, str, 1);
		str++;
	}
}

void	ft_type(char const *str, int *len, va_list ap)
{
	if (*str == 's')
		ft_putstr(va_arg(ap, char *), len);
	else if (*str == 'c')
		ft_putchar(va_arg(ap, int), len);
	else if (*str == 'p')
		ft_putnbr_base_fd(va_arg(ap, unsigned long), "0123456789abcdef", 1, len);
	else if (*str == 'd')
		ft_putnbr_fd(va_arg(ap, int), 1, len);
	else if (*str == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1, len);
	else if (*str == 'u')
		ft_putnbr_fd(va_arg(ap, int), 1, len);
	else if (*str == 'x')
		ft_putnbr_base_fd(va_arg(ap, unsigned int), "0123456789abcdef", 1, len);
	else if (*str == 'X')
		ft_putnbr_base_fd(va_arg(ap, unsigned int), "0123456789ABCDEF", 1, len);
	else if (*str == '%')
		ft_putchar(*str, len);
}
