#include <iostream>
#include <cmath>

using namespace std;

// Define region codes for each region
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

// Function to compute the region code for a point (x, y)
int computeCode(double x, double y, double xmin, double ymin, double xmax, double ymax) {
    int code = INSIDE;

    if (x < xmin) {
        code = LEFT;
    } else if (x > xmax) {
        code = RIGHT;
    }

    if (y < ymin) {
        code = BOTTOM;
    } else if (y > ymax) {
        code = TOP;
    }

    return code;
}

// Function to clip a line using Cohen-Sutherland algorithm
void cohenSutherland(double x1, double y1, double x2, double y2, double xmin, double ymin, double xmax, double ymax) {
    int code1 = computeCode(x1, y1, xmin, ymin, xmax, ymax);
    int code2 = computeCode(x2, y2, xmin, ymin, xmax, ymax);

    bool accept = false;

    while (true) {
        if (!(code1 | code2)) {
            // Both endpoints are inside the clipping window
            accept = true;
            break;
        } else if (code1 & code2) {
            // Both endpoints are outside in the same region
            break;
        } else {
            // At least one endpoint is outside the clipping window, clip the line
            int codeOut = code1 ? code1 : code2;

            double x, y;

            // Calculate the intersection point
            if (codeOut & TOP) {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            } else if (codeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            } else if (codeOut & RIGHT) {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            } else if (codeOut & LEFT) {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1, xmin, ymin, xmax, ymax);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2, xmin, ymin, xmax, ymax);
            }
        }
    }

    if (accept) {
        cout << "Line after clipping: (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")" << endl;
    } else {
        cout << "Line is completely outside the clipping window." << endl;
    }
}

int main() {
    double x1, y1, x2, y2, xmin, ymin, xmax, ymax;

    cout << "Enter the coordinates of the line (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    cout << "Enter the clipping window (xmin ymin xmax ymax): ";
    cin >> xmin >> ymin >> xmax >> ymax;

    cout << "Original line: (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")" << endl;
    cout << "Clipping window: (" << xmin << ", " << ymin << ") to (" << xmax << ", " << ymax << ")" << endl;

    cohenSutherland(x1, y1, x2, y2, xmin, ymin, xmax, ymax);

    return 0;
}

