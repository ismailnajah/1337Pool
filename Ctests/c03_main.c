#include <stdio.h>
#include <string.h>

#include "../C03/ex00/ft_strcmp.c"
#include "../C03/ex01/ft_strncmp.c"
#include "../C03/ex02/ft_strcat.c"

int main()
{
#if 1
	char s1[20] = "hello ";
	char s2[]= {'h','e','l', 'l', 'b', 'c', 0};

	printf("\tstrcmp(\"%s\", \"%s\") : %d\n", s1, s2, strcmp(s1, s2));
	printf("\tft_strcmp(\"%s\", \"%s\") : %d\n", s1, s2, ft_strcmp(s1, s2));
	printf("\n");
	
	unsigned int n = 4;
	printf("\tstrncmp(\"%s\", \"%s\") : %d\n", s1, s2, strncmp(s1, s2, n));
	printf("\tft_strncmp(\"%s\", \"%s\") : %d\n", s1, s2, ft_strncmp(s1, s2, n));
	printf("\n");


	char z1[10] = "hello ";
	printf("\tstrcat(\"%s\", \"%s\") : %s\n", s1, s2, strcat(s1, s2));
	printf("\tft_strcmp(\"%s\", \"%s\") : %s\n", z1, s2, ft_strcat(z1, s2));
	printf("\n");
	

#endif
	return 0;
}
