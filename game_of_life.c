#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define WIDTH 1250
#define HEIGHT 1250

int world[HEIGHT][WIDTH];

//initializing '*'  as alive cells randomly
void init_world() {
    srand(time(NULL));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            world[i][j] = rand() % 2;
        }
    }
}

//printing '*' and '.' (if the cell is dead)  to the console
void print_world() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (world[i][j] == 0) {
                printf(".");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
    printf("\n");
}
//RULES for game of life regarding neighbors
int get_num_neighbors(int row, int col) {
    int num_neighbors = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i == row && j == col) {
                continue;
            }
            if (i < 0 || i >= HEIGHT || j < 0 || j >= WIDTH) {
                continue;
            }
            if (world[i][j] == 1) {
                num_neighbors++;
            }
        }
    }
    return num_neighbors;
}

//updating grid using RULES
void update_world() {
    int new_world[HEIGHT][WIDTH];
    //parallelizing the for loops using openmp
    #pragma omp parallel for collapse(2) 
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int num_neighbors = get_num_neighbors(i, j);
            if (world[i][j] == 1) {
                if (num_neighbors < 2 || num_neighbors > 3) {
                    new_world[i][j] = 0;
                } else {
                    new_world[i][j] = 1;
                }
            } else {
                if (num_neighbors == 3) {
                    new_world[i][j] = 1;
                } else {
                    new_world[i][j] = 0;
                }
            }
        }
    }
    //updating world using new_world variable
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            world[i][j] = new_world[i][j];
        }
    }
}

int main() {
    init_world();
    for (int i = 0; i < 10; i++) {
        update_world();
    }
    return 0;
}

