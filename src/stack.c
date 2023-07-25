#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"



/* create new stack */
struct linklist_stack* stack_creat()
{
	struct linklist_stack* stack = (struct linklist_stack*)malloc(sizeof(struct linklist_stack));
	
	stack->size = 0;
	stack->top = NULL;

	return stack;
}

/* destroy stack */
void stack_destroy(struct linklist_stack* stack)
{
	while (stack->top != NULL) {
		ListNode* tmp = stack->top->next;
		free(stack->top);
		stack->top = tmp;
	}

	free(stack);
}

static int stack_size(struct linklist_stack* stack)
{
	return stack->size;
}

static int stack_empty(struct linklist_stack* stack)
{
	return (stack->size == 0) ? 0 : 1;
}

/* access stack first */
static int stack_peek(struct linklist_stack* stack)
{
	while (stack_size(stack) != 0)
		return stack->top->val;

	return -1;
}

void stack_push(struct linklist_stack* stack, int num)
{
	if (stack) {
		ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
		tmp->next = stack->top;
		tmp->val = num;
		stack->top = tmp;
		stack->size++; 
	}
}

int stack_pop(struct linklist_stack* stack)
{
	if (stack_size(stack) == 0)
		return -1;

	if (stack) {
		int val = stack_peek(stack);
		ListNode* tmp = stack->top;
		stack->top = tmp->next;
		free(tmp);
		stack->size--;
			
		return val;
	}

	return -1;
}


