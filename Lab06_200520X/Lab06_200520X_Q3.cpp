#include<stdio.h>
#include<iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define length 10

void pushA(int);
void popA();
void displayA();

void pushL(int);
void popL();
void displayL();

int stack[length], topA = -1;

void pushA(int value){
   if(topA == length-1)
      cout<<("\nStack is Full!!! Insertion is not possible!!!");
   else{
      topA++;
      stack[topA] = value;
   }
}

void popA(){
   if(topA == -1)
      cout<<("\nStack is Empty!!! Deletion is not possible!!!");
   else{
      cout<<"\nDeleted :" <<stack[topA];
      topA--;
   }
}

void displayA(){
   if(topA == -1)
      cout<<("\nStack is Empty!!!");
   else{
      int i;
      cout<<("\nStack elements are:");
      for(i=topA; i>=0; i--){
	    cout<<stack[i]<<" ";
      }
   }
}

struct Node
{
   int data;
   struct Node *next;
}
*top = NULL;

void pushL(int value)
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

void popL()
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

void displayL()
{
   if(top == NULL)
      cout<<"\nStack is Empty!!!";
   else{
      struct Node *temp = top;
      cout<<"Elements:";
      while(temp->next != NULL){
	       cout<<temp->data<<"--->";
	       temp = temp -> next;
      }
      cout<<temp->data<<"--->NULL"<<endl;
   }
}


int main(){
    cout<<"Array:-"<<endl;
    auto startA = high_resolution_clock::now();
    pushA(8);
    pushA(10);
    pushA(5);
    pushA(11);
    pushA(15);
    pushA(23);
    pushA(6);
    pushA(18);
    pushA(20);
    pushA(17);
    displayA();
    popA();
    popA();
    popA();
    popA();
    popA();
    displayA();
    pushA(4);
    pushA(30);
    pushA(3);
    pushA(1);
    displayA();
    auto stopA = high_resolution_clock::now();
    auto durationA = duration_cast<nanoseconds>(stopA - startA);
    cout << "\nTime taken by the block of array function : "<< durationA.count() << " nanoseconds"<<endl;
    
    cout<<"---------------------------------------------------"<<endl;
    cout<<"LinkedList:-"<<endl;
    
    auto startL = high_resolution_clock::now();
    pushL(8);
    pushL(10);
    pushL(5);
    pushL(11);
    pushL(15);
    pushL(23);
    pushL(6);
    pushL(18);
    pushL(20);
    pushL(17);
    displayL();
    popL();
    popL();
    popL();
    popL();
    popL();
    displayL();
    pushL(4);
    pushL(30);
    pushL(3);
    pushL(1);
    displayL();
    auto stopL = high_resolution_clock::now();
    auto durationL = duration_cast<nanoseconds>(stopL - startL);
    cout << "\nTime taken by the block of linked list function : "<< durationL.count() << " nanoseconds";
}