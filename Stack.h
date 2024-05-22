
#include <stdio.h>
#include <stdlib.h>//->exit(1)->error(str)

//#include <Stdbool.h>


#define true 1
#define false 0

#define MAX_SIZE 100 

int top;

typedef struct {
	int x;
	int y;
}POS;

typedef struct {
	POS pos;
}Element;

typedef struct {
	int top;
	Element data[MAX_SIZE];
}Stack;

//typedef struct POS Element;

//define: init,push(e),pop,is_empty,is_full,peek
//Element data[MAX_SIZE];
Element data0[MAX_SIZE];

//int top = data0->top;

/*void error(char str[]) {
	printf("%s\n", str);
	exit(1);
}*/

//int data[MAX_SIZE];

//typedef int Elem ;



int is_empty(Element data0[MAX_SIZE]) {
	if (top == -1) {
		return true;
	}
	else
		return false;//return (top==-1);
	//again, can be expressed compactly.
}

int is_full(Element data0[MAX_SIZE]) {
	if (top == MAX_SIZE - 1) {//return (top==(MAX_SIZE-1));
		return true;//oh. can be expressed this compactly.
	}
	else
		return false;
}

void init_stack(Element data0[MAX_SIZE]) {
	top = -1;
}
void push(Element data0[MAX_SIZE], Element e) {
	if (is_full(data0)) {
		/*error("Overflow Error!");*/
	}
	else {
		top += 1;
		data0[top].pos.x = e.pos.x;
		data0[top].pos.y = e.pos.y;
		
		//data[++top]=e;
		//again, can be expressed compactly.
	}
}

Element pop(Element data0[MAX_SIZE]) {
	Element popped;
	if (is_empty(data0)) {
		/*error("Unerflow Error!");*/
	}
	else {//return data[top--];
		//again, can be expressed compactly.
		top -= 1;
		popped.pos.x= data0[top + 1].pos.x;
		popped.pos.y = data0[top + 1].pos.y;
		return popped;
	}
}

Element peek(Element data0[MAX_SIZE]) {
	Element peeked;
	if (is_empty(data0)) {
		/*error("Underflow Error!");*/
	}
	else {
		peeked.pos.x= data0[top].pos.x;
		peeked.pos.y = data0[top].pos.y;
		return peeked;
	}
}

