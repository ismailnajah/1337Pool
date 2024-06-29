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
#include "../C02/ex11/ft_putstr_non_printable.c"
//#include "../C02/ex12/ft_print_memory.c"

void header(char *str){
	write(1, str, strlen(str));
}

int main()
{
#if 1
	//testing ex00
	char src[] = "Hello, Poolers";
	char dest01[16];
	char dest02[16];
	header("------------------- Testing ex00 ------------------------\n");
	printf("original strcpy : %s\n", strcpy(dest01, src));
	printf("  our ft_strcpy : %s\n", ft_strcpy(dest02, src));
	printf("\n");

	//testing ex01
	char dest11[16];
	char dest12[16];
	header("------------------- Testing ex01 ------------------------\n");
	printf("original strncpy : %s\n", strncpy(dest11, src, 5));
	printf("  our ft_strncpy : %s\n", ft_strncpy(dest12, src, 5));
	printf("\n");


	//testing ex02
	char onlyalpha[] = "thisStringHasOnlyAlphabets";
	char withdigits[] = "this string has 4 digits. 1337";
	char empty[] = "";
	char onlydigits[] = "4324345553222";
	header("------------------- Testing ex02 ------------------------\n");
	printf("ft_str_is_alpha(\"%s\"): %d\n", onlyalpha, ft_str_is_alpha(onlyalpha));
	printf("ft_str_is_alpha(\"%s\"): %d\n", withdigits, ft_str_is_alpha(withdigits));
	printf("ft_str_is_alpha(\"%s\"): %d\n", empty, ft_str_is_alpha(empty));
	printf("ft_str_is_alpha(\"%s\"): %d\n", onlydigits, ft_str_is_alpha(onlydigits));

	//testing ex03
	header("------------------- Testing ex03 ------------------------\n");
	printf("ft_str_is_numeric(\"%s\"): %d\n", onlyalpha, ft_str_is_numeric(onlyalpha));
	printf("ft_str_is_numeric(\"%s\"): %d\n", withdigits, ft_str_is_numeric(withdigits));
	printf("ft_str_is_numeric(\"%s\"): %d\n", empty, ft_str_is_numeric(empty));
	printf("ft_str_is_numeric(\"%s\"): %d\n", onlydigits, ft_str_is_numeric(onlydigits));
	printf("\n");


	//testing ex04
	header("------------------- Testing ex04 ------------------------\n");
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
	header("------------------- Testing ex05 ------------------------\n");
	printf("ft_str_is_uppercase(\"%s\"): %d\n", uppercase, ft_str_is_uppercase(uppercase));	
	printf("ft_str_is_uppercase(\"%s\"): %d\n", lowercase, ft_str_is_uppercase(lowercase));	
	printf("ft_str_is_uppercase(\"%s\"): %d\n", empty, ft_str_is_uppercase(empty));	
	printf("ft_str_is_uppercase(\"%s\"): %d\n", singleupper, ft_str_is_uppercase(singleupper));	
	printf("ft_str_is_uppercase(\"%s\"): %d\n", singlelower, ft_str_is_uppercase(singlelower));	
	printf("\n");

	//testing ex06
	char normal[] = "This is @ normal $ string 123342 )(^&*$|\\";
	char special[] = "hello\n"; 
	header("------------------- Testing ex06 ------------------------\n");
	printf("ft_str_is_printable(\"%s\"): %d\n", normal, ft_str_is_printable(normal));	
	printf("ft_str_is_printable(\"%s\"): %d\n", empty, ft_str_is_printable(empty));	
	printf("ft_str_is_printable(\"%s\"): %d\n", special, ft_str_is_printable(special));	
	printf("\n");

	//testing ex07
	header("------------------- Testing ex07 ------------------------\n");
	char test[] = "this is a test";
	printf("ft_strupcase(\"%s\"): ", test);
	printf("%s\n", ft_strupcase(test));
	printf("\n");

	//testing ex08
	header("------------------- Testing ex08 ------------------------\n");
	printf("ft_strlowcase(\"%s\"): ", test);
	printf("%s\n", ft_strlowcase(test));
	printf("\n");

	//testing ex09
	header("------------------- Testing ex09 ------------------------\n");
	char capitalize[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	printf("ft_strcapitalize(\"%s\"): ", capitalize);
	printf("%s\n", ft_strcapitalize(capitalize));
	printf("\n");

	//testing ex10	
	header("------------------- Testing ex10 ------------------------\n");
	char src_strlcpy[] = "hello";
	unsigned int dest_size = 10;
	char dest_strlcpy1[dest_size];
	char dest_strlcpy2[dest_size];
	printf("     strlcpy(%s) : %lu\n", src_strlcpy, strlcpy(dest_strlcpy1, src_strlcpy, dest_size));
	printf("			- dest_strlpy1 = %s\n", dest_strlcpy1);

	printf("  ft_strlcpy(%s) : %d\n", src_strlcpy, ft_strlcpy(dest_strlcpy2, src_strlcpy, dest_size));
	printf("			- dest_strlpy2 = %s\n", dest_strlcpy2);
	printf("\n");

	//testing ex11	
	header("------------------- Testing ex11 ------------------------\n");
	//char ex11_str[] = "Coucou\ntu vas\t bien \v %*$#@^&242745? \r";
	
	//ft_putstr_non_printable(ex11_str);
	for (int i=0; i<=255; i++)
			nonprint(i);

	write(1, "\n\n", 2);

#endif
#if 0
	//testing ex12
	header("------------------- Testing ex12------------------------\n");
	char memory[] = "Bonjour les aminches\t\n\tc. est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ";
	unsigned int memory_size = 1000;
	ft_print_memory((void*) memory, memory_size);
#endif
	return 0;

}
