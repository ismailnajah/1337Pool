#include "../C12/ex00/ft_list.h"

#include "../C12/ex00/ft_create_elem.c"
#include "../C12/ex01/ft_list_push_front.c"
#include "../C12/ex02/ft_list_size.c"
#include "../C12/ex03/ft_list_last.c"

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

int main()
{
	t_list *list = NULL;

	list = ft_create_elem(node(55));
	ft_list_push_front(&list, node(1337));
	ft_list_push_front(&list, node(98));
	ft_list_push_front(&list, node(10));
	ft_list_push_front(&list, node(2));
	ft_list_push_front(&list, node(5));
	print_llist(list);
	
	printf("size: %d\n", ft_list_size(list));

	printf("last elem: %d\n", *((int*)ft_list_last(list)->data));
	return (0);
}
