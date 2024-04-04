#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>
using namespace std;

// Function to calculate Hermite interpolation
double HermiteInterpolation(double p0, double p1, double m0, double m1, double t) {
    double t2 = t * t;
    double t3 = t2 * t;
    double h1 = 2 * t3 - 3 * t2 + 1;
    double h2 = -2 * t3 + 3 * t2;
    double h3 = t3 - 2 * t2 + t;
    double h4 = t3 - t2;
    return p0 * h1 + p1 * h2 + m0 * h3 + m1 * h4;
}

// Function to draw Hermite curve
void HermiteCurve(int x[4], int y[4], double m[4]) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    double t, xt, yt;
    for (int i = 0; i < 3; ++i) {
        for (t = 0.0; t <= 1.0; t += 0.001) {
            xt = HermiteInterpolation(x[i], x[i+1], m[i], m[i+1], t);
            yt = HermiteInterpolation(y[i], y[i+1], m[i], m[i+1], t);
            putpixel((int)xt, (int)yt, WHITE);
        }
    }
    for (int i = 0; i < 4; ++i) {
        putpixel(x[i], y[i], WHITE);
    }
}

int main() {
    int x[4], y[4];
    double m[4];
    int i;
    printf("Enter the coordinates of X and Y:\n");
    for (i = 0; i < 4; i++) {
        scanf("%d%d", &x[i], &y[i]);
    }
    printf("Enter the slope at the first point:\n");
    for (i = 0; i < 4; i++) {
    printf("Enter the slope at %d  point:\n",i+1);
        scanf("%lf", &m[i]);
    }
    HermiteCurve(x, y, m);
    getch(); // Wait for a key press
    closegraph(); // Close the graphics window
    return 0;
}

