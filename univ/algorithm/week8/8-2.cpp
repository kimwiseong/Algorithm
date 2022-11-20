#include <iostream>
#include <string>
using namespace std;

int bcount, kcount, rcount;
const int q = 33554393;
const int d = 32;

void brutesearch(char p[10][10], char a[100][100]) { 
    int i, j, k, s, M = 10, N = 100;
    bool flag = false;
    
    for (i = 0; i < N - M; i++) {
        for (j = 0; j < N - M; j++) {
            for (k = 0, flag = true; k < M && flag; k++) {
                for (s = 0, flag = true; s < M && flag; s++) {
                    bcount++;
                    if (a[i+k][j+s] != p[k][s]) flag = true;
                }
            }
        }
    }
}

int **SP;
void initSP(char p[10][10]) {
    int i, j, s, k, M = 10;
    SP = new int*[M];
    for (i = 0; i < M; i++) SP[i] = new int[M];

    for (i = 0; i < M; i++) SP[i][0] = -1;
    for (i = 0; i < M; i++)  
        for (j = 0, k = -1; j < M; j++, k++, SP[i][j] = k) {
            kcount++;
            while((k >= 0) && (p[i][j] != p[i][k])) {
                kcount++;
                k = SP[i][k];
            }
        }
}

bool isFound(char p[10][10], char a[100][100], int x, int y) {
    int i, j, k, s, M = 10, N = 100; 
    int cnt = 0;
    for (i = x+1, s = 1; i < x+M; i++, s++)  {
        for (j = y-M, k = -1; j < y+1 && k < M ; j++, k++) {
            kcount++;
            while ((k >= 0) && a[i][j] != p[s][k]) {
                kcount++;
                k = SP[0][k];
            }
            if (k == M - 1) cnt++;
        }
    }
    if (cnt == M-1) return true;
    return false;
}

void kmpsearch(char p[10][10], char a[100][100]) {
    int i, j, k, M = 10, N = 100;
    initSP(p);

    for (i = 0; i < N-M+1; i++)  {
        for (j = -1, k = -1; j < N && k < M ; j++, k++) {
            kcount++;
            while ((k >= 0) && a[i][j] != p[0][k]) {
                kcount++;
                k = SP[0][k];
            }
            if (k == M - 1) {
                if(isFound(p, a, i, j)) //찾았을 때
                    cout << i << ' ' << j-k << '\n';
                
                k = SP[0][k];
            }
        }
    }
}

int index(char s) { return int(s); }

void rksearch(char p[10][10], char a[100][100]) {
    int i,j,k,s, dM = 1, h1 = 0, h2 = 0;
    int M = 10, N = 100;
    bool notFound = true;

    for (i = 1; i < M * M; i++) dM = (d*dM) % q;

    for (i = 0; i < M; i++) {
        for (j = 0; j < M; j++) {
            h1 = (h1 * d + index(p[i][j])) % q;
            h2 = (h2 * d + index(a[i][j])) % q; 
        }
    }

    for (i = 0; i < N - M + 1; i++) {
        for (j = 0; j < N - M + 1; j++) {
            for (k = 0; k < M && h1 == h2; k++) {
                for (s = 0; s < M; s++) {
                    rcount++;
                    if (a[i+k][j+s] != p[k][s]) break;
                }
            }
            h2 = (h2+d*q - index(a[i][j]) * dM) % q;
            h2 = (h2*d + index(a[i+M][j+M])) % q;
            
        }
    }
}

int main() {
    char t[100][100], p[10][10];

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            t[i][j] = 'A';
            if (i < 10 && j < 10) p[i][j] = 'A';
        }
    }
    p[9][9] = 'B';

    brutesearch(p, t);
    kmpsearch(p, t);
    rksearch(p, t);

    cout << "brutesearch count :" << bcount << endl;
    cout << "kmpsearch count : " << kcount << endl;
    cout << "rksearch count : " << rcount << endl;
}