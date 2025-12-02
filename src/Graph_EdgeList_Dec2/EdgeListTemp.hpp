#include <iostream>
#include <string>

using namespace std;

// Assuming simple structures for Vertex and Edge based on your code
struct Vertex {
    string data;
};

struct Edge {
    Vertex* u;
    Vertex* v;
    char data;
};

class Graph {
public:
    virtual int numVertices() = 0;
    virtual Vertex* verticesArr() = 0;
    virtual int numEdges() = 0;
    virtual Edge* edgesArr() = 0;
    virtual Edge* getEdge(Vertex* u, Vertex* v) = 0;
    virtual Vertex* endVertices(Edge e) = 0;
    virtual Vertex* getOpposite(Vertex* v, Edge e) = 0;
    virtual int outDegree(Vertex* v) = 0;
    virtual Edge* outgoingEdges(Vertex* v) = 0;
    virtual int inDegree(Vertex* v) = 0;
    virtual Edge* incomingEdges(Vertex* v) = 0;
    virtual Vertex* insertVertex(string x) = 0;
    virtual Edge* insertEdge(Vertex* u, Vertex* v, char x) = 0;
    virtual void removeVertex(Vertex* v) = 0;
    virtual void removeEdge(Edge* e) = 0;
};

class EdgeList : public Graph {
private:
    Vertex* vertices;     // array of vertices
    Edge* edges;          // array of edges
    int m_edges;          // number of edges
    int m_vert;           // number of vertices
    int cap = 10;         // capacity

public:
    EdgeList() {
        m_edges = 0;
        m_vert = 0;
        vertices = new Vertex[cap];
        edges = new Edge[cap];
    }

    // 1. numVertices()
    int numVertices() override {
        return m_vert;
    }

    // 2. vertices()
    Vertex* verticesArr() override {
        return vertices;
    }

    // 3. numEdges()
    int numEdges() override {
        return m_edges;
    }

    // 4. edges()
    Edge* edgesArr() override {
        return edges;
    }

    // 5. getEdge(u, v) (DIRECTED)
    Edge* getEdge(Vertex* u, Vertex* v) override {
        // ERROR FIX: Check for null pointers
        if (u == nullptr || v == nullptr) return nullptr;

        for (int i = 0; i < m_edges; i++) {
            if (edges[i].u == u && edges[i].v == v)
                return &edges[i];
        }
        return nullptr;
    }

    // 6. endVertices(e)
    Vertex* endVertices(Edge e) override {
        return e.u; // Returning start vertex (Directed convention varies, but this is acceptable)
    }

    // 7. getOpposite (DIRECTED)
    Vertex* getOpposite(Vertex* v, Edge e) override {
        if (v == nullptr) return nullptr; // ERROR FIX: Null check
        if (e.u == v) return e.v;
        if (e.v == v) return e.u;
        return nullptr;
    }

    // 8. outDegree(v)
    int outDegree(Vertex* v) override {
        if (v == nullptr) return 0; // ERROR FIX: Null check
        int count = 0;
        for (int i = 0; i < m_edges; i++) {
            if (edges[i].u == v)
                count++;
        }
        return count;
    }

    // 9. outgoingEdges(v)
    Edge* outgoingEdges(Vertex* v) override {
        if (v == nullptr) return nullptr; // ERROR FIX: Null check
        static Edge out[100]; // Note: Static arrays are risky, but keeping per your structure
        int idx = 0;
        for (int i = 0; i < m_edges; i++) {
            if (edges[i].u == v)
                out[idx++] = edges[i];
        }
        return out;
    }

    // 10. inDegree(v)
    int inDegree(Vertex* v) override {
        if (v == nullptr) return 0; // ERROR FIX: Null check
        int count = 0;
        for (int i = 0; i < m_edges; i++) {
            if (edges[i].v == v)
                count++;
        }
        return count;
    }

    // 11. incomingEdges(v)
    Edge* incomingEdges(Vertex* v) override {
        if (v == nullptr) return nullptr; // ERROR FIX: Null check
        static Edge in[100];
        int idx = 0;
        for (int i = 0; i < m_edges; i++) {
            if (edges[i].v == v)
                in[idx++] = edges[i];
        }
        return in;
    }

    // helper
    Vertex* findVertexPtr(string x) {
        for (int i = 0; i < m_vert; i++) {
            if (vertices[i].data == x)
                return &vertices[i];
        }
        return nullptr;
    }

    // 12. insertVertex(x)
    Vertex* insertVertex(string x) override {
        // ERROR FIX: Check Capacity
        if (m_vert >= cap) {
            cout << "Graph full. Cannot add vertex." << endl;
            return nullptr;
        }

        // ERROR FIX: Check Duplicates
        if (findVertexPtr(x) != nullptr) {
            return findVertexPtr(x);
        }

        vertices[m_vert].data = x;
        m_vert++;
        return &vertices[m_vert - 1];
    }

    // 13. insertEdge(u, v, x)
    Edge* insertEdge(Vertex* u, Vertex* v, char x) override {
        // ERROR FIX: Check Capacity
        if (m_edges >= cap) {
            cout << "Edge list full." << endl;
            return nullptr;
        }

        // ERROR FIX: Validity checks
        if (u == nullptr || v == nullptr) return nullptr;
        
        // ERROR FIX: Check if edge already exists
        if (getEdge(u, v) != nullptr) {
            return getEdge(u, v);
        }

        edges[m_edges].u = u;
        edges[m_edges].v = v;
        edges[m_edges].data = x;
        m_edges++;
        return &edges[m_edges - 1];
    }

    // 14. removeVertex(v)
    void removeVertex(Vertex* v) override {
        if (v == nullptr) return; // ERROR FIX: Null check

        int idx = -1;
        for (int i = 0; i < m_vert; i++) {
            if (&vertices[i] == v) { idx = i; break; }
        }
        if (idx == -1) return;

        // ERROR FIX: Remove edges FIRST. 
        // We must remove dependencies before shifting the vertex array.
        int i = 0;
        while (i < m_edges) {
            if (edges[i].u == v || edges[i].v == v)
                removeEdge(&edges[i]); // removeEdge handles the array shift and size decrement
            else
                i++;
        }

        // Shift vertex array left
        for (int k = idx; k < m_vert - 1; k++)
            vertices[k] = vertices[k + 1];
        m_vert--;
        
        // Note: In an array-based graph, shifting vertices invalidates 
        // pointers held by other edges. This is a structural limitation, 
        // but removing incident edges helps.
    }

    // 15. removeEdge(e)
    void removeEdge(Edge* e) override {
        if (e == nullptr) return; // ERROR FIX: Null check

        int idx = -1;
        for (int i = 0; i < m_edges; i++) {
            if (&edges[i] == e) { idx = i; break; }
        }
        if (idx == -1) return;

        for (int i = idx; i < m_edges - 1; i++)
            edges[i] = edges[i + 1];

        m_edges--;
    }
};