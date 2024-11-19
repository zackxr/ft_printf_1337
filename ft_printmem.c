/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksiss <smaksiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:23:05 by smaksiss          #+#    #+#             */
/*   Updated: 2024/11/14 15:27:13 by smaksiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(unsigned long n)
{
	int	i;

	i = 1;
	while (n >= 16)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static void	ft_reverse(unsigned long n)
{
	if (n >= 16)
	{
		ft_reverse(n / 16);
		ft_reverse(n % 16);
	}
	else
		write(1, &"0123456789abcdef"[n], 1);
}

int	ft_pmem(unsigned long str)
{
	unsigned long		s;
	int					c;

	s = (unsigned long)str;
	c = 0;
	if (!s)
	{
		c += 3;
		write(1, "0x0", 3);
		return (c);
	}
	write(1, "0x", 2);
	c += 2;
	c += ft_count(s);
	ft_reverse(s);
	return (c);
}
