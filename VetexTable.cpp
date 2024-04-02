#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

// Function to create the vertex table
vector<tuple<double, double>> vertexTable(const vector<tuple<double, double>>& vertices) {
    return vertices;
}

// Function to create the edge table
vector<tuple<string, int, int>> edgeTable(const vector<tuple<double, double>>& vertices) {
    vector<tuple<string, int, int>> edges;
    for (int i = 0; i < vertices.size(); ++i) {
        int nextIndex = (i + 1) % vertices.size();
        edges.push_back(make_tuple("E" + to_string(i + 1), i + 1, nextIndex + 1));
    }
    return edges;
}

// Function to create the polygon surface table
vector<tuple<string, int, int>> surfaceTable(const vector<tuple<double, double>>& vertices) {
    vector<tuple<string, int, int>> surfaces;
    for (int i = 0; i < vertices.size(); ++i) {
        int nextIndex1 = (i + 1) % vertices.size();
        surfaces.push_back(make_tuple("S" + to_string(i + 1), i + 1, nextIndex1 + 1));
    }
    return surfaces;
}

// Function to input vertices from the user
vector<tuple<double, double>> inputVertices() {
    vector<tuple<double, double>> vertices;
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    for (int i = 0; i < numVertices; ++i) {
        double x, y;
        cout << "Enter x-coordinate for vertex " << i + 1 << ": ";
        cin >> x;
        cout << "Enter y-coordinate for vertex " << i + 1 << ": ";
        cin >> y;
        vertices.push_back(make_tuple(x, y));
    }
    return vertices;
}

int main() {
    // Get vertices from user
    vector<tuple<double, double>> vertices = inputVertices();

    // Create and display vertex table
    cout << "\nVertex Table:\n";
    for (int i = 0; i < vertices.size(); ++i) {
        cout << "v" << i + 1 << ": ";
        cout << "(" << get<0>(vertices[i]) << ", " << get<1>(vertices[i]) << ")\n";
    }

    // Create and display edge table
    vector<tuple<string, int, int>> edges = edgeTable(vertices);
    cout << "\nEdge Table:\n";
    for (int i = 0; i < edges.size(); ++i) {
        cout << get<0>(edges[i]) << ": ";
        cout << "(" << get<1>(edges[i]) << ", " << get<2>(edges[i]) << ")\n";
    }

    // Create and display polygon surface table
    vector<tuple<string, int, int>> surfaces = surfaceTable(vertices);
    cout << "\nPolygon Surface Table:\n";
    for (int i = 0; i < surfaces.size(); ++i) {
        cout << get<0>(surfaces[i]) << ": ";
        cout << "(" << get<1>(surfaces[i]) << ", " << get<2>(surfaces[i]) << ")\n";
    }

    return 0;
}
