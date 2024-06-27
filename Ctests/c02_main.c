#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "../C02/ex00/ft_strcpy.c"

int main()
{
	//testing ex00
	char *src = "Hello, Poolers";
	char dest1[16];
	char dest2[16];
	printf("original strcpy : %s\n", strcpy(dest1, src));
	printf("  our ft_strcpy : %s\n", ft_strcpy(dest2, src));
	printf("\n");
	return 0;
}
