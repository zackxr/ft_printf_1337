/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksiss <smaksiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:21:47 by smaksiss          #+#    #+#             */
/*   Updated: 2024/11/16 10:09:37 by smaksiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_signed_n(int n, char str, char c)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		ft_signed_n(n, str, c);
	}
	else if (n > 9)
	{
		ft_signed_n(n / 10, str, c);
		ft_signed_n(n % 10, str, c);
	}
	else if (n >= 0 && n <= 9)
	{
		c = n + 48;
		write(1, &c, 1);
	}
}

static void	ft_unsigned_n(unsigned int n, char str)
{
	char	c;

	if (n > 9)
	{
		ft_unsigned_n(n / 10, str);
		ft_unsigned_n(n % 10, str);
	}
	else if (n >= 0 && n <= 9)
	{
		c = n + 48;
		write(1, &c, 1);
	}
}

static int	lengthu(unsigned int b)
{
	int	i;

	i = 0;
	if (b < 0)
	{
		i++;
		b *= -1;
	}
	while (b / 10)
	{
		b /= 10;
		i++;
	}
	return (i);
}

static int	length(int b)
{
	int	i;

	i = 0;
	if (b < 0)
	{
		i++;
		b *= -1;
	}
	while (b / 10)
	{
		b /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int n, char str)
{
	int				i;
	unsigned int	b;
	char			c;

	c = 0;
	i = 0;
	b = 0;
	if (str == 'u')
	{
		b = lengthu((unsigned int) n);
		ft_unsigned_n((unsigned int)n, str);
	}
	else if (str == 'd' || str == 'i')
	{
		b = length(n);
		ft_signed_n(n, str, c);
	}
	return (b + 1);
}
