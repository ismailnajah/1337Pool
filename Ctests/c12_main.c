#include "../C12/ex00/ft_list.h"

#include "../C12/ex00/ft_create_elem.c"
#include "../C12/ex01/ft_list_push_front.c"
#include "../C12/ex02/ft_list_size.c"
#include "../C12/ex03/ft_list_last.c"
#include "../C12/ex04/ft_list_push_back.c"
#include "../C12/ex05/ft_list_push_strs.c"
#include "../C12/ex06/ft_list_clear.c"
#include "../C12/ex07/ft_list_at.c"
#include "../C12/ex08/ft_list_reverse.c"
#include "../C12/ex09/ft_list_foreach.c"
#include "../C12/ex10/ft_list_foreach_if.c"

#include "../C09/ex02/ft_split.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	*node(int nb)
{
	int *p = malloc(sizeof(int));
	*p = nb;
	return (p);
}

void ft_putint(void *data)
{
	printf("%d ", *((int*)data));
}
void ft_putstr(void *data)
{
	printf("%s -> ", (char*)data);
}

void upper(void *data)
{
	char *str = (char*)data;
	int i = 0;
	while (str[i])
	{
		if ('a' <= str[i] && str[i] <= 'z')
			str[i] = 'A' + (str[i] - 'a');
		i++;
	}
}

int cmp(int *a, int *b)
{
	return (*a - *b);
}

void ft_abs(void *data)
{
	int *n = (int*)data;
	if (*n < 0)
		*n *= -1;
}

int main()
{
	t_list *list = NULL;

	ft_list_push_back(&list, node(55));
	ft_list_push_front(&list, node(1337));
	ft_list_push_front(&list, node(98));
	ft_list_push_front(&list, node(10));
	ft_list_push_front(&list, node(-15));
	ft_list_push_front(&list, node(2));
	ft_list_push_front(&list, node(5));
	
	ft_list_push_back(&list, node(99));

	//print int list
	ft_list_foreach(list, &ft_putint);
	
	printf("\nsize: %d\n", ft_list_size(list));

	printf("last elem: %d\n", *((int*)ft_list_last(list)->data));
	
	char *str = "hello how are you doing";
	char **words_list = ft_split(str, " ");
	int i = 0;
	while (words_list[i])
		i++;
	t_list *strs_llist = ft_list_push_strs(i, words_list);
	ft_list_foreach(strs_llist, &ft_putstr);


	//ex07
	int index = ft_list_size(list) + 12;
	t_list *node = ft_list_at(list, index);
	if (node)
		printf("\nelement at index %d is: %d\n", index, *((int*)node->data));

	//ex8
	printf("\nreverse the list:\n");
	ft_list_reverse(&list);
	ft_list_reverse(&strs_llist);
	ft_list_foreach(list, &ft_putint);
	printf("\n");
	ft_list_foreach(strs_llist, &ft_putstr);


	//ex10 : ft_list_foreach_if
	printf("\nft_list_foreach_if: ");
	char *data_ref = "you";
	ft_list_foreach_if(strs_llist, &upper, data_ref, &strcmp);
	ft_list_foreach(strs_llist, &ft_putstr);

	int nb = -15;
	ft_list_foreach_if(list, &ft_abs, &nb, &cmp);
	printf("\n");
	ft_list_foreach(list, &ft_putint);

	printf("\n## free the list ##\n");
	ft_list_clear(list, &free);
	ft_list_clear(strs_llist, &free);
	ft_list_clear(NULL, &free);
	strs_llist = NULL;
	list = NULL;
	ft_list_foreach(strs_llist, &ft_putstr);
	return (0);
}
