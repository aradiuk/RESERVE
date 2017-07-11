#include <stdio.h>

int ft_atoi_base(char *str, char *base);

int main(int argc, char **argv)
{
	printf("%d\n", ft_atoi_base(argv[1], "0123456789abcdef"));
	return(0);
}
