#include<Stdio.h>
#include "stack.h"
#include "pos.h"
#define MAX 100
#define PATH 0
#define WALL 1
#define VISITED 2
#define BACKTRACKED 3
int maze[MAX][MAX];
int n;
void read_maze();
void print_maze();
bool movable(POS pos, int dir);



int main() {
	read_maze();
	Stack s = create();
	Position cur;
	cur.x = 0;
	cur.y = 0;
	while (1) {
		maze[cur.x][cur.y] = VISITED;
		if (cur.x == n - 1 && cur.y == n - 1) {
			printf("Found the path.\n");
			break;
		}
		bool forwarded = false;
		for (int dir = 0; dir < 4; dir++) {
			if (movable(cur, dir)) {
				push(s, cur);
				cur = move_to(cur, dir);
				forwarded = true;
				break;
			}
		if (!forwarded) {
			maze[cur.x][cur.y] = BACKTRACKED;
			if (is_empty(s)){
				printf("No path exists.\n");
				break;
			}
			cur = pop(s);
			}
		}
	}print_maze();
}