#include <stdio.h>
#include <string.h>

#include "../C03/ex00/ft_strcmp.c"
#include "../C03/ex01/ft_strncmp.c"
int main()
{
#if 1
	char s1[] = "helle";
	char s2[] = "hell";
	printf("\tstrcmp(\"%s\", \"%s\") : %d\n", s1, s2, strcmp(s1, s2));
	printf("\tft_strcmp(\"%s\", \"%s\") : %d\n", s1, s2, ft_strcmp(s1, s2));
	printf("\n");
	
	unsigned int n = 5;
	printf("\tstrncmp(\"%s\", \"%s\") : %d\n", s1, s2, strncmp(s1, s2, n));
	printf("\tft_strncmp(\"%s\", \"%s\") : %d\n", s1, s2, ft_strncmp(s1, s2, n));



#endif
	return 0;
}
