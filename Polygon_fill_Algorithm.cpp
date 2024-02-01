#include<iostream>
#include<graphics.h>

using namespace std;

class Edge {
public:
    int yMin, yMax;
    float x, slopeInverse;
};

void addEdge(Edge edges[], int& count, int yMin, int yMax, float x1, float y1, float x2, float y2) {
    // Sort the edge based on the yMin value
    if (y1 > y2) {
        swap(x1, x2);
        swap(y1, y2);
    }

    edges[count].yMin = yMin;
    edges[count].yMax = yMax;

    if (y1 == y2) {
        edges[count].x = x1;
    } else {
        edges[count].x = x1 + (yMin - y1) / (y2 - y1) * (x2 - x1);
    }

    edges[count].slopeInverse = 1.0 / ((y2 - y1) / (x2 - x1));
    count++;
}

void scanlineFill(int x[], int y[], int n) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    Edge edges[10], temp;
    int minY = INT_MAX, maxY = INT_MIN;

    // Find the minimum and maximum y-coordinates
    for (int i = 0; i < n; i++) {
        minY = min(minY, y[i]);
        maxY = max(maxY, y[i]);
    }

    int edgeCount = 0;

    // Generate edges from the polygon
    for (int i = 0; i < n; i++) {
        int nextIndex = (i + 1) % n;
        addEdge(edges, edgeCount, y[i], y[nextIndex], x[i], y[i], x[nextIndex], y[nextIndex]);
    }

    // Process each scanline
    for (int y = minY; y <= maxY; y++) {
        for (int i = 0; i < edgeCount; i++) {
            if (y >= edges[i].yMin && y < edges[i].yMax) {
                // Sorting edges based on x-coordinate for intersection handling
                for (int j = i + 1; j < edgeCount; j++) {
                    if (edges[i].x > edges[j].x) {
                        temp = edges[i];
                        edges[i] = edges[j];
                        edges[j] = temp;
                    }
                }

                // Fill the pixels between the intersections
                for (int k = i; k < edgeCount - 1; k += 2) {
                    for (int x = edges[k].x; x < edges[k + 1].x; x++) {
                        putpixel(x, y, WHITE);
                    }
                }
            }
        }

        // Update x-coordinate for the next scanline
        for (int i = 0; i < edgeCount; i++) {
            if (y >= edges[i].yMin && y < edges[i].yMax) {
                edges[i].x += edges[i].slopeInverse;
            }
        }
    }
// hhhhhhh
}

int main() {
    int n;

    cout << "Enter the number of vertices: ";
    cin >> n;

    int x[10], y[10];

    cout << "Enter the coordinates of the vertices (in order):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << (i + 1) << ": ";
        cin >> x[i] >> y[i];
    }

    scanlineFill(x, y, n);
    getch();
}


