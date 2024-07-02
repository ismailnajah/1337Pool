#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#include "../C04/ex03/ft_atoi.c"

// Test cases
void ft_atoi_run_tests() {
    const char *test_cases[] = {
        "123",
        "   \t\n\r\f\v  456",
        "   +789",
        "  -321",
        " +--42",
        "  ---987",
        " \t\n\r\f\v +12abc34",
        "   \t\n\r\f\v --def567",
        "",
        "  \t\n\r\f\v ",
		"    \t \n \v    -922337203685477"
    };

    int expected_results[] = {
        123,
        456,
        789,
        -321,
        42,
        -987,
        12,
        0,
        0,
        0,
		atoi(test_cases[10]),
    };
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    bool all_passed = true;

    for (int i = 0; i < num_tests; i++) {
        const char *input_str = test_cases[i];
        int expected_output = expected_results[i];
        int result = ft_atoi((char*)input_str);

        if (result != expected_output) {
            printf("Test case %d failed: Expected %d, got %d\n", i+1, expected_output, result);
            all_passed = false;
        } else {
            printf("Test case %d passed\n", i+1);
        }
    }

    if (all_passed) {
        printf("All test cases passed!\n");
    } else {
        printf("Some test cases failed.\n");
    }
}
