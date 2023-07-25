#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

int main(int argc, char* argv[])
{
	int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	struct linklist_stack *stack;

	stack = stack_creat();

	for (int i=0; i<10; i++)
		stack_push(stack, data[i]);

	stack_pop(stack);

	fprintf(stdout, "size = %d, value = %d\n",
		stack->size, stack->top->val);

	stack_destroy(stack);
		
	exit(0);
}
