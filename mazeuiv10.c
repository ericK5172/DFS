#include <Stdio.h>
#include<stdlib.h>
#include<Stdbool.h>
#include <conio.h>
#include <iostream>
#include "stackV10.h"

// Function to read the maze from standard input
void read_maze(char maze[][100], int& rows, int& cols) {
    std::string line;
    rows = 0;
    while (std::getline(std::cin, line)) {
        if (line.empty()) continue;
        cols = line.length();
        for (int j = 0; j < cols; ++j) {
            maze[rows][j] = line[j];
        }
        rows++;
    }
}

// Function to print the maze
void print_maze(char maze[][100], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << maze[i][j];
        }
        std::cout << '\n';
    }
}

// Function to check if a position is within maze boundaries and is movable (i.e., not a wall and not visited)
bool is_movable(char maze[][100], int rows, int cols, int x, int y) {
    return x >= 0 && x < rows&& y >= 0 && y < cols && (maze[x][y] == ' ' || maze[x][y] == 'E');
}

// Function to perform DFS on the maze with user interaction
void dfs_maze(char maze[][100], int rows, int cols, POS start) {
    Stack stack;
    stack.push(start);

    POS current = start;

    while (!stack.isEmpty()) {
        current = stack.peek();
        int x = current.x;
        int y = current.y;
        stack.pop();

        // Mark the current position as visited
        if (maze[x][y] == 'E') {
            std::cout << "Exit found at (" << x << ", " << y << ")\n";
            return;
        }
        maze[x][y] = '.';

        print_maze(maze, rows, cols);

        char direction;
        std::cout << "Enter direction (w: North, d: East, s: South, a: West): ";
        std::cin >> direction;

        int new_x = x, new_y = y;
        switch (direction) {
        case 'w': new_x = x - 1; break; // North
        case 'd': new_y = y + 1; break; // East
        case 's': new_x = x + 1; break; // South
        case 'a': new_y = y - 1; break; // West
        default: continue;
        }

        if (is_movable(maze, rows, cols, new_x, new_y)) {
            stack.push(current); // Push current position before moving
            current = { new_x, new_y };
            stack.push(current); // Push new position to stack
        }
        else {
            if (!stack.isEmpty()) {
                current = stack.peek();
                stack.pop();
            }
            else {
                std::cout << "No path found in the maze.\n";
                return;
            }
        }
    }
    std::cout << "No path found in the maze.\n";
}

int main() {
    const int MAX_SIZE = 100;
    char maze[MAX_SIZE][MAX_SIZE];
    int rows, cols;

    read_maze(maze, rows, cols);
    POS start = { 1, 1 }; // Example start position, adjust as needed
    dfs_maze(maze, rows, cols, start);
    print_maze(maze, rows, cols);

    return 0;
}
