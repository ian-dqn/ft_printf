#include "libft.h"

int	ft_intcount(long long n)
{
	int	count;

	count = 0;
	if (n < 0)
		n *= -1;
	while (n >= 10)
	{
		count++;
		n /= 10;
	}
	return (++count);
}
