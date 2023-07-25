/* 
 * simple binary tree
 *
 */

#include "tree.h"

/* creat tree node */
struct tree_node *new_tree_node(int val)
{
	struct tree_node *node;

	node = (struct tree_node *)malloc(sizeof(struct tree_node));
	node->val = val;
	node->height = 0;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void destroy_tree_node(struct tree_node *node)
{
	free(node);
	node = NULL;
}

int *level_order(struct tree_node *root, int *size)
{
	/* queue */
	int front = 0, rear = 0;
	int index = 0, *arr;
	struct tree_node *node;
	struct tree_node **queue;

	queue = (struct tree_node **)malloc(sizeof(struct tree_node *) * MAX_NODE_SIZE);
	arr = (int *)malloc(sizeof(int) * MAX_NODE_SIZE);
	
	queue[front++] = root;
	
	while (front < rear) {
		/* pop */
		node = queue[front++];
		arr[index++] = node->val;

		if (node->left)
			queue[rear++] = node->left;
		if (node->right)
			queue[rear++] = node->right;
	}

	*size = index;
	arr = realloc(arr, sizeof(int) * (*size));

	free(queue);
	queue = NULL;

	return arr;
}

/*
 * @arr: store tree value
 *
 */
void pre_order(struct tree_node *root, int *size, int *arr)
{
	if (!root)
		return;

	/* order: root -> left -> right */
	arr[(*size)++] = root->val;
	pre_order(root->left, size, arr);
	pre_order(root->right, size, arr);	
}

void in_order(struct tree_node *root, int *size, int *arr)
{
	if (!root)
		return;
	
	/* order: left -> root -> right */
	in_order(root->left, size, arr);
	arr[(*size)++] = root->val;
	in_order(root->right, size, arr);
}

void post_order(struct tree_node *root, int *size, int *arr)
{
	if (!root)
		return;
	/* order: left -> right -> root */
	post_order(root->left, size, arr);
	post_order(root->right, size, arr);
	arr[(*size)++] = root->val;
}

