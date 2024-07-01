#include <stdio.h>
#include <string.h>
#include "../C03/ex05/ft_strlcat.c"

int main() {
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
        
        size_t result_strlcat = strlcat(dest, tests[i].src, tests[i].size);
        size_t result_ft_strlcat = ft_strlcat(dest_ft, tests[i].src, tests[i].size);
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
    
    return 0;
}

