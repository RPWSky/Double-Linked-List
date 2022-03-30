#include <iostream>

struct Node {
	int data;
	Node *next, *prev;
};

struct Stack {
	int value;
	Stack *link;
};
//Create
Stack *create(int val) {
	Stack *newStack = new Stack;
	newStack->value = val;
	newStack->link = nullptr; 
	return newStack;
}
//Insertion
void push(Stack **top, int val) {
	if((*top) == nullptr) {
		(*top) = create(val);
		std::cout << "Berhasil menambahkan Stack" << std::endl;
	}else{
		Stack *newStack = create(val);
		newStack->link = (*top);
		(*top) = newStack;
		std::cout << "Berhasil menambahkan Top" << std::endl;
	}
}
//Deletion
 void pop(Stack **top) {
	if((*top) == nullptr) std::cout << "Tidak ada yang bisa dihapus" << std::endl;
	else{
		if((*top)->link == nullptr) {
			delete (*top);
			(*top) = nullptr;
			std::cout << "Stack sudah dihapus" << std::endl;
		}else{
			Stack *del = (*top);
			(*top) = (*top)->link;
			del->link = nullptr;
			delete del;
			std::cout << "Sudah Dihapus" << std::endl;
		}
	}
}
	void init(Stack **top) {
	if((*top == nullptr)) {
		std::cout << "Tidak ada yang di-inisialisasi" << std::endl;
	}else if((*top)->link == nullptr){
		delete(*top); (*top) = nullptr;
	}else {
		Stack *del, *cur = (*top);
		do{
		// Config
		del = cur;
		cur = cur->link;
			
		// Untied
		del->link = nullptr;
			
		//	Trashed
		delete del;		
		}while(cur != nullptr); 
		(*top) = nullptr;
	}
	std::cout << "Sudah dilaksanakan" << std::endl;
}
void printStack(Stack **top) {
	if((*top) == nullptr){
		std::cout << "Tidak ada Stack ditemukan" << std::endl;	
	}else{
		Stack *cur = (*top);
		while(cur != nullptr) {
			std::cout << cur->value << std::endl;
			cur = cur->link;
		}	
	}
}

  int main() { 
	Stack *top = nullptr;

	printStack(&top);
	push(&top, 5);
	push(&top, 4);
	push(&top, 3);
	push(&top, 2);
	push(&top, 1);
	printStack(&top);
	
	pop(&top);
	pop(&top);
	printStack(&top);	
	init(&top);
	printStack(&top);
	
	return 0;
}
