#include <iostream>
#include <ctime>
#include <cstdlib>
#define Nmax 26
using namespace std;

int compareCount, computeCount, innerCount;

float angle_arr[8];
int index_arr[8];
struct point { int x, y; char c; float angle; };
struct point polygon[Nmax];

struct line { struct point p1, p2, p3, p4; };

float ComputeAngle (struct point p1, struct point p2) {
    int dx, dy, ax, ay;
    float t;

    dx = p2.x - p1.x; 
    ax = abs(dx);
    dy = p2.y - p1.y; 
    ay = abs(dy);

    t = (ax + ay == 0) ? 0 : (float) dy / (ax + ay);
    computeCount++;
    if (dx < 0) t = 2-t;
    else if (dy < 0) t = 4 + t;
    return t*90.0;
}

void Swap(struct point *p1, struct point *p2) {
    struct point tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void insertion(struct point a[]) {
    int i, j;
    struct point v;
    for (i = 1; i < Nmax; i++) {
        v = a[i];
        j = i-1;

        compareCount++;
        while (j >= 0 && v.angle < a[j].angle) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
    }
}

int Direction(struct point A, struct point B, struct point C) { 
    int dxAB, dxAC, dyAB, dyAC, Dir;
    dxAB=B.x-A.x; 
    dyAB=B.y-A.y;
    dxAC=C.x-A.x;
    dyAC=C.y-A.y;
    if(dxAB * dyAC < dyAB * dxAC) Dir = 1; 
    if(dxAB * dyAC > dyAB * dxAC) Dir = -1;
    if (dxAB * dyAC == dyAB * dxAC) {
        if (dxAB == 0 && dyAB == 0) Dir = 0;
        if ((dxAB * dxAC < 0) || (dyAB * dyAC < 0)) Dir = -1;
        else if ((dxAB * dxAB + dyAB * dyAB) >= (dxAC * dxAC + dyAC * dyAC)) 
            Dir = 0;
        else Dir = 1;
    }
    return Dir;
}

void FindSimplePolygon(struct point P[], int n, int j) {
    P[j].angle = 0.0;
    for (int i = 0; i < Nmax; i++) 
        P[i].angle  = ComputeAngle(P[j], P[i]);
    insertion(P);
}



int GrahamScan(struct point P[], int n) {
    int i, FirstPoint, NextPoint;
    FirstPoint = 1;

    for (i = 2; i <= n; i++) 
        if (P[i].y < P[FirstPoint].y) FirstPoint = i;
    
    for (i = 1; i < n; i++) 
        if (P[i].y == P[FirstPoint].y 
        && P[i].x > P[FirstPoint].x) FirstPoint = i;
    
    Swap(&P[FirstPoint], &P[1]);
    FindSimplePolygon(P, n, 1);

    P[0] = P[n];
    NextPoint = 3;
    for (i = 4; i <= n; i++) {
        while(Direction(P[NextPoint-1], P[NextPoint], P[i]) >= 0) {
            NextPoint--;
            innerCount++;
        }
        NextPoint++;
        Swap(&P[NextPoint], &P[i]);
    }
    return NextPoint;
}


int main() {
    srand(time(NULL));

    // polygon[0].c = 'A'; polygon[0].x = 3; polygon[0].y = 4;
    // polygon[1].c = 'B'; polygon[1].x = 1; polygon[1].y = 2;
    // polygon[2].c = 'C'; polygon[2].x = 2; polygon[2].y = 5;
    // polygon[3].c = 'D'; polygon[3].x = 2; polygon[3].y = 6;
    // polygon[4].c = 'E'; polygon[4].x = 9; polygon[4].y = 3;
    // polygon[5].c = 'F'; polygon[5].x = 5; polygon[5].y = 3;
    // polygon[6].c = 'G'; polygon[6].x = 6; polygon[6].y = 4;
    // polygon[7].c = 'H'; polygon[7].x = 8; polygon[7].y = 4;
    // { A(3,4), B(1,2), C(2,5), D(2,6), E(9,3), F(5,3), G(6,4), H(8,4) }

    char alpha = 'A';
    for (int i = 0; i < Nmax; i++) {
        polygon[i].c = alpha++; 
        polygon[i].x = rand()%100; 
        polygon[i].y = rand()%100;
    } 

    int g = GrahamScan(polygon, Nmax);// << '\n';
    cout << "convex hull : ";
    for (int i = 0; i < g; i++) {
        cout << polygon[i].c << ' ';
    }
    cout << "\n수평각 계산 회수 : " << computeCount 
        << ", 각의 비교 회수 : " << compareCount 
        << ", 내부의 점 개수 : " << innerCount << '\n';
}

/*
// { A(3,4), B(1,2), C(2,5), D(2,6), E(9,3), F(5,3), G(6,4), H(8,4) }
*/