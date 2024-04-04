  #include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>
using namespace std;

void BezierCurve(int x[4], int y[4]) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int i;
    double t, xt, yt;
    for (t = 0.0; t < 1.0; t += 0.0005) {
        xt = pow(1 - t, 3) * x[0] + 3 * t * pow(1 - t, 2) * x[1] + 3 * pow(t, 2) * (1 - t) * x[2] + pow(t, 3) * x[3];
        yt = pow(1 - t, 3) * y[0] + 3 * t * pow(1 - t, 2) * y[1] + 3 * pow(t, 2) * (1 - t) * y[2] + pow(t, 3) * y[3];
        putpixel((int)xt, (int)yt, WHITE);
    }
    for (i = 0; i < 4; i++) {
        putpixel(x[i], y[i], WHITE);
    }
}

int main() {
    int x[4], y[4];
    int i;
    printf("Enter the coordinates of X and Y:\n");
    for (i = 0; i < 4; i++) {
        scanf("%d%d", &x[i], &y[i]);
    }
    BezierCurve(x, y);
    getch(); // Wait for a key press
    closegraph(); // Close the graphics window
    return 0;
}

