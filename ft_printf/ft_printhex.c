/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksiss <smaksiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:08:55 by smaksiss          #+#    #+#             */
/*   Updated: 2024/11/13 10:09:51 by smaksiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_reverse(char *str, unsigned int n)
{
	char			*ptr;
	int				i;
	int				j;

	i = 0;
	j = 0;
	ptr = calloc(i, 1);
	while (n)
	{
		ptr[i++] = str[n % 16];
		n /= 16;
	}
	i--;
	while (i >= 0)
	{
		j++;
		write(1, &ptr[i--], 1);
	}
	return (j);
}

int	ft_printhex(int x, char s)
{
	int				i;
	char			*str;
	unsigned int	num;

	if (s == 'x')
		str = "0123456789abcdef";
	if (s == 'X')
		str = "0123456789ABCDEF";
	num = (unsigned int)x;
	if (num == 0)
	{
		ft_putchar('0');
		return (1);
	}
	i = ft_reverse(str, x);
	return (i);
}
// int main()
// {
// 	int i = ft_printhex(-8,'x');
// 	printf("\n");
// 	int	j = printf("%x",-8);
// 	printf("\n%d",i);
// 	printf("\n%d",j);
// }