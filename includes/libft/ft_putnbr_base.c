int	ft_putnbr_hexa(long long n, char *base)
{
	char *base;
	int len;

	len = ft_strlen(base);
	if (n >= len)
	{
		ft_putnbr_hexa((n / len), base);
		ft_putnbr_hexa((n % len), base);
	}
	else
		write(1, &base[n], 1);
	return (1);
}
