#include <iostream>
#include <graphics.h>
#include <cmath>

using namespace std;

// Define constants for width and height
const int WIDTH = 800;
const int HEIGHT = 600;

// Function to initialize the buffer with a specific color
void initializeBuffer(int buffer[][WIDTH], int color) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            buffer[i][j] = color;
       }
    }
}

 ////Function to update the buffer with a specific color at a given position
void updateBuffer(int buffer[][WIDTH], int x, int y, int color) {
   if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        buffer[y][x] = color;
    }
}

// Function to draw the buffer on the screen
void drawBuffer(int buffer[][WIDTH]) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
           putpixel(j, i, buffer[i][j]);
        }
    }
}

 //Function to draw a rectangle with specified color in the buffer
void drawRectangle(int buffer[][WIDTH], int x1, int y1, int x2, int y2, int color) {
    for (int i = y1; i <= y2; ++i) {
       for (int j = x1; j <= x2; ++j) {
           updateBuffer(buffer, j, i, color);
        }
    }
}

 //Function to draw a circle with specified color in the buffer
void drawCircle(int buffer[][WIDTH], int x, int y, int radius, int color) {
    for (int i = y - radius; i <= y + radius; ++i) {
        for (int j = x - radius; j <= x + radius; ++j) {
          if ((j - x) * (j - x) + (i - y) * (i - y) <= radius * radius) {
              updateBuffer(buffer, j, i, color);
            }
        }
    }
}

// Main function to render the scene
int main() {
    // Initialize graphics mode
   int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    // Initialize buffer with black color/  
  int buffer[HEIGHT][WIDTH];
   initializeBuffer(buffer, BLACK);

    // Draw a red rectangle with a white border in the buffer
    drawRectangle(buffer, 200, 200, 400, 400, WHITE);
    drawRectangle(buffer, 198, 198, 402, 402, RED);
   // Draw a green circle with a white border in the buffer
   drawCircle(buffer, 400, 300, 100, WHITE);
    drawCircle(buffer, 400, 300, 102, GREEN);

   // Draw the buffer on the screen
   drawBuffer(buffer);

   // Wait for a key press
    getch();
   // Close graphics mode
   closegraph();

  return 0;}



