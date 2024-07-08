#include <stdio.h>

void ft_putchar(char c);
void ft_swap(int *a, int *b);
void ft_putstr(char *str);
int ft_strlen(char *str);
int ft_strcmp(char *s1, char *s2);

int main()
{
	ft_putstr("Hello from lib\n");
	ft_putchar('C');
	int i = ft_strlen("this is a C09 test");
	int b = ft_strcmp("hellorc", "hellob");
	ft_swap(&i, &b);
	return 0;
}
