#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#include "../C04/ex04/ft_putnbr_base.c"

void ft_putstr(char *str);
void ft_putnbr(int n);

// Test cases
void ft_putnbr_base_run_tests() {
    const char *test_bases[] = {
        "01",
        "012345678",
        "0123456789",
        "0123456789abcdef",
        "poneyvif",
        "hello",
        "thisbase",
        "%$^&@!)(\\",
        "pos+",
        "-negativ",
    };
   	int num_tests = sizeof(test_bases) / sizeof(test_bases[0]);
	srand(time(NULL));
	int number = rand() % 20;
    for (int i = 0; i < num_tests; i++) {
        const char *base = test_bases[i];
		ft_putstr("Test case ");
		ft_putnbr(i+1);

		ft_putstr("\t--- n=");
		ft_putnbr(number);
		ft_putstr(", base=\"");
		ft_putstr((char *) base);
		ft_putstr("\"--- :     ");
		
		ft_putnbr_base(number , (char *)base);
		ft_putstr("\n");
    }
}
