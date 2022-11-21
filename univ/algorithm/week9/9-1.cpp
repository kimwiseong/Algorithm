#include <iostream>
#include <ctime>
#include <cstdlib>
#define Nmax 25
using namespace std;

int computeCount, compareCount;

struct point { int x, y; char c; float angle; };

float ComputeAngle (struct point p1, struct point p2) {
    int dx, dy, ax, ay;
    float t;

    dx = p2.x - p1.x; ax = abs(dx);
    dy = p2.y - p1.y; ay = abs(dy);

    t = (ax + ay == 0) ? 0 : (float) dy / (ax + ay);
    computeCount++;
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
        compareCount++;
        while (j >= 0 && v.angle < a[j].angle) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
    }
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
    for (int i = 0; i < Nmax; i++) 
        cout << "point : " << polygon[i].c << ", x : " << polygon[i].x 
        << ", y : " << polygon[i].y << ", angle : " << polygon[i].angle << '\n';
    
    
    cout << "계산 횟수 : " << computeCount <<'\n';
    cout << "비교 횟수 : " << compareCount <<'\n';
}