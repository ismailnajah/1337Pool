#include <stdio.h>
#include <string.h>

#include "../C03/ex00/ft_strcmp.c"
#include "../C03/ex01/ft_strncmp.c"
#include "../C03/ex02/ft_strcat.c"
#include "../C03/ex03/ft_strncat.c"
#include "../C03/ex04/ft_strstr.c"
#include "../C03/ex05/ft_strlcat.c"

#include "../C00/ex07/ft_putnbr.c"

void test_strlcat()
{
    // Test cases
    struct TestCase {
        const char *dest;
        const char *src;
        size_t size;
    };
    
    struct TestCase tests[] = {
        {"", "", 10},
        {"Hello, ", "world!", 15},
        {"This is a ", "test", 8},
        {"Destination string longer than buffer", "Source", 20},
        {"This is the destination string", "This is the source string", 40},
        {"Short", "Longer source string", 10},
        {"Overwriting the buffer with a longer source", "Short", 10},
        {"Appending to an existing buffer", "Append", 20},
        {"Testing if the function works as expected", "Indeed, it should work", 30},
        {"Buffer is larger than destination string", "Source string", 50}
    };
    
    size_t num_tests = sizeof(tests) / sizeof(tests[0]);
    
    // Iterate over each test case
    for (size_t i = 0; i < num_tests; ++i) {
        char dest[100];  // Adjust the size according to your needs
        char dest_ft[100];  // Adjust the size according to your needs
        
        strcpy(dest, tests[i].dest);
        strcpy(dest_ft, tests[i].dest);
        
        size_t result_strlcat = strlcat(dest,(char*) tests[i].src, tests[i].size);
        size_t result_ft_strlcat = ft_strlcat(dest_ft,(char*) tests[i].src, tests[i].size);
       	if(result_strlcat == result_ft_strlcat)
		{	
        	printf("{\n");
        	printf("    // Test case %zu\n", i + 1);
       		printf("    .dest = \"%s\",\n", tests[i].dest);
        	printf("    .src = \"%s\",\n", tests[i].src);
        	printf("    .size = %zu,\n", tests[i].size);
        	printf("    .expected_strlcat = %zu,\n", result_strlcat);
	        printf("    .actual_strlcat = %zu,\n", strlen(dest));
	        printf("    .expected_ft_strlcat = %zu,\n", result_ft_strlcat);
    	    printf("    .actual_ft_strlcat = %zu,\n", strlen(dest_ft));
			printf("    .expected_destination = \"%s\",\n", dest);
        	printf("    .actual_destination = \"%s\",\n", dest_ft);
			printf("},\n");
		}
    }
}



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
	test_strlcat();
#endif
	return 0;
}
