#include <iostream>
#include <graphics.h>

using namespace std;

// Define a simple primitive class to represent triangles
class Primitive {
public:
    int vertices[3][3]; // vertices[3][3] stores (x, y, z) coordinates of each vertex
    int color; // Color of the triangle
};

// Function to draw a line from (x1, y1) to (x2, y2)
void drawLine(int x1, int y1, int x2, int y2) {
    line(x1, y1, x2, y2);
}

// Function to draw a filled triangle given its vertices
void drawFilledTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color) {
    setfillstyle(SOLID_FILL, color);
    int points[8] = {x1, y1, x2, y2, x2, y2, x3, y3};
    fillpoly(4, points);
}

// Function to determine if a point (x, y) is inside a triangle defined by its vertices
bool isPixelInsideTriangle(int x, int y, int v0[3], int v1[3], int v2[3]) {
    int s = v0[1] * v2[0] - v0[0] * v2[1] + (v2[1] - v0[1]) * x + (v0[0] - v2[0]) * y;
    int t = v0[0] * v1[1] - v0[1] * v1[0] + (v0[1] - v1[1]) * x + (v1[0] - v0[0]) * y;
    if ((s < 0) != (t < 0))
        return false;
    
    int A = -v1[1] * v2[0] + v0[1] * (v2[0] - v1[0]) + v0[0] * (v1[1] - v2[1]) + v1[0] * v2[1];
    if (A < 0.0) {
        s = -s;
        t = -t;
        A = -A;
    }
    return (s > 0) && (t > 0) && ((s + t) <= A);
}

// Function to perform depth buffer algorithm and draw the scene
void depthBufferMethod(Primitive primitives[], int numPrimitives, int width, int height) {
    int depthBuffer[width][height];

    // Initialize depth buffer with infinity
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            depthBuffer[i][j] = INT_MAX;
        }
    }

    // Draw triangles using depth buffer algorithm
    for (int k = 0; k < numPrimitives; ++k) {
        Primitive prim = primitives[k];
        int v0[3] = {prim.vertices[0][0], prim.vertices[0][1], prim.vertices[0][2]};
        int v1[3] = {prim.vertices[1][0], prim.vertices[1][1], prim.vertices[1][2]};
        int v2[3] = {prim.vertices[2][0], prim.vertices[2][1], prim.vertices[2][2]};

        for (int x = 0; x < width; ++x) {
            for (int y = 0; y < height; ++y) {
                if (isPixelInsideTriangle(x, y, v0, v1, v2)) {
                    int depth = v0[2] + ((v1[2] - v0[2]) * (x - v0[0]) + (v2[2] - v0[2]) * (y - v0[1])) / ((v1[0] - v0[0]) * (v2[1] - v0[1]) - (v2[0] - v0[0]) * (v1[1] - v0[1]));
                    if (depth < depthBuffer[x][y]) {
                        depthBuffer[x][y] = depth;
                        drawFilledTriangle(v0[0], v0[1], v1[0], v1[1], v2[0], v2[1], prim.color);
                    }
                }
            }
        }
    }
}

// Main function
int main() {
    // Initialize graphics mode
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Define the primitives (triangles)
    Primitive primitives[3];
    primitives[0].vertices[0][0] = 100; primitives[0].vertices[0][1] = 100; primitives[0].vertices[0][2] = 1;
    primitives[0].vertices[1][0] = 200; primitives[0].vertices[1][1] = 300; primitives[0].vertices[1][2] = 2;
    primitives[0].vertices[2][0] = 300; primitives[0].vertices[2][1] = 100; primitives[0].vertices[2][2] = 3;
    primitives[0].color = WHITE;

    primitives[1].vertices[0][0] = 200; primitives[1].vertices[0][1] = 200; primitives[1].vertices[0][2] = 4;
    primitives[1].vertices[1][0] = 400; primitives[1].vertices[1][1] = 400; primitives[1].vertices[1][2] = 5;
    primitives[1].vertices[2][0] = 100; primitives[1].vertices[2][1] = 400; primitives[1].vertices[2][2] = 6;
    primitives[1].color = RED;

    primitives[2].vertices[0][0] = 300; primitives[2].vertices[0][1] = 300; primitives[2].vertices[0][2] = 7;
    primitives[2].vertices[1][0] = 500; primitives[2].vertices[1][1] = 100; primitives[2].vertices[1][2] = 8;
    primitives[2].vertices[2][0] = 600; primitives[2].vertices[2][1] = 300; primitives[2].vertices[2][2] = 9;
    primitives[2].color = GREEN;

    // Call depth buffer method to draw the scene
    depthBufferMethod(primitives, 3, getmaxx(), getmaxy());

    // Wait for a key press
    getch();

    // Close the graphics mode
    closegraph();
    return 0;
}

