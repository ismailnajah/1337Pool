#include <stdio.h>
#include <string.h>
#include "../C09/ex02/ft_split.c"

#define ON 0

#if ON
void ft_putchar(char c);
void ft_swap(int *a, int *b);
void ft_putstr(char *str);
int ft_strlen(char *str);
int ft_strcmp(char *s1, char *s2);
#endif

int main(int ac, char **av)
{
	(void) ac;
#if ON
	ft_putstr("Hello from lib\n");
	ft_putchar('C');
	int i = ft_strlen("this is a C09 test");
	int b = ft_strcmp("hellorc", "hellob");
	ft_swap(&i, &b);
#endif
	char **words_list = ft_split(av[1], av[2]);
	for(int i = 0; words_list[i]; i++)
		printf("\"%s\" : %lu\n", words_list[i], strlen(words_list[i]));

	return 0;
}
