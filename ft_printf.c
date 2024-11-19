/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksiss <smaksiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 09:17:18 by smaksiss          #+#    #+#             */
/*   Updated: 2024/11/18 09:14:22 by smaksiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_help(const char *str, va_list ptr, int c, int i)
{
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			if (str[i + 1] == 's')
				c += ft_putstr(va_arg(ptr, char *));
			else if (str[i + 1] == 'c')
				c += ft_putchar(va_arg(ptr, int));
			else if ((str[i + 1] == 'd' || str[i + 1] == 'i'
					|| str[i + 1] == 'u'))
				c += ft_putnbr(va_arg(ptr, int), str[i + 1]);
			else if (str[i + 1] == 'p')
				c += ft_pmem(va_arg(ptr, unsigned long));
			else if (str[i + 1] == 'x' || str[i + 1] == 'X')
				c += ft_printhex(va_arg(ptr, unsigned int), str[i + 1]);
			else if (str[i + 1] == '%')
				c += ft_putchar(str[i + 1]);
			i++;
		}
		else if (str[i] != '%')
			c += ft_putchar(str[i]);
		i++;
	}
	return (c);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		i;
	int		c;

	if (write(1, "", 0) == -1)
		return (-1);
	i = 0;
	c = 0;
	va_start(ptr, str);
	c = ft_help(str, ptr, c, i);
	va_end(ptr);
	return (c);
}
