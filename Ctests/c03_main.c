#include <stdio.h>
#include <string.h>

#include "../C03/ex00/ft_strcmp.c"
#include "../C03/ex01/ft_strncmp.c"
#include "../C03/ex02/ft_strcat.c"
#include "../C03/ex03/ft_strncat.c"
#include "../C03/ex04/ft_strstr.c"
#include "../C03/ex05/ft_strlcat.c"

#include "../C00/ex07/ft_putnbr.c"

int main()
{
#if 0
	char s1[20] = "hello ";
	char s2[]= {'h','e','l', 'l', 'b', 'c', 0};

	printf("\tstrcmp(\"%s\", \"%s\") : %d\n", s1, s2, strcmp(s1, s2));
	printf("\tft_strcmp(\"%s\", \"%s\") : %d\n", s1, s2, ft_strcmp(s1, s2));
	printf("\n");
	
	unsigned int n = 4;
	printf("\tstrncmp(\"%s\", \"%s\") : %d\n", s1, s2, strncmp(s1, s2, n));
	printf("\tft_strncmp(\"%s\", \"%s\") : %d\n", s1, s2, ft_strncmp(s1, s2, n));
	printf("\n");


	char s11[20] = "hello ";
	printf("\tstrcat(\"%s\", \"%s\") : %s\n", s1, s2, strcat(s1, s2));
	printf("\tft_strcat(\"%s\", \"%s\") : %s\n", s11, s2, ft_strcat(s11, s2));
	printf("\n");
	
	char cat_s1[20] = "hello ";
	char cat_z1[20] = "hello ";
	char cat_src[]= {'h','e','l', 'l', 'b', 'c', '0'};
	unsigned int nb = 50;
	printf("\tstrncat(\"%s\", \"%s\") : %s\n", cat_s1, cat_src, strncat(cat_s1, cat_src, nb));
	printf("\tft_strncat(\"%s\", \"%s\") : %s\n", cat_z1, cat_src, ft_strncat(cat_z1, cat_src, nb));
	printf("\n");

	char haystack[] = "this is heystack string";
	char needle[] = "tack";
	printf("\tstrstr(\"%s\", \"%s\") : %s\n", haystack, needle, strstr(haystack, needle));
	printf("\tft_strstr(\"%s\", \"%s\") : %s\n", haystack, needle, ft_strstr(haystack, needle));
	printf("\n");

#endif
#if 1
	char lcat_s1[7] = "hello";
	char lcat_z1[7] = "hello";
	char lcat_src[]= "this is a test";
	int dest_size = sizeof(lcat_s1); 
	printf("\tstrlcat(\"%s\", \"%s\", %d) : ",lcat_s1, lcat_src, dest_size);
	int result = strlcat(lcat_s1, lcat_src, dest_size); 
	printf("%s ->  %d\n", lcat_s1, result);
	
	printf("\tft_strlcat(\"%s\", \"%s\", %d) : ",lcat_z1, lcat_src, dest_size);
	result = ft_strlcat(lcat_z1, lcat_src, dest_size); 
	printf("%s ->  %d\n", lcat_z1, result);
	printf("\n");
	
#endif
	return 0;
}
