#include "../C13/ex00/ft_btree.h"

#include "../C13/ex00/btree_create_node.c"

int *node(int data)
{
	int *elem = malloc(sizeof(int));
	*elem = data;
	return elem;
}

int main()
{
	t_btree *root;
	root = btree_create_node(node(10));
	return 0;
}
