#include "../C12/ex00/ft_list.h"

#include "../C12/ex00/ft_create_elem.c"
#include "../C12/ex01/ft_list_push_front.c"
#include "../C12/ex02/ft_list_size.c"
#include "../C12/ex03/ft_list_last.c"
#include "../C12/ex04/ft_list_push_back.c"
#include "../C12/ex05/ft_list_push_strs.c"
#include "../C09/ex02/ft_split.c"

#include <stdio.h>
#include <stdlib.h>
void print_llist(t_list *node)
{
	while (node)
	{
		printf("%d ", *((int*)node->data));
		node = node->next;
	}
	printf("\n");
}

int	*node(int nb)
{
	int *p = malloc(sizeof(int));
	*p = nb;
	return (p);
}

void ft_print_strings(t_list *head)
{
	while (head)
	{
		printf("%s <>", (char*)head->data);
		head = head->next;
	}
}

int main()
{
	t_list *list = NULL;

	ft_list_push_back(&list, node(55));
	ft_list_push_front(&list, node(1337));
	ft_list_push_front(&list, node(98));
	ft_list_push_front(&list, node(10));
	ft_list_push_front(&list, node(2));
	ft_list_push_front(&list, node(5));
	
	ft_list_push_back(&list, node(99));

	print_llist(list);
	
	printf("size: %d\n", ft_list_size(list));

	printf("last elem: %d\n", *((int*)ft_list_last(list)->data));
	
	char *str = "";
	char **words_list = ft_split(str, " ");
	int i = 0;
	while (words_list[i])
		i++;
	ft_print_strings(ft_list_push_strs(i, words_list));
	
	return (0);
}
