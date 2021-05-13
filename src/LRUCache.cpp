#include "../inc/LRUCache.h"
#include "../inc/Node.h"

#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>

LRUCache::LRUCache(){}

void LRUCache::deleteHit(Node *find, int n){
	Node* ptr;
	ptr = find;
	for(int i = 0; i < n; i++){
		ptr = head->next;
		i++;
	}
	Node* del = ptr;
	Node* prev = head;
    while(prev->next != NULL && prev->next != del) 
        prev = prev->next; 
  
    if(prev->next == NULL) 
    { 
        return; 
    } 
  
    prev->next = prev->next->next; 
  
    free(del); 
  
    return; 
} 	

void LRUCache::deleteNode() {
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

void LRUCache::write(long unsigned int newdata) {
		if(counter == 1000){
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
void LRUCache::read(long unsigned int newdata){
	struct Node* ptr;
	ptr = head;
	while(ptr != NULL){
		if(newdata == ptr->data){
			hit++;
			deleteHit(head, track);
			write(newdata);
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
  

void LRUCache::updateHits(){
	hit++;
}

void LRUCache::updateMisses(){
	miss++;
}

int LRUCache::getHits() const {return hit;}

int LRUCache::getMisses() const {return miss;}
