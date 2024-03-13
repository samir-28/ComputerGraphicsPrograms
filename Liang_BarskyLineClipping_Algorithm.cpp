#include <iostream>
#include <cmath>

using namespace std;

// Function to apply Liang-Barsky line clipping algorithm
void liangBarsky(double x1, double y1, double x2, double y2, double xmin, double ymin, double xmax, double ymax) {
    double p[4], q[4];
    double t1 = 0.0, t2 = 1.0;

    // Calculate values of parameters p and q for each edge
    p[0] = -(x2 - x1);
    p[1] = x2 - x1;
    p[2] = -(y2 - y1);
    p[3] = y2 - y1;

    q[0] = x1 - xmin;
    q[1] = xmax - x1;
    q[2] = y1 - ymin;
    q[3] = ymax - y1;

    for (int i = 0; i < 4; i++) {
        if (p[i] == 0) {
            if (q[i] < 0) {
                cout << "Line is parallel to clipping window and outside." << endl;
                return;
            }
        } else {
            double r = q[i] / p[i];

            if (p[i] < 0) {
                t1 = max(t1, r);
            } else {
                t2 = min(t2, r);
            }

            if (t1 > t2) {
                cout << "Line is completely outside the clipping window." << endl;
                return;
            }
        }
    }

    // Calculate clipped line coordinates
    double x1_clip = x1 + t1 * (x2 - x1);
    double y1_clip = y1 + t1 * (y2 - y1);
    double x2_clip = x1 + t2 * (x2 - x1);
    double y2_clip = y1 + t2 * (y2 - y1);

    cout << "Line after clipping: (" << x1_clip << ", " << y1_clip << ") to (" << x2_clip << ", " << y2_clip << ")" << endl;
}

int main() {
    double x1, y1, x2, y2, xmin, ymin, xmax, ymax;

    cout << "Enter the coordinates of the line (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    cout << "Enter the clipping window (xmin ymin xmax ymax): ";
    cin >> xmin >> ymin >> xmax >> ymax;

    cout << "Original line: (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")" << endl;
    cout << "Clipping window: (" << xmin << ", " << ymin << ") to (" << xmax << ", " << ymax << ")" << endl;

    liangBarsky(x1, y1, x2, y2, xmin, ymin, xmax, ymax);

    return 0;
}

