#include "graph.hpp"

class AdjacencyMatrix : public Graph {
private:
    int cap = 10;
    int numVerticesVar;
    int numEdgesVar;
    Vertex vertexList[10];
    Edge* matrix[10][10];

    int indexOf(Vertex v) {
        for (int i = 0; i < numVerticesVar; i++)
            if (vertexList[i].data == v.data) return i;
        return -1;
    }

public:
    AdjacencyMatrix() {
        numVerticesVar = 0;
        numEdgesVar = 0;
        for (int i = 0; i < cap; i++)
            for (int j = 0; j < cap; j++)
                matrix[i][j] = nullptr;
    }

    int numVertices() { return numVerticesVar; }

    Vertex* vertices() { return vertexList; }

    int numEdges() { return numEdgesVar; }

    Edge* edges() {
        if (numEdgesVar == 0) return nullptr;
        Edge* allEdges = new Edge[numEdgesVar];
        int k = 0;
        for (int i = 0; i < numVerticesVar; i++)
            for (int j = 0; j < numVerticesVar; j++)
                if (matrix[i][j] != nullptr)
                    allEdges[k++] = *(matrix[i][j]);
        return allEdges;
    }

    Edge getEdge(Vertex u, Vertex v) {
        int ui = indexOf(u), vi = indexOf(v);
        if (ui == -1 || vi == -1 || matrix[ui][vi] == nullptr)
            return Edge{'0'};
        return *(matrix[ui][vi]);
    }

    Vertex* endVertices(Edge e) {
        for (int i = 0; i < numVerticesVar; i++)
            for (int j = 0; j < numVerticesVar; j++)
                if (matrix[i][j] != nullptr && matrix[i][j]->data == e.data) {
                    Vertex* ends = new Vertex[2];
                    ends[0] = vertexList[i];
                    ends[1] = vertexList[j];
                    return ends;
                }
        return nullptr;
    }

    Vertex getOpposite(Vertex v, Edge e) {
        int vi = indexOf(v);
        for (int i = 0; i < numVerticesVar; i++)
            for (int j = 0; j < numVerticesVar; j++)
                if (matrix[i][j] != nullptr && matrix[i][j]->data == e.data) {
                    if (vi == i) return vertexList[j];
                    if (vi == j) return vertexList[i];
                }
        return Vertex{"NONE"};
    }

    int outDegree(Vertex v) {
        int vi = indexOf(v), deg = 0;
        for (int j = 0; j < numVerticesVar; j++)
            if (matrix[vi][j] != nullptr) deg++;
        return deg;
    }

    Edge* outgoingEdges(Vertex v) {
        int deg = outDegree(v);
        Edge* outEdges = new Edge[deg];
        int vi = indexOf(v), k = 0;
        for (int j = 0; j < numVerticesVar; j++)
            if (matrix[vi][j] != nullptr)
                outEdges[k++] = *(matrix[vi][j]);
        return outEdges;
    }

    int inDegree(Vertex v) {
        int vi = indexOf(v), deg = 0;
        for (int i = 0; i < numVerticesVar; i++)
            if (matrix[i][vi] != nullptr) deg++;
        return deg;
    }

    Edge* incomingEdges(Vertex v) {
        int deg = inDegree(v);
        Edge* inEdges = new Edge[deg];
        int vi = indexOf(v), k = 0;
        for (int i = 0; i < numVerticesVar; i++)
            if (matrix[i][vi] != nullptr)
                inEdges[k++] = *(matrix[i][vi]);
        return inEdges;
    }

    Vertex insertVertex(string x) {
        Vertex v;
        v.data = x;
        if (numVerticesVar < cap) vertexList[numVerticesVar++] = v;
        return v;
    }

    Edge insertEdge(Vertex u, Vertex v, char x) {
        int ui = indexOf(u), vi = indexOf(v);
        if (ui == -1 || vi == -1) return Edge{'0'};
        if (matrix[ui][vi] == nullptr) {
            Edge* e = new Edge;
            e->data = x;
            matrix[ui][vi] = e;
            numEdgesVar++;
            return *e;
        }
        return *(matrix[ui][vi]);
    }

    void removeVertex(Vertex v) {
        int vi = indexOf(v);
        if (vi == -1) return;
        for (int i = 0; i < numVerticesVar; i++) {
            if (matrix[vi][i]) { delete matrix[vi][i]; numEdgesVar--; }
            if (matrix[i][vi]) { delete matrix[i][vi]; numEdgesVar--; }
        }
        for (int i = vi; i < numVerticesVar - 1; i++) vertexList[i] = vertexList[i + 1];
        for (int i = vi; i < numVerticesVar - 1; i++)
            for (int j = 0; j < numVerticesVar; j++)
                matrix[i][j] = matrix[i + 1][j];
        for (int j = vi; j < numVerticesVar - 1; j++)
            for (int i = 0; i < numVerticesVar; i++)
                matrix[i][j] = matrix[i][j + 1];
        numVerticesVar--;
    }

    void removeEdge(Edge e) {
        for (int i = 0; i < numVerticesVar; i++)
            for (int j = 0; j < numVerticesVar; j++)
                if (matrix[i][j] != nullptr && matrix[i][j]->data == e.data) {
                    delete matrix[i][j];
                    matrix[i][j] = nullptr;
                    numEdgesVar--;
                    return;
                }
    }
};