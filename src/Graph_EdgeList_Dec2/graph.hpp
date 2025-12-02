#include "vertex.hpp"
#include "edge.hpp"

class Graph {
public:
    virtual int numVertices() = 0;
    virtual Vertex* vertices() = 0;            // array of vertex labels (chars). Caller must not assume null-termination.
    virtual int numEdges() = 0;
    virtual Edge* edges() = 0;                // array of edge labels (ints). Caller deletes returned array.
    virtual Edge getEdge(Vertex u, Vertex v) = 0; // returns edge label or -1 if none
    virtual Vertex* endVertices(Edge e) = 0;    // returns two-Vertex array (caller deletes) or nullptr
    virtual Vertex getOpposite(Vertex v, Edge e) = 0;
    virtual int outDegree(Vertex v) = 0;
    virtual Edge* outgoingEdges(Vertex v) = 0;  // caller deletes returned array
    virtual int inDegree(Vertex v) = 0;
    virtual Edge* incomingEdges(Vertex v) = 0;  // caller deletes returned array
    virtual Vertex insertVertex(Vertex x) = 0;   // insert vertex label
    virtual Edge insertEdge(Vertex u, Vertex v, int x) = 0; // insert edge with int label
    virtual void removeVertex(Vertex v) = 0;
    virtual void removeEdge(Edge e) = 0;
    virtual void print() = 0;                // print graph representation
};

