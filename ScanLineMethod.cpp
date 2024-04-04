#include <iostream>
#include <graphics.h>

using namespace std;

// Define a simple primitive class to represent triangles
class Primitive {
public:
    int vertices[3][3]; // vertices[3][3] stores (x, y, z) coordinates of each vertex
    int color; // Color of the triangle
};

// Function to draw a line from (x1, y1) to (x2, y2) with the specified color
void drawLine(int x1, int y1, int x2, int y2, int color) {
    setcolor(color);
    line(x1, y1, x2, y2);
}

// Function to find the intersection points of scan lines with the edges of the triangle
void findIntersectionPoints(int x1, int y1, int x2, int y2, int scanlineY, float &xintersect) {
    if (y1 == y2) {
        xintersect = x1;
        return;
    }
    xintersect = x1 + (float)(x2 - x1) * (float)(scanlineY - y1) / (float)(y2 - y1);
}

// Function to fill the triangle using the scan-line algorithm
void scanLineFill(Primitive &prim) {
    int ymin = min(min(prim.vertices[0][1], prim.vertices[1][1]), prim.vertices[2][1]);
    int ymax = max(max(prim.vertices[0][1], prim.vertices[1][1]), prim.vertices[2][1]);

    // Loop through each scan line
    for (int y = ymin; y <= ymax; y++) {
        float xl, xr; // Left and right intersection points

        // Find the intersection points of the scan line with the edges of the triangle
        findIntersectionPoints(prim.vertices[0][0], prim.vertices[0][1], prim.vertices[1][0], prim.vertices[1][1], y, xl);
        findIntersectionPoints(prim.vertices[0][0], prim.vertices[0][1], prim.vertices[2][0], prim.vertices[2][1], y, xr);
        findIntersectionPoints(prim.vertices[1][0], prim.vertices[1][1], prim.vertices[2][0], prim.vertices[2][1], y, xr);

        // Sort xl and xr
        if (xl > xr) {
            swap(xl, xr);
        }

        // Draw the scan line segment
        drawLine(xl, y, xr, y, WHITE);
    }
}

// Main function
int main() {
    // Initialize graphics mode
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Define a triangle primitive
    Primitive prim;
    prim.vertices[0][0] = 100; prim.vertices[0][1] = 100; prim.vertices[0][2] = 1;
    prim.vertices[1][0] = 200; prim.vertices[1][1] = 300; prim.vertices[1][2] = 2;
    prim.vertices[2][0] = 300; prim.vertices[2][1] = 100; prim.vertices[2][2] = 3;
    prim.color = WHITE;

    // Call the scan-line fill function to fill the triangle
    scanLineFill(prim);

    // Wait for a key press
    getch();

    // Close the graphics mode
    closegraph();
    return 0;
}

