#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node {
	int data;
	struct Node *prev;
	struct Node *next;
};
struct Node* head = NULL;
int counter = 0;
void deleteNode() {
      if(head != NULL) {
        if(head->next == NULL) {
          head = NULL;
        } else {
          Node* temp = head;
          while(temp->next->next != NULL)
            temp = temp->next;
          Node* lastNode = temp->next;
          temp->next = NULL;
          free(lastNode); 
        }
      }
}
void insert(int newdata, const char* read) {
	if(read == "W"){
		if(counter == 8){
			deleteNode();
		} 		
		else{
			struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
			newnode->data = newdata;
			newnode->prev = NULL;
			newnode->next = head;
			if(head != NULL){
				head->prev = newnode ;
			}
			head = newnode;
			counter++;
		}
	}
}
void display() {
	struct Node* ptr;
	ptr = head;
	while(ptr != NULL) {
    	cout<< ptr->data <<" ";
    	ptr = ptr->next;
    }
}
int main() {
	insert(3, "W");
	insert(1, "W");
	insert(7, "W");
	insert(2, "W");
	insert(9, "W");
	insert(3, "W");
	insert(1, "W");
	insert(7, "W");
	insert(2, "W");
	insert(3, "W");
	cout<<"The doubly linked list is: \n";
	display();
	cout<< "\n" ;
	return 0;
}
