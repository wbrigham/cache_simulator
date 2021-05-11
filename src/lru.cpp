#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
struct Node {
	long unsigned int data;
	struct Node *prev;
	struct Node *next;
};
struct Node* head = NULL;
int counter = 0;
int hit = 0;
int miss = 0;
int track = 0;

void deleteHit(Node *head, int n){
	Node* ptr;
	ptr = head;
	for(int i = 0; i < n; i++){
		ptr = head->next;
		i++;
	}
	Node* del = ptr;
	Node* prev = head;
    while(prev->next != NULL && prev->next != del) 
        prev = prev->next; 
  
    // Check if node really exists in Linked List 
    if(prev->next == NULL) 
    { 
        cout << "\nGiven node is not present in Linked List"; 
        return; 
    } 
  
    // Remove node from Linked List 
    prev->next = prev->next->next; 
  
    // Free memory 
    free(del); 
  
    return; 
} 	
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
void insert(long unsigned int newdata, const char* read) {
	if(read == "W"){
		if(counter == 8){
			deleteNode();
			struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
			newnode->data = newdata;
			newnode->prev = NULL;
			newnode->next = head;
			if(head != NULL){
				head->prev = newnode ;
			}
			head = newnode;
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
	else if(read == "R"){
		struct Node* ptr;
		ptr = head;
		while(ptr != NULL){
			if(newdata == ptr->data){
				hit++;
				deleteHit(head, track);
				insert(newdata, "W");
				break;		
			}
			else{
				ptr = ptr->next;
			}
			track++;
		}
		if(ptr == NULL){
			miss++;
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
	insert(4, "W");
	insert(3, "W");
	insert(7, "W");
	insert(3, "R");
	/*insert(1, "W");
	insert(7, "W");
	insert(2, "W");
	insert(9, "W");
	insert(3, "W");
	insert(1, "W");
	insert(7, "W");
	insert(2, "W");
	insert(3, "W");
	insert(3,"R");*/
	cout<<"The doubly linked list is: \n";
	display();
	cout<< "\n" ;
	return 0;
}
