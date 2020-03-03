#include "libft.h"

int		ft_hexacount(unsigned int n, unsigned int base_size)
{
	int i;

	i = 1;
	while (n >= base_size)
	{
		n /= base_size;
		i++;
	}
	if (i > 8)
		i = 8;
	return (i);
}
