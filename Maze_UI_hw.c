
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



typedef Element stack;

typedef struct {
	int x;
	int y;
}Position;

#define nCOL 100
#define nROW 100
int MAZE[nROW][nCOL] = { 0, };

typedef struct {
	int col;
	int row;
	char status[64];
	int MAZE[col][row];
}maze;

int main()
{
	int maze[nCOL][nROW]
	//read_maze(); 
	stack s = create();
	Position cur;
	cur.x = 0; cur.y = 0;
	int init_dir = 0;/*이번에는Position대신정수들을 저장하는 스택을사용한다. *//*어떤 위치에 도착했을 떄 처음으로 시도해 볼 이동방향*/
	while (1) {
		maze.MAZE[cur.x][cur.y].status = "VISITED";/*if(cur.x== n-1&& cur.y== n-1)printf("Found the path.\n");break;}/*visited */
		{
			bool forwarded = false;
			for (int dir = init_dir; dir < 4; dir++) {
			if (movable(cur, dir)) {
				/* 0:N, 1:E, 2:S, 3:W *//**/현재 위치 대신 이동하는 방향을push* /
				push(s, dir);/*스택에는*/
				cur = move_to(cur, dir);
				forwarded = true; 
				init_dir = 0; 
				break;/*처음 방문하는위치에서는항상0번 방향부터 시도해 본다. */
			}
		}/*개선*/if (!forwarded) {
			/* nowhere to go */maze[cur.x][cur.y] = BACKTRACKED; 
			if (is_empty(s)) {
				printf("No path exists.\n");
				break;
			}/*forward *//* backtracked */
			int d = pop(s); 
			cur = move_to(cur, (d + 2) % 4);
			init_dir = d + 1;
		}}
		print_maze();
	}
}