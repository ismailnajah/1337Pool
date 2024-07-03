#include <stdio.h>

#include "../C05/ex02/ft_iterative_power.c"
#include "../C05/ex03/ft_recursive_power.c"
// Structure to hold a test case
typedef struct {
    int x;
    int n;
    int expected_result;
} TestCase;

// Array of test cases
TestCase test_cases[] = {
    // Basic Cases
    {2, 0, 1},
    {3, 1, 3},
    {0, 5, 0},

    // Edge Cases
    {2, -3, 0},         // 1 / power(2, 3) = 1 / 8 = 0.125
    {-2, 4, 16},        // power(-2, 4) = 16
    {-2, 5, -32},       // power(-2, 5) = -32

    // Boundary Cases
    {2, 15, 32768},     // 2^15 = 32768
    {2, -15, 0},        // 1 / 2^15 = 1 / 32768 = very small number (but not exactly 0)

    // Special Cases
    {1, 100, 1},
    {-1, 11, -1},

    // Additional Cases
    {10, 10, 1000000000},   // 10^10 = 10000000000 (This will overflow, so we use a smaller value)
    {10, 6, 1000000},       // 10^6 = 1000000
};

int main() {
    int num_test_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    
    printf("Number of Test Cases: %d\n", num_test_cases);
    printf("Running Test Cases...\n");
    
    for (int i = 0; i < num_test_cases; ++i) {
        int x = test_cases[i].x;
        int n = test_cases[i].n;
        int expected_result = test_cases[i].expected_result;
        
        // Replace this with your power(x, n) function call
        // int actual_result = power(x, n);
        // For demonstration, print the results instead
        int actual_result = ft_recursive_power(x, n);  // Placeholder for actual function result
        
        printf("Test Case %d: power(%d, %d) = %d, Expected: %d\n",
               i + 1, x, n, actual_result, expected_result);
    }
    
    return 0;
}

