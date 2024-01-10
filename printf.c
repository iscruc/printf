/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icruces- < icruces-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:05:58 by icruces-          #+#    #+#             */
/*   Updated: 2024/01/10 20:32:53 by icruces-         ###   ########.fr       */
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
	while (*str)
	{
		if (*str == '%' && (*(str + 1) =='c' || *(str + 1) == 'd' || *(str + 1) == 's' ||
			*(str + 1) == 'p' || *(str + 1) == 'i' || *(str + 1) == 'u' 
			|| *(str + 1) == 'x' || *(str + 1) == 'X' || *(str + 1) == '%'))
			ft_type(++str, &len, ap);
		else
			len += write(1, str, 1);
		str++;
	}
	return (len);
}

 int	main(void)
{
	int	len;
	char *str = NULL;

	//ft_printf("%d",ft_printf("printing  c: %s, s: %s\n", str, "12"));
	ft_printf("%d",ft_printf("%s\n", str));
	//printf("printing  c: %s, s: %s\n", str, "12");
}
 
