#include <iostream>
#include <ctime>
#include <cstdlib>
#define N 101
#define M 101
#define min(x, y) (((x) < (y)) ? (x) : (y))
using namespace std;

int c[N][M];

int main() {
    srand(time(NULL));

    // int matrix[4][4] = {
    //     {6, 7, 12, 5},
    //     {5, 3, 11, 18},
    //     {7, 17, 3, 3},
    //     {8, 10, 14, 9}};

    // for (int i = 0; i < 4; i++) 
    //     for (int j = 0; j < 4; j++) 
    //         if (i == 0 && j == 0) c[0][0] = matrix[0][0];
    //         else if (i == 0) c[i][j] = c[i][j-1] + matrix[i][j];
    //         else if (j == 0) c[i][j] = c[i-1][j] + matrix[i][j];
    //         else c[i][j] = matrix[i][j] + min(c[i-1][j], c[i][j-1]);
        
    // cout << c[3][3] << '\n';

    int matrix[N][M]; 
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++) 
            matrix[i][j] = rand() % 100 + 1;

    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++) 
            if (i == 0 && j == 0) c[0][0] = matrix[0][0];
            else if (i == 0) c[i][j] = c[i][j-1] + matrix[i][j];
            else if (j == 0) c[i][j] = c[i-1][j] + matrix[i][j];
            else c[i][j] = matrix[i][j] + min(c[i-1][j], c[i][j-1]);

    cout << c[N-1][M-1] << '\n';
}