#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "../C02/ex00/ft_strcpy.c"
#include "../C02/ex01/ft_strncpy.c"
#include "../C02/ex02/ft_str_is_alpha.c"
#include "../C02/ex03/ft_str_is_numeric.c"

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
	printf("\n");

	//testing ex02
	char *nodigits = "this string has no digits.";
	char *withdigits = "this string has 4 digits. 1337";
	char *empty = "";
	char *onlydigits = "4324345553222";
	printf("ft_str_is_alpha(\"%s\"): %d\n", nodigits, ft_str_is_alpha(nodigits));
	printf("ft_str_is_alpha(\"%s\"): %d\n", withdigits, ft_str_is_alpha(withdigits));
	printf("ft_str_is_alpha(\"%s\"): %d\n", empty, ft_str_is_alpha(empty));
	printf("ft_str_is_alpha(\"%s\"): %d\n", onlydigits, ft_str_is_alpha(onlydigits));
	printf("\n");

	//testing ex03
	printf("ft_str_is_numeric(\"%s\"): %d\n", nodigits, ft_str_is_numeric(nodigits));
	printf("ft_str_is_numeric(\"%s\"): %d\n", withdigits, ft_str_is_numeric(withdigits));
	printf("ft_str_is_numeric(\"%s\"): %d\n", empty, ft_str_is_numeric(empty));
	printf("ft_str_is_numeric(\"%s\"): %d\n", onlydigits, ft_str_is_numeric(onlydigits));
	


	return 0;
}
