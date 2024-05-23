#pragma warnings(disable: 4996)

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>

#include "Stack.h"



/*typedef struct {
	int x;
	int y;
}POS;*/

#define MAX_SIZE 100 
//typedef int Element;

//typedef struct POS Element;
//define: init,push(e),pop,is_empty,is_full,peek
//Element data[MAX_SIZE];

/*void error(char str[]) {
	printf("%s\n", str);
	exit(1);
}*/

//int data[MAX_SIZE];

//typedef int Elem ;

// #include<conio.h>

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
}
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


}*/



#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4



/*typedef struct {
	coord xycoord;
}POS;*/



#define MAZE_SIZE 8

/*typedef struct {
	//int MAZE_SIZE;
	//int diagram[MAZE_SIZE][MAZE_SIZE];
	int diagram[8][8];
}Diagram;*/

int readed_maze[MAZE_SIZE][MAZE_SIZE];
char maze[MAZE_SIZE][MAZE_SIZE];//char->int

//char created_maze[MAZE_SIZE][MAZE_SIZE];


/*typedef struct {
	int top;
	Element element;
}BasicStack;

typedef struct {
	BasicStack stack0;
	//int element;
}sstack;*/

//typedef struct Stack BasicStack;

typedef int set;


set direction_orders[4] = { NORTH,EAST,SOUTH,WEST };

typedef struct {
	int direction_number;
	//set direction_orders[4];
}direction;

typedef struct {
	Stack stack0;
	//char status[48];
	//POS pos;
	//int pos_num;
	set direction_orders;
	//direction directions;
}StoringStack;

StoringStack positions;
StoringStack visited;

//stack unexplored[MAX_SIZE];

//int store_top;

int check_input_direction() {
	int direction_number;
	char c;
    printf("Input: ");
    scanf("%hhd", &c);
	// if (_kbhit()) {        //Ű���� �Է� Ȯ�� (true / false)
	// 	c = _getch();      // ����Ű �Է½� 224 00�� ������ �Ǳ⿡ �տ� �ִ� �� 224�� ����
	// 	if (c == -32) {    // -32�� �ԷµǸ�
	// 		c = _getch();  // ���� �Է°��� �Ǻ��Ͽ� �����¿� ���
	// 		switch (c) {
	// 		case 75:
	// 			direction_number = WEST;
	// 			//printf("75\t");
	// 			break;
	// 		case 77:
	// 			direction_number = EAST;
	// 			//printf("77\t");
	// 			break;
	// 		case 72:
	// 			direction_number = NORTH;
	// 			//printf("72\t");
	// 			break;
	// 		case 80:
	// 			direction_number = SOUTH;
	// 			//printf("80\t");
	// 			break;

	// 		}
	// 	}
	// }
    switch (c) {
        case 'w':
            direction_number = WEST;
            //printf("75\t");
            break;
        case 'e':
            direction_number = EAST;
            //printf("77\t");
            break;
        case 'n':
            direction_number = NORTH;
            //printf("72\t");
            break;
        case 's':
            direction_number = SOUTH;
            //printf("80\t");
            break;

    }
    return direction_number;
}

// int dir = check_input_direction();
//direction.direction_number = dir;

/*POS SetSF(int a, int b, int c, int d) {
	POS start = { a,b };
	POS finish = { c,d };

}*/


//bool movable(POS cur_pos, int dir);
//int n;
//int temp_maze_row[MAX_SIZE];

int offset[4][2] = {
	{0,1},//NORTH
	{1,0},//EAST
	{0,-1},//SOUTH
	{-1,0}//WEST
};

POS move_in_direction(POS pos, int dir) {
	POS next_pos;
	if ((dir == 0) || (dir == 1)) {
		pos.x += offset[dir][0];
		pos.y += offset[dir][1];
	}

	next_pos.x = pos.x;
	next_pos.y = pos.y;
	return next_pos;
}

//POS next_pos;
//next_pos = move_in_direction(cur_pos, dir);
bool is_outer(POS pos) {
	if (((pos.x < 0) || (pos.x > MAZE_SIZE)) || (pos.y < 0) || (pos.y > MAZE_SIZE)) {
		return true;
	}
}


bool is_visited(POS pos) {
	for (int i = 0; i < MAX_SIZE; i++) {
		if ((visited.stack0.data[i].pos.x == pos.x) && (visited.stack0.data[i].pos.y == pos.y)) {
			return true;
		}
	}
}

bool is_wall(POS pos) {
	if (is_outer(pos)) {//outside. not wall.
		return false;
	}
	while (!is_outer(pos)) {
		if (maze[pos.x][pos.y] == 'W') {
			return true;
		}
		else
			return false;
	}

}

bool movable(POS pos, int dir) {
	POS next_pos;
	next_pos = move_in_direction(pos, dir);
	if ((!is_wall(next_pos)) && (!is_outer(next_pos)) && (is_visited(next_pos))) {
		return true;
	}
}

// oh �������� x�� �������� y �̸�  ����������,�Ʒ������� ����(0����)

POS find_start(char maze[MAZE_SIZE][MAZE_SIZE]) {
	POS StartCoord = { 0,0 };
	// FinishCoord;
	for (int i = 0; i < MAZE_SIZE; i++)
		for (int j = 0; j < MAZE_SIZE; j++) {
			if ((maze[i][j] == 's') || (maze[i][j] == 'S')) {
				StartCoord.x = i;
				StartCoord.y = j;
			}
		}
	return StartCoord;
	//return FinishCoord;
}

POS find_finish(char maze[MAZE_SIZE][MAZE_SIZE]) {
	//POS StartCoord;
	POS FinishCoord = { MAZE_SIZE,MAZE_SIZE };

	for (int i = 0; i < MAZE_SIZE; i++)
		for (int j = 0; j < MAZE_SIZE; j++) {
			if ((maze[i][j] == 'f') || (maze[i][j] == 'F')) {
				FinishCoord.x = i;
				FinishCoord.y = j;
			}
		}
	//return StartCoord;
	return FinishCoord;
}

POS my_location(char maze[MAZE_SIZE][MAZE_SIZE], int dir) {
	char temp_maze[MAZE_SIZE][MAZE_SIZE];
	int starting_x;
	int starting_y;
	POS my_pos;
	POS StartCoord;
	POS FinishCoord;
	StartCoord = find_start(maze);
	FinishCoord = find_finish(maze);
	starting_x = StartCoord.x;
	starting_y = StartCoord.y;
	my_pos.x = starting_x;
	my_pos.y = starting_y;
	POS next_pos;
	while (movable(my_pos, dir)) {
		next_pos = move_in_direction(my_pos, dir);
		if ((next_pos.x == FinishCoord.x) && (next_pos.y == FinishCoord.y)) {//reached finish
			//printf("Path Found!\n");
			break;
		}
		my_pos.x = next_pos.x;
		my_pos.y = next_pos.y;
		temp_maze[my_pos.x][my_pos.y] = 'm';
		dir = -1;
	}
	return my_pos;
}
//POS my_pos=my_location(maze, dir);




char conversion(int num) {
	char c;
	switch (num) {
	case NORTH:
		// c = '��'
        c = 'n';
	case EAST:
		// c = '��';
        c = 'e';
	case SOUTH:
		// c = '��';
        c = 's';
	case WEST:
		// c = '��';
        c = 'w';
	}
}

int* Stdin[MAX_SIZE * 2];

/*void Add_Stdin(Stdin) {
	int i = 0;
	while (dir != 1) {
		Stdin[] = dir;
		i++;
	}
}*/


char* converted_Stdin[MAX_SIZE * 2];

POS Stdout[MAX_SIZE * 2];


void read_maze(int maze_info[MAZE_SIZE][MAZE_SIZE]) {
	//readed_maze[MAZE_SIZE][MAZE_SIZE];
	for (int i = 0; i < MAZE_SIZE; i++) {
		for (int j = 0; j < MAZE_SIZE; j++) {
			readed_maze[i][j] = maze_info[i][j];
		}
	}
	//return readed_maze;
}

POS my_loc;

void create() {
	//POS my_loc;
	//my_loc = my_location(maze, dir);
	//char created_maze[MAZE_SIZE][MAZE_SIZE];
	for (int i = 0; i < MAZE_SIZE; i++) {
		for (int j = 0; j < MAZE_SIZE; j++) {
			/*if ((i == my_loc.x) && (j == my_loc.y)) {
				maze[i][j] = 'm';//'��'
			}*/
			if (readed_maze[i][j] == 1) {
				maze[i][j] = 'W';//'��'

			}
			else if (readed_maze[i][j] == 0) {
				maze[i][j] = 'r';//'��'

			}
			else if (readed_maze[i][j] == 's' || readed_maze[i][j] == 'S') {
				maze[i][j] = 'S';//'��'

			}
			else if (readed_maze[i][j] == 'f' || readed_maze[i][j] == 'F') {
				maze[i][j] = 'F';//'��'

			}
			else {
				maze[i][j] = 'e';//'��'

			}
		}
	}
	//return maze;
}

void print_maze() {
	for (int i = 0; i < MAZE_SIZE; i++) {
		for (int j = 0; j < MAZE_SIZE; j++) {
			printf("%2c ", maze[i][j]);
		}printf("\n");
	}
}

void recreate(POS my_loc, char temp_maze[MAZE_SIZE][MAZE_SIZE]) {
	//POS my_loc;
	//my_loc = my_location(maze, dir);
	//char created_maze[MAZE_SIZE][MAZE_SIZE];
	for (int i = 0; i < MAZE_SIZE; i++) {
		for (int j = 0; j < MAZE_SIZE; j++) {
			if ((i == my_loc.x) && (j == my_loc.y)) {
				temp_maze[i][j] = 'm';//'��'
			}
			if (readed_maze[i][j] == 1) {
				temp_maze[i][j] = 'W';//'��'

			}
			else if (readed_maze[i][j] == 0) {
				temp_maze[i][j] = 'r';//'��'

			}
			else if (readed_maze[i][j] == 's' || readed_maze[i][j] == 'S') {
				temp_maze[i][j] = 'S';//'��'

			}
			else if (readed_maze[i][j] == 'f' || readed_maze[i][j] == 'F') {
				temp_maze[i][j] = 'F';//'��'

			}
			else {
				temp_maze[i][j] = 'e';//'��'

			}
		}
	}
	//return maze;
}
void reprint_maze(char temp_maze[MAZE_SIZE][MAZE_SIZE]) {
	for (int i = 0; i < MAZE_SIZE; i++) {
		for (int j = 0; j < MAZE_SIZE; j++) {
			printf("%2c ", temp_maze[i][j]);
		}printf("\n");
	}
}

int dir;

// void debug() {
//     printf("DEBUG\n");
// }

int main() {

	init_stack(positions.stack0.data);
	init_stack(visited.stack0.data);

    dir = check_input_direction();

	//store_top = top;
	//stack s;
	//int a = 0, b = 0, c = 0, d = 0;
	//SetSF(0, 0, c, d);

	char temp_maze[MAZE_SIZE][MAZE_SIZE];

	int test_maze[8][8] = {
		{1,1,1,1,1,1,1,1},
		{'s',0,1,1,0,0,1,1},
		{1,0,0,0,1,0,0,1},
		{1,0,1,1,0,1,0,1},
		{1,0,0,0,0,1,0,'f'},
		{1,0,0,1,0,0,0,1},
		{1,0,1,1,0,1,1,1},
		{1,1,1,1,1,1,1,1}
	};
	read_maze(test_maze);


	create();

	printf("created MAZE:\n");
	for (int i = 0; i < MAZE_SIZE; i++) {
		for (int j = 0; j < MAZE_SIZE; j++) {
			printf("%d ", maze[i][j]);
		}printf("\n");
	}
	printf("\n");

	printf("\n");

	print_maze();

	POS start;
	start = find_start(maze);

	POS finish;
	finish = find_finish(maze);

	POS cur_pos = { start.x,start.y };
	int k = 0;
	Element e;
	e.pos = cur_pos;

	POS next_pos = move_in_direction(cur_pos, dir);
	//POS my_loc;
	//my_loc = my_location(maze, dir);
	while (!((positions.stack0.data->pos.x == finish.x) && (positions.stack0.data->pos.y == finish.y))) {
		//printf("e");
        push(positions.stack0.data, e);
		push(visited.stack0.data, e);
		if ((positions.stack0.data->pos.x == finish.x) && (positions.stack0.data->pos.y == finish.y)) {
			printf("Path Found!");
		}
		if (movable(cur_pos, dir)) {
			e.pos = next_pos;
			push(positions.stack0.data, e);
			push(visited.stack0.data, e);
			cur_pos = next_pos;
		}
		else {//if(!movable)
			push(visited.stack0.data, e);
			cur_pos = pop(positions.stack0.data).pos;
			if (is_empty(positions.stack0.data)) {
				printf("This Maze Has No Path!\n");
			}

		}
		//recreate(my_loc, temp_maze);
		//reprint_maze(temp_maze);
	}
	

	/*while (1)
	{
		KeyCheck();
	}*/



	return 0;

}

		/*Element e;
	POS cur_pos_1 = { 1,1 };
	e.pos = cur_pos_1;*/

	//init_stack(positions);
	//init_stack(visited);
	/*for (int i = 0; i < 5; i++) {
		push(positions.stack0.data, e);
	}*/

	/*Stack test_stack;
	test_stack.data[0].pos = cur_pos_1;
	test_stack.top = -1;

	for (int i = 0; i < 5; i++) {
		push(test_stack.data, e);
	}*/


	/*printf("Test:\n ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", test_stack.data[i].pos.x);
		printf("%d ", test_stack.data[i].pos.y);
		printf("\n ");

		printf("Positions:\n ");
		for (int i = 0; i < 10; i++) {
			printf("%d ", positions.stack0.data[i].pos.x);
			printf("%d ", positions.stack0.data[i].pos.y);
			printf("\n ");
		}

		printf("Visited:\n ");
		for (int i = 0; i < 10; i++) {
			printf("%d ", visited.stack0.data[i].pos.x);
			printf("%d ", visited.stack0.data[i].pos.y);
			printf("\n ");
		}*/
		//printf("please choose n greater than 2 for n*n maze generation:\n");
		//scanf("%d", &n);
		/*for (int i = 1; i < n - 1; i++) {
			temp_maze_row[i] = 0;
		}
		printf("\ntemp_maze_row now:\n");
		for (int i = 0; i < n; i++) {
			printf("n=%d\t", temp_maze_row[i]);
		}*/


		/*printf("readed MAZE:\n");
	for (int i = 0; i < MAZE_SIZE; i++) {
		for (int j = 0; j < MAZE_SIZE; j++) {
			printf("%d ",readed_maze[i][j]);
		}printf("\n");
	}*/

	/*for (int i = 0; i < MAZE_SIZE; i++) {
		for (int j = 0; j < MAZE_SIZE; j++) {
			printf("%c ",maze[i][j]);
		}printf("\n");
	}*/

	/*printf("created MAZE:\n");
	for (int i = 0; i < MAZE_SIZE; i++) {
		for (int j = 0; j < MAZE_SIZE; j++) {
			printf("%d ", maze[i][j]);
		}printf("\n");
	}
	printf("\n");*/

	//printf("printed maze:\n");
	//}
	
/*void add_my_loc(POS my_loc) {
	char temp_maze[MAZE_SIZE][MAZE_SIZE];
	for (int i = 0; i < MAZE_SIZE; i++){
		for (int j = 0; j < MAZE_SIZE; j++){
			//if ((i == my_loc.x) && (j == my_loc.y)) {
			//	temp_maze[i][j] = 'm';
			//}
			if (readed_maze[i][j] == 1) {
				temp_maze[i][j] = 'W';//'��'

			}
			else if (readed_maze[i][j] == 0) {
				temp_maze[i][j] = 'r';//'��'

			}
			else if (readed_maze[i][j] == 's' || readed_maze[i][j] == 'S') {
				temp_maze[i][j] = 'S';//'��'

			}
			else if (readed_maze[i][j] == 'f' || readed_maze[i][j] == 'F') {
				temp_maze[i][j] = 'F';//'��'

			}
			else {
				temp_maze[i][j] = 'e';//'��
		}
			for (int i = 0; i < MAZE_SIZE; i++) {
				for (int j = 0; j < MAZE_SIZE; j++) {
					printf("%2c ", temp_maze[i][j]);
				}printf("\n");
			}
	}

}*/