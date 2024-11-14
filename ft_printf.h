/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksiss <smaksiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:06:46 by smaksiss          #+#    #+#             */
/*   Updated: 2024/11/14 12:03:05 by smaksiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_putnbr(int n, char str);
int		ft_pmem(unsigned long str);
int		ft_printhex(unsigned int x, char s);

#endif
