/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icruces- < icruces-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:05:58 by icruces-          #+#    #+#             */
/*   Updated: 2023/12/07 18:13:02 by icruces-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	int		len;

	if (!str)
		return (0);
	va_start(ap, str);
	len = 0;
	if (*str == "%" && (*str + 1 == "c" || *str + 1 == "d" || *str + 1 == "s" ||
		*str + 1 == "p" || str + 1 == "i" || *str + 1 == "i" || *str + 1 == "u" 
		|| *str + 1 == "x" || *str + 1 == "X" || *str + 1 == "%"))
		ft_type(++str);
	printline(va_arg(ap, char *), &len);
	return (len);
}

int	main(void)
{
	int	len;

	len = ft_printf("printing %s", "helllo", "test", 12.34);
	printf("\n%d", len);
}
