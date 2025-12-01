#include <iostream>
#include "graph.hpp"

class GraphMatrix : public Graph {
private:
    int cap = 10;
    int matrix[10][10];   // 0 means no edge, otherwise stores the edge label (int)
    char s_vertices[10];  // labels for vertices
    int num_vert;
    int s_edges[100];     // list of edge labels (max 100 for 10x10)
    int num_edge;

    int indexOf(char v) {
        for (int i = 0; i < num_vert; i++)
            if (s_vertices[i] == v) return i;
        return -1;
    }

public:
    GraphMatrix() : num_vert(0), num_edge(0) {
        for (int i = 0; i < cap; i++)
            for (int j = 0; j < cap; j++)
                matrix[i][j] = 0;
        for (int i = 0; i < 100; i++) s_edges[i] = 0;
    }

    int numVertices() override { return num_vert; }

    char* vertices() override { return s_vertices; }

    int numEdges() override { return num_edge; }

    int* edges() override {
        if (num_edge == 0) return nullptr;
        int* allEdges = new int[num_edge];
        for (int k = 0; k < num_edge; k++) allEdges[k] = s_edges[k];
        return allEdges;
    }

    int getEdge(char u, char v) override {
        int ui = indexOf(u), vi = indexOf(v);
        if (ui == -1 || vi == -1) return -1;
        return matrix[ui][vi];
    }

    char* endVertices(int e) override {
        for (int i = 0; i < num_vert; i++)
            for (int j = 0; j < num_vert; j++)
                if (matrix[i][j] == e) {
                    char* ends = new char[2];
                    ends[0] = s_vertices[i];
                    ends[1] = s_vertices[j];
                    return ends;
                }
        return nullptr;
    }

    char getOpposite(char v, int e) override {
        int vi = indexOf(v);
        if (vi == -1) return '\0';
        for (int i = 0; i < num_vert; i++)
            for (int j = 0; j < num_vert; j++)
                if (matrix[i][j] == e) {
                    if (vi == i) return s_vertices[j];
                    if (vi == j) return s_vertices[i];
                }
        return '\0';
    }

    int outDegree(char v) override {
        int vi = indexOf(v);
        if (vi == -1) return 0;
        int deg = 0;
        for (int j = 0; j < num_vert; j++)
            if (matrix[vi][j] != 0) deg++;
        return deg;
    }

    int* outgoingEdges(char v) override {
        int deg = outDegree(v);
        if (deg == 0) return nullptr;
        int* outEdges = new int[deg];
        int vi = indexOf(v), k = 0;
        for (int j = 0; j < num_vert; j++)
            if (matrix[vi][j] != 0)
                outEdges[k++] = matrix[vi][j];
        return outEdges;
    }

    int inDegree(char v) override {
        int vi = indexOf(v);
        if (vi == -1) return 0;
        int deg = 0;
        for (int i = 0; i < num_vert; i++)
            if (matrix[i][vi] != 0) deg++;
        return deg;
    }

    int* incomingEdges(char v) override {
        int deg = inDegree(v);
        if (deg == 0) return nullptr;
        int* inEdges = new int[deg];
        int vi = indexOf(v), k = 0;
        for (int i = 0; i < num_vert; i++)
            if (matrix[i][vi] != 0)
                inEdges[k++] = matrix[i][vi];
        return inEdges;
    }

    char insertVertex(char x) override {
        if (num_vert < cap) s_vertices[num_vert++] = x;
        return x;
    }

    int insertEdge(char u, char v, int x) override {
        int ui = indexOf(u), vi = indexOf(v);
        if (ui == -1 || vi == -1) return -1;
        if (matrix[ui][vi] == 0) {
            matrix[ui][vi] = x;
            if (num_edge < 100) s_edges[num_edge++] = x;
            return x;
        }
        return matrix[ui][vi];
    }

    void removeVertex(char v) override {
        int vi = indexOf(v);
        if (vi == -1) return;

        // Remove edges incident to the vertex and remove their records from s_edges
        for (int i = 0; i < num_vert; i++) {
            if (matrix[vi][i] != 0) {
                int val = matrix[vi][i];
                for (int k = 0; k < num_edge; k++) {
                    if (s_edges[k] == val) {
                        for (int t = k; t < num_edge - 1; t++) s_edges[t] = s_edges[t + 1];
                        num_edge--; break;
                    }
                }
                matrix[vi][i] = 0;
            }
            if (matrix[i][vi] != 0) {
                int val = matrix[i][vi];
                for (int k = 0; k < num_edge; k++) {
                    if (s_edges[k] == val) {
                        for (int t = k; t < num_edge - 1; t++) s_edges[t] = s_edges[t + 1];
                        num_edge--; break;
                    }
                }
                matrix[i][vi] = 0;
            }
        }

        // Shift vertex labels left
        for (int i = vi; i < num_vert - 1; i++) s_vertices[i] = s_vertices[i + 1];

        // Shift matrix rows up
        for (int i = vi; i < num_vert - 1; i++)
            for (int j = 0; j < num_vert; j++)
                matrix[i][j] = matrix[i + 1][j];

        // Shift matrix columns left
        for (int j = vi; j < num_vert - 1; j++)
            for (int i = 0; i < num_vert; i++)
                matrix[i][j] = matrix[i][j + 1];

        // zero out the now-unused last row/column
        for (int j = 0; j < num_vert; j++) matrix[num_vert - 1][j] = 0;
        for (int i = 0; i < num_vert; i++) matrix[i][num_vert - 1] = 0;

        num_vert--;
    }

    void removeEdge(int e) override {
        for (int i = 0; i < num_vert; i++)
            for (int j = 0; j < num_vert; j++)
                if (matrix[i][j] == e) {
                    matrix[i][j] = 0;
                    for (int k = 0; k < num_edge; k++) {
                        if (s_edges[k] == e) {
                            for (int t = k; t < num_edge - 1; t++) s_edges[t] = s_edges[t + 1];
                            num_edge--; break;
                        }
                    }
                    return;
                }
    }
    
    void print() override {
        using std::cout;
        using std::endl;
        cout << "Vertices: (";
        for (int i = 0; i < num_vert; i++) {
            cout << s_vertices[i];
            if (i != num_vert - 1) cout << ", ";
        }
        cout << ")" << endl;

        cout << "Edges: (";
        for (int i = 0; i < num_edge; i++) {
            cout << s_edges[i];
            if (i != num_edge - 1) cout << ", ";
        }
        cout << ")" << endl;

        cout << "Adjacency matrix:" << endl;
        // header
        cout << "  ";
        for (int j = 0; j < num_vert; j++) cout << s_vertices[j] << " ";
        cout << endl;
        for (int i = 0; i < num_vert; i++) {
            cout << s_vertices[i] << " ";
            for (int j = 0; j < num_vert; j++) {
                if (matrix[i][j] == 0) cout << ". "; else cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};