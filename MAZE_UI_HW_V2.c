
/*#include<stdio.h>
#include<stdlib.h>*/
#pragma warnings(disable: 4996)
#define _CRT_SECURE_NO_WARNINGS 
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


#include<conio.h>

/*void movement()
{

	char c;
	while (1)
	{
		c = gecthe();
		switch (c)
		{
		case 'w': case'W':moveup();
			break;
		case'd': case'D': moveright();
			break;
		case'q': return 0;
		}
	}
}*/
void KeyCheck() {
	char c;
		
	if (_kbhit()) {        //키보드 입력 확인 (true / false)
		c = _getch();      // 방향키 입력시 224 00이 들어오게 되기에 앞에 있는 값 224를 없앰
		if (c == -32) {    // -32로 입력되면
			c = _getch();  // 새로 입력값을 판별하여 상하좌우 출력
			switch (c) {
			case 75:
				printf("왼쪽으로 이동\n");
				break;
			case 77:
				printf("오른쪽으로 이동\n");
				break;
			case 72:
				printf("위로 이동\n");
				break;
			case 80:
				printf("아래로 이동\n");
				break;
			}
		}
	}
		

}
typedef struct {
	int x;
	int y;
}xycoord;
xycoord SetSF(int a, int b, int c,int d) {
	xycoord start = { a,b };
	xycoord finish = { c,d };

}


int main() {
	init_stack();
	store_top = top;
	int a=0, b=0, c=0, d=0;
	printf("start coordinate: ");
	scanf("%d ", &a);
	scanf("%d ", &b);
	printf("finish coordinate: ");
	scanf("%d ", &c);
	scanf("%d ", &d);
	//scanf("%d ", &b);
	while (1)
	{
		KeyCheck();
	}
	




	return 0;
}