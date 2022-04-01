#include <iostream>
#define MAX 5

int peek(int *stack) {
	int i = 0;
	while(stack[i] != '\0') {
		i++;
	}
	return i;
}
void push(int *stack, int **top, int value) {
	if(peek(stack) < MAX) {
		if((*top) == nullptr) {
			*stack = value;
			(*top) = stack; 
		} else {
			(*top) = ((*top) + 1);
			*(*top) = value;	
		}
	} else std::cout << "Stack Full\n";
}
void pop(int *stack, int **top) {
	if((*top) == nullptr) std::cout << "Stack Empty\n";
	else if(peek(stack) == 1) {
		stack[0] = '\0';
		(*top) = nullptr;
	} else {
		*(*top) = '\0';
		(*top) = ((*top) - 1);
	}
}
void PrintStack(int **top) {
	int *cur = (*top);
	int i = 1;
	while(*cur != '\0') {
		std::cout << *cur << "\n";
		cur = (cur - 1);
	}
	std::cout << "===============================\n";
}
int main() {
	int stack[MAX] = {NULL}, *top = nullptr;
	
	push(stack, &top, 1);
	push(stack, &top, 2);
	push(stack, &top, 3);
	push(stack, &top, 4);
	push(stack, &top, 5);
	push(stack, &top, 6);
	
	PrintStack(&top);
	
	pop(stack, &top);
	pop(stack, &top);
	
	PrintStack(&top);
	
	push(stack, &top, 7);
	
	PrintStack(&top);
	
	return 0;
}
