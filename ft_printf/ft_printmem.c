#include "ft_printf.h"

int	ft_pmem(int str)
{
	long	s;
	int					c;
	char				*hex;

	s = (long)str;
	c = 0;
	hex = "0123456789abcdef";
	if (!s)
	{
		c += 3;
		write(1, "0x0", 3);
		return (c);
	}
	write(1, "0x", 2);
	c += 2;
	while (s)
	{
		write(1, &hex[s % 16], 1);
		s /= 16;
		c++;
	}
	return (c);
}
