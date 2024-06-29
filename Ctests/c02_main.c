#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "../C02/ex00/ft_strcpy.c"
#include "../C02/ex01/ft_strncpy.c"
#include "../C02/ex02/ft_str_is_alpha.c"
#include "../C02/ex03/ft_str_is_numeric.c"
#include "../C02/ex04/ft_str_is_lowercase.c"
#include "../C02/ex05/ft_str_is_uppercase.c"
#include "../C02/ex06/ft_str_is_printable.c"
#include "../C02/ex07/ft_strupcase.c"
#include "../C02/ex08/ft_strlowcase.c"
#include "../C02/ex09/ft_strcapitalize.c"
#include "../C02/ex10/ft_strlcpy.c"

int main()
{

	//testing ex00
	char src[] = "Hello, Poolers";
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
	char onlyalpha[] = "thisStringHasOnlyAlphabets";
	char withdigits[] = "this string has 4 digits. 1337";
	char empty[] = "";
	char onlydigits[] = "4324345553222";
	printf("ft_str_is_alpha(\"%s\"): %d\n", onlyalpha, ft_str_is_alpha(onlyalpha));
	printf("ft_str_is_alpha(\"%s\"): %d\n", withdigits, ft_str_is_alpha(withdigits));
	printf("ft_str_is_alpha(\"%s\"): %d\n", empty, ft_str_is_alpha(empty));
	printf("ft_str_is_alpha(\"%s\"): %d\n", onlydigits, ft_str_is_alpha(onlydigits));
	printf("\n");

	//testing ex03
	printf("ft_str_is_numeric(\"%s\"): %d\n", onlyalpha, ft_str_is_numeric(onlyalpha));
	printf("ft_str_is_numeric(\"%s\"): %d\n", withdigits, ft_str_is_numeric(withdigits));
	printf("ft_str_is_numeric(\"%s\"): %d\n", empty, ft_str_is_numeric(empty));
	printf("ft_str_is_numeric(\"%s\"): %d\n", onlydigits, ft_str_is_numeric(onlydigits));
	printf("\n");


	//testing ex04
	char lowercase[] = "thisisalowercasestring";
	char uppercase[] = "THISISANUPPERCASESTRING";
	char singlelower[] = "a";
	char singleupper[] = "A";
	printf("ft_str_is_lowercase(\"%s\"): %d\n", uppercase, ft_str_is_lowercase(uppercase));	
	printf("ft_str_is_lowercase(\"%s\"): %d\n", lowercase, ft_str_is_lowercase(lowercase));	
	printf("ft_str_is_lowercase(\"%s\"): %d\n", empty, ft_str_is_lowercase(empty));	
	printf("ft_str_is_lowercase(\"%s\"): %d\n", singleupper, ft_str_is_lowercase(singleupper));	
	printf("ft_str_is_lowercase(\"%s\"): %d\n", singlelower, ft_str_is_lowercase(singlelower));	
	printf("\n");
	
	//testing ex05
	printf("ft_str_is_uppercase(\"%s\"): %d\n", uppercase, ft_str_is_uppercase(uppercase));	
	printf("ft_str_is_uppercase(\"%s\"): %d\n", lowercase, ft_str_is_uppercase(lowercase));	
	printf("ft_str_is_uppercase(\"%s\"): %d\n", empty, ft_str_is_uppercase(empty));	
	printf("ft_str_is_uppercase(\"%s\"): %d\n", singleupper, ft_str_is_uppercase(singleupper));	
	printf("ft_str_is_uppercase(\"%s\"): %d\n", singlelower, ft_str_is_uppercase(singlelower));	
	printf("\n");

	//testing ex06
	char normal[] = "This is @ normal $ string 123342 )(^&*$|\\";
	char special[] = "hello\n"; 
	printf("ft_str_is_printable(\"%s\"): %d\n", normal, ft_str_is_printable(normal));	
	printf("ft_str_is_printable(\"%s\"): %d\n", empty, ft_str_is_printable(empty));	
	printf("ft_str_is_printable(\"%s\"): %d\n", special, ft_str_is_printable(special));	
	printf("\n");

	//testing ex07
	char test[] = "this is a test";
	printf("ft_strupcase(\"%s\"): ", test);
	printf("%s\n", ft_strupcase(test));
	printf("\n");

	//testing ex08
	// test is now all upper case
	printf("ft_strlowcase(\"%s\"): ", test);
	printf("%s\n", ft_strlowcase(test));
	printf("\n");

	//testing ex09
	char capitalize[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	printf("ft_strcapitalize(\"%s\"): ", capitalize);
	printf("%s\n", ft_strcapitalize(capitalize));
	printf("\n");

	//testing ex10
	char src_strlcpy[] = "hello";
	unsigned int dest_size = 2;
	char dest_strlcpy1[dest_size];
	char dest_strlcpy2[dest_size];
	printf("     strlcpy(%s) : %lu\n", src_strlcpy, strlcpy(dest_strlcpy1, src_strlcpy, dest_size));
	printf("			- dest_strlpy1 = %s\n", dest_strlcpy1);

	printf("  ft_strlcpy(%s) : %d\n", src_strlcpy, ft_strlcpy(dest_strlcpy2, src_strlcpy, dest_size));
	printf("			- dest_strlpy2 = %s\n", dest_strlcpy2);
	printf("\n");



	return 0;
}
