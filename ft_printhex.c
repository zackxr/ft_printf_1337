/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksiss <smaksiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:08:55 by smaksiss          #+#    #+#             */
/*   Updated: 2024/11/16 10:08:51 by smaksiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(unsigned int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static void	ft_reverse(char *str, unsigned int n)
{
	if (n >= 16)
	{
		ft_reverse(str, n / 16);
		ft_reverse(str, n % 16);
	}
	else
		write(1, &str[n], 1);
}

int	ft_printhex(unsigned int x, char s)
{
	int				i;
	char			*str;

	i = 0;
	if (s == 'x')
		str = "0123456789abcdef";
	if (s == 'X')
		str = "0123456789ABCDEF";
	x = (unsigned int)x;
	if (x == 0)
	{
		ft_putchar('0');
		return (1);
	}
	i = ft_count(x);
	ft_reverse(str, x);
	return (i);
}
