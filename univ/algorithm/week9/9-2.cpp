#include <iostream>
#include <ctime>
#include <cstdlib>
#define Nmax 25
#define MAX_INT INT_MAX/500
using namespace std;


struct point { int x, y; char c; float angle; };

struct line { struct point p1, p2, p3, p4; };

float ComputeAngle (struct point p1, struct point p2) {
    int dx, dy, ax, ay;
    float t;

    dx = p2.x - p1.x; 
    ax = abs(dx);
    dy = p2.y - p1.y; 
    ay = abs(dy);

    t = (ax + ay == 0) ? 0 : (float) dy / (ax + ay);

    if (dx < 0) t = 2-t;
    else if (dy < 0) t = 4 + t;
    return t*90.0;
}

struct point polygon[Nmax];

void insertion(struct point a[]) {
    int i, j;
    struct point v;
    for (i = 1; i < Nmax; i++) {
        v = a[i];
        j = i-1;
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

bool Intersection(struct line AB, struct line CD) { 
    return (Direction(AB.p1, AB.p2, CD.p3) 
    * Direction(AB.p1, AB.p2, CD.p4) <= 0) 
    && (Direction(CD.p3, CD.p4, AB.p1) 
    * Direction(CD.p3, CD.p4, AB.p2) <= 0);
}

bool IsPointInside(struct point A) {
    int Count, i, LastPoint;
    bool PointOnTestLine;
    struct line TestLine, PolyLine;
    Count = LastPoint = 0;
    TestLine.p1 = A;
    TestLine.p2 = A;
    TestLine.p2.x = MAX_INT;

    for(i = 1;i <= Nmax;i++){
        PolyLine.p1 = PolyLine.p2 = polygon[i];
        
        if (Intersection(TestLine, PolyLine)) PointOnTestLine = true;
        else {
            PolyLine.p2 = polygon[LastPoint]; LastPoint = i;
            
            if (!PointOnTestLine) {
                if (Intersection(PolyLine, TestLine)) Count++; 
            } 
            else { 
                if(Direction(TestLine.p1, TestLine.p2, PolyLine.p1) 
                    * Direction(TestLine.p1, TestLine.p2, PolyLine.p2) < 0) {
                    Count++;
                }
                PointOnTestLine = false;
            }
        }
    }
    return ((Count % 2) == 1); 
}

int main() {
    srand(time(NULL));
    char alpha = 'A';
    struct point tmp;

    polygon[0].c = alpha++;
    polygon[0].x = rand() % 100;
    polygon[0].y = rand() % 100;
    for (int i = 1; i < Nmax; i++) {
        polygon[i].c = alpha++;
        polygon[i].x = rand() % 100;
        polygon[i].y = rand() % 100;
        if (polygon[i].y < polygon[0].y) {
            tmp = polygon[0];
            polygon[0] = polygon[i];
            polygon[i] = tmp;
        }
    }
    
    polygon[0].angle = 0.0;
    for (int i = 1; i < Nmax; i++) 
        polygon[i].angle  = ComputeAngle(polygon[0], polygon[i]);
    insertion(polygon);

    int inputX, inputY;
    cout << "좌표 입력(x, y) : ";
    cin >> inputX >> inputY;

    struct point Z;
    Z.x = inputX;
    Z.y = inputY;
    Z.c = alpha;

    IsPointInside(Z) ? cout << "true\n" : cout << "false\n";
    
}