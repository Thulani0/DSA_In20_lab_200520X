#include<stdio.h>
#include<iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define length 10

void push(int);
void pop();
void display();

int stack[length], top = -1;

void push(int value){
   if(top == length-1)
      cout<<("\nStack is Full!!! Insertion is not possible!!!");
   else{
      top++;
      stack[top] = value;
   }
}

void pop(){
   if(top == -1)
      cout<<("\nStack is Empty!!! Deletion is not possible!!!");
   else{
      cout<<"\nDeleted :" <<stack[top];
      top--;
   }
}

void display(){
   if(top == -1)
      cout<<("\nStack is Empty!!!");
   else{
      int i;
      cout<<("\nStack elements are:\n");
      for(i=top; i>=0; i--){
	    cout<<stack[i]<<" ";
      }
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
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nTime taken by the block of array function : "<< duration.count() << " microseconds";
}