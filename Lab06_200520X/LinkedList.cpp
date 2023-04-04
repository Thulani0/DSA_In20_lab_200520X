#include<stdio.h>
#include<iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Node
{
   int data;
   struct Node *next;
}
*top = NULL;

void push(int);
void pop();
void display();

void push(int value)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   if(top == NULL)
      newNode->next = NULL;
   else
      newNode->next = top;
   top = newNode;
}

void pop()
{
   if(top == NULL)
      cout<<"\nStack is Empty!!!\n";
   else{
      struct Node *temp = top;
      cout<<"\nDeleted element:"<< temp->data<<endl;
      top = temp->next;
      free(temp);
   }
}

void display()
{
   if(top == NULL)
      cout<<"\nStack is Empty!!!\n";
   else{
      struct Node *temp = top;
      while(temp->next != NULL){
	       cout<<temp->data<<"--->";
	       temp = temp -> next;
      }
      cout<<temp->data<<"--->NULL";
   }
}

int main(){
    auto start = high_resolution_clock::now();
    push(8);
    push(10);
    push(5);
    push(11);
    push(15);
    push(23);
    push(6);
    push(18);
    push(20);
    push(17);
    display();
    pop();
    pop();
    pop();
    pop();
    pop();
    display();
    push(4);
    push(30);
    push(3);
    push(1);
    display();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "\nTime taken by the block of linked list function : "<< duration.count() << " nanoseconds";
}