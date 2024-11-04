#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	Printmem(char *str)
{
	int	i;j

static void PrintHex(char str, int nb)
{
	char	*h1;
	char	*h2;

	h1 = "0123456789abcdef";
	h2 = "0123456789ABCDEF";
	if (nb > 16)
	{
		PrintHex(str, nb / 16);
		PrintHex(str, nb % 16);
	}
	else if (nb <= 16 && str == 'x')
		write(1, &h1[nb], 1);
	else if (nb <= 16 && str == 'X')
		write(1, &h2[nb], 1);
}

static void ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putnbr(long nb, char str)
{
	size_t	j;

	if (str == 'i' || str == 'd')
		j = (long)nb;
	if (str == 'u')
		j = (size_t)nb;
	if (j < 0)
	{
		ft_putchar('-');
		j = -j;
	}
	else if (j >= 10)
	{
		ft_putnbr(j / 10, str);
		j = j % 10;
	}
	else if (j < 10)
		ft_putchar(j + 48);
}

static void ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*(str++));
}

void	hello(char *str, ...)
{
	va_list	ap;
	int		t;

	t = 0;
	va_start(ap, str);
	while (str[t])
	{
		if (str[t] != '%')
			write(1, &str[t], 1);
		else
		{
			t++;
			if (str[t] == 'c')
				ft_putchar(va_arg(ap, int));
			else if (str[t] == 's')
				ft_putstr(va_arg(ap, char*));
			else if (str[t] == 'd' || str[t] == 'i' || str[t] == 'u')
				ft_putnbr((long)va_arg(ap, int), str[t]);
			else if (str[t] == 'x' || str[t] == 'X')
				PrintHex(str[t],va_arg(ap,int));
			else if (str[t] == 'p')
				putaddr(va_arg(ap,int));
		}
		t++;
	}
}

int main()
{
	hello("my age is %d and %sand %p\n",59,"\nhello hh \n",5);
	printf("\nmy age is %d and %sand %p\n",59,"\nhello hh \n","hh");
}
