#include "../C13/ex00/ft_btree.h"

#include "../C13/ex00/btree_create_node.c"
#include "../C13/ex01/btree_apply_prefix.c"
#include "../C13/ex02/btree_apply_infix.c"
#include "../C13/ex03/btree_apply_suffix.c"

#include <stdio.h>

typedef struct s_queue
{
	t_btree	*item;
	struct s_queue	*next;
}	t_queue;

void	ft_en_queue(t_queue **queue, t_btree *item)
{
	t_queue	*elem;
	t_queue	*node;

	elem = malloc(sizeof(struct s_queue));
	elem->item = item;
	elem->next = NULL;
	node = *queue;
	if (!(*queue))
		*queue = elem;
	else
	{
		while(node->next)
			node = node->next;
		node->next = elem;
	}
}

t_btree	*ft_de_queue(t_queue **queue)
{
	t_btree *item;
	t_queue *node;

	if (!(*queue))
		return NULL;
	node = (*queue);
	item = node->item;
	*queue = (*queue)->next;
	free(node);
	return (item);
}


int *item(int data)
{
	int *elem = malloc(sizeof(int));
	*elem = data;
	return elem;
}

t_btree	*create_tree(int max)
{
	int i = 1;
	t_queue *queue = NULL;
	t_btree *root = btree_create_node(item(i));
	t_btree *node = root;
	i++;
	while (node)
	{
		if (i <= max)
		{
			node->left = btree_create_node(item(i));
			i++;
		}
		if (i + 1 <= max)
		{
			node->right = btree_create_node(item(i));
			i++;
		}
		if (node->left)
			ft_en_queue(&queue, node->left);
		if(node->right)
			ft_en_queue(&queue, node->right);
		node = ft_de_queue(&queue);
	}
	return (root);
}

void	ft_putint(void *item)
{
	printf("%d -> ", *((int*)item));
}
void ft_print_btree(t_btree *root)
{
	if(!root)
		return ;
	if (root->left || root->right)
		printf("root: %d \n", *((int*)root->item));
	if (root->left)
		printf("\tleft : %d\n", *((int*)root->left->item));
	if (root->right)
		printf("\tright: %d\n", *((int*)root->right->item));
	ft_print_btree(root->left);
	ft_print_btree(root->right);
}

int main()
{
	t_btree *root = create_tree(6);
	ft_print_btree(root);
	printf("---------------------------\n");
	printf("prefix (a.k.a preorder):\t");
	btree_apply_prefix(root, &ft_putint);
	printf("\n");
	
	printf("infix (a.k.a inorder):\t\t");
	btree_apply_infix(root, &ft_putint);
	printf("\n");

	printf("suffix (a.k.a postorder):\t");
	btree_apply_suffix(root, &ft_putint);
	printf("\n");



	//ft_print_btree(root);
	return 0;
}
