#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "../C02/ex00/ft_strcpy.c"
#include "../C02/ex01/ft_strncpy.c"

int main()
{
	//testing ex00
	char *src = "Hello, Poolers";
	char dest01[16];
	char dest02[16];
	printf("original strcpy : %s\n", strcpy(dest01, src));
	printf("  our ft_strcpy : %s\n", ft_strcpy(dest02, src));
	printf("\n");

	//testing ex01
	char dest11[16];
	char dest12[16];
	printf("original strncpy : %s\n", strncpy(dest11, src, 5));
	printf("  our ft_strncpy : %s\n", ft_strncpy(dest12, src, 5));


	return 0;
}
