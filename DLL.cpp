#include <iostream>
#include <conio.h>

struct Node {
	int data;
	Node *next;
	Node *prev;
}*head, *tail, *cur, *del, *newNode, *temp;
//Create
  void createDLL(int val) {
  	head = new Node();
  	head->data = val;
  	head->next = NULL;
	  head->prev = NULL;
	  tail = head;
      }
//Insertion
  void addFirst(int val) {
	  newNode = new Node();
	  newNode->data = val;
	  newNode->prev = NULL;
	  newNode->next = head;
	  head = newNode;
      }
  void addMid(int val,int index) {
	  newNode = new Node();
	  newNode->data = val;
	  cur = head;
	  int count = 1;
	  while(count < index) {
		cur = cur->next;
		count++;
	    }
	  newNode->prev = cur;
	  newNode->next = cur->next;
	  cur->next = newNode;
	  cur = newNode->next;
	  cur->prev = newNode;
      }
  void addLast(int val) {
	  newNode = new Node();
	  newNode->data = val;
	  newNode->prev = tail;
	  newNode->next = NULL;
	  tail->next = newNode;
	  tail = newNode;
      }
//Deletion
  void removeFirst() {
	  del = head;
	  head = del->next;
	  head->prev = NULL;
	  delete del;
      }
  void removeMid(int index) {
	  cur = head;
	  int count = 1;
	  while(count < index) {
		cur = cur->next;
		count++;
	    }
	  del = cur;
	  cur = cur->prev;
	  temp = del->next;
	  temp->prev = cur;
	  cur->next = temp;
	  delete del;
      }
  void removeLast() {
	  del = tail;
	  tail = tail->prev;
	  tail->next = NULL;
	  delete del;
      }
  void printDLL() {
	  cur = head;
	  int count = 1;
	  while(cur != NULL) {
		  std::cout << "data" << count << " : " << cur->data << std::endl;
		  cur = cur->next;
		  count++;
	    }
	    std::cout << "\n=====================================\n\n";
      }
  int main() { 
        int x, y; 
		std::cout << "Panjang data ? "; std::cin >> y;
		std::cout << "\ncontoh : 1 2 3\n""data  : "; std::cin >> x;
		createDLL(x);
		for(int i = 1; i < y; i++) {
		std::cin >> x;
		addLast(x);
		}
		printDLL;
	int pilihan;
      	do {
        std::cout << "\n\n----------DOUBLE LINKED LIST-----------\n";
        std::cout << "Pilih menu : \n";
        std::cout << "1. tambah data pertama\n";
        std::cout << "2. tambah data diantara\n";
        std::cout << "3. tambah data terakhir\n";
        std::cout << "4. hapus data pertama\n";
        std::cout << "5. hapus data diantara\n";
        std::cout << "6. hapus data terakhir\n";
        std::cout << "7. print data\n";
        std::cout << "Lain-lain >> EXIT\n";
        std::cout << "Pilihan : ";
        std::cin >> pilihan;
        switch (pilihan){
        case 1 :
            addFirst(111);
            break;
        case 2 :
            addMid(222,3);
        	break;
        case 3 :
            addLast(333);
        	break;
        case 4 :
            removeFirst();
        	break;
        case 5 :
            removeMid(3);
        	break;
        case 6 :
            removeLast();
        	break;
        case 7 :
            printDLL();
            break;
        default :
            std::cout << "---------EXIT---------";
            break;
        }
        }while(pilihan <= 7);
        getch();
}
        case 6 :
            removeLast();
        	break;
        case 7 :
            printDLL();
            break;
        default :
            std::cout << "---------EXIT---------";
            break;
        }
        }while(pilihan <= 7);
        getch();
}
