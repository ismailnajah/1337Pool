#include "../C11/ex00/ft_foreach.c"
#include "../C11/ex01/ft_map.c"
#include "../C11/ex02/ft_any.c"
#include "../C11/ex03/ft_count_if.c"
#include "../C11/ex04/ft_is_sort.c"
#include "../C11/ex06/ft_sort_string_tab.c"

#include "../C07/ex02/ft_ultimate_range.c"
#include "../C04/ex02/ft_putnbr.c"
#include "../C04/ex01/ft_putstr.c"
#include "../C05/ex00/ft_iterative_factorial.c"
#include "../C07/ex05/ft_split.c"
#include "../C02/ex03/ft_str_is_numeric.c"
#include "../C02/ex04/ft_str_is_lowercase.c"
#include "../C02/ex05/ft_str_is_uppercase.c"

void show(int n)
{
	ft_putnbr(n);
	ft_putstr(" ");
}

int ascending(int a, int b)
{
	return a - b;
}

int descending(int a, int b)
{
	return b - a;
}

int main()
{
	int *range;
	int length = ft_ultimate_range(&range, 1, 10);
	ft_putstr("\n--- ex00 ---\n");
	ft_foreach(range, length, &show);

	ft_putstr("\n--- ex01 ---\n");
	int *power_range = ft_map(range, length, &ft_iterative_factorial);
	ft_foreach(power_range, length, &show);
	
	
	
	ft_putstr("\n--- ex02 ---\n");
	char *str = "z y c b a f x t";
	int word_count = 7;
	char **words_list = ft_split(str, " ");
	show(ft_any(words_list, &ft_str_is_numeric));
	show(ft_any(words_list, &ft_str_is_lowercase));
	show(ft_any(words_list, &ft_str_is_uppercase));


	ft_putstr("\n--- ex03 ---\n");
	show(ft_count_if(words_list, word_count, &ft_str_is_numeric));


	ft_putstr("\n--- ex04 ---\n");
	int tab[] = {10 , 9, 8, 6, 5};
	show(ft_is_sort(tab, 5, &ascending));
	show(ft_is_sort(tab, 5, &descending));


	ft_putstr("\n--- ex06 ---\n");
	ft_sort_string_tab(words_list);
	for(int i=0; words_list[i]; i++)
	{
		ft_putstr(words_list[i]);
		ft_putstr(" ");
	}
	free(range);
	free(power_range);
	for(int i=0; words_list[i]; i++)
		free(words_list[i]);
	free(words_list);
	return (0);
}
