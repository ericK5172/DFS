
/*#include<stdio.h>
#include<stdlib.h>*/
#pragma warnings(disable: 4996)
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>//->exit(1)->error(str)

//#include <Stdbool.h>

#include "ArrayStack.h"

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
//stack unexplored[MAX_SIZE];

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

	if (_kbhit()) {        //Ű���� �Է� Ȯ�� (true / false)
		c = _getch();      // ����Ű �Է½� 224 00�� ������ �Ǳ⿡ �տ� �ִ� �� 224�� ����
		if (c == -32) {    // -32�� �ԷµǸ�
			c = _getch();  // ���� �Է°��� �Ǻ��Ͽ� �����¿� ���
			switch (c) {
			case 75:
				printf("�������� �̵�\n");
				break;
			case 77:
				printf("���������� �̵�\n");
				break;
			case 72:
				printf("���� �̵�\n");
				break;
			case 80:
				printf("�Ʒ��� �̵�\n");
				break;
			}
		}
	}


}
typedef struct {
	int x;
	int y;
}POS;
POS SetSF(int a, int b, int c, int d) {
	POS start = { a,b };
	POS finish = { c,d };

}

#include <stdbool.h>
bool movable(POS pos, int dir) {

}
int n;
int temp_maze_row[MAX_SIZE];

void read_maze();
void print_maze();
void create();
bool movable(POS pos, int dir);


int main() {
	init_stack();
	store_top = top;
	Stack s;
	int a = 0, b = 0, c = 0, d = 0;
	SetSF(0, 0, c, d);

	//printf("please choose n greater than 2 for n*n maze generation:\n");
	//scanf("%d", &n);
	/*for (int i = 1; i < n - 1; i++) {
		temp_maze_row[i] = 0;
	}
	printf("\ntemp_maze_row now:\n");
	for (int i = 0; i < n; i++) {
		printf("n=%d\t", temp_maze_row[i]);
	}*/
	
	
	
	/*while (1)
	{
		KeyCheck();
	}*/
	




	return 0;
}