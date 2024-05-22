
/*#include<stdio.h>
#include<stdlib.h>*/


#include <stdio.h>
#include <stdlib.h>//->exit(1)->error(str)

//#include <Stdbool.h>


#define true 1
#define false 0

#define MAX_SIZE 100 
typedef int Element;

//define: init,push(e),pop,is_empty,is_full,peek
Element data[MAX_SIZE];

int top;

/*void error(char str[]) {
	printf("%s\n", str);
	exit(1);
}*/

//int data[MAX_SIZE];

//typedef int Elem ;



int is_empty() {
	if (top == -1) {
		return true;
	}
	else
		return false;//return (top==-1);
	//again, can be expressed compactly.
}

int is_full() {
	if (top == MAX_SIZE - 1) {//return (top==(MAX_SIZE-1));
		return true;//oh. can be expressed this compactly.
	}
	else
		return false;
}

void init_stack() {
	top = -1;
}
void push(Element e) {
	if (is_full()) {
		/*error("Overflow Error!");*/
	}
	else {
		top += 1;
		data[top] = e;
		//data[++top]=e;
		//again, can be expressed compactly.
	}
}

Element pop() {
	if (is_empty()) {
		/*error("Unerflow Error!");*/
	}
	else {//return data[top--];
		//again, can be expressed compactly.
		top -= 1;
		return data[top + 1];
	}
}

Element peek() {
	if (is_empty()) {
		/*error("Underflow Error!");*/
	}
	else {
		return data[top];
	}
}

#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4

typedef struct {
	int element;
}Stack;

Stack direction_orders[4] = { NORTH,EAST,SOUTH,WEST };


typedef struct {
	char status[48];
	int pos_num;
	Stack direction_orders;
}stack;

stack positions[MAX_SIZE];
stack visited[MAX_SIZE];
stack unexplored[MAX_SIZE];

int store_top;

int main() {
	init_stack();
	store_top=top;




	return 0;
}