#include <stdio.h>

int main(int ac, char **av)
{
	char *str = "";

	write(1, &str, 1);
	write(1, "\n", 1);
	printf("%p\n", str);
}
