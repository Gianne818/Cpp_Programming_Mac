#include "vertex.hpp"
#include "edge.hpp"

class Graph {
public:
    virtual int numVertices() = 0;
    virtual Vertex* vertices() = 0;
    virtual int numEdges() = 0;
    virtual Edge* edges() = 0;
    virtual Edge getEdge(Vertex u, Vertex v) = 0;
    virtual Vertex* endVertices(Edge e) = 0;
    virtual Vertex getOpposite(Vertex v, Edge e) = 0;
    virtual int outDegree(Vertex v) = 0;
    virtual Edge* outgoingEdges(Vertex v) = 0;
    virtual int inDegree(Vertex v) = 0;
    virtual Edge* incomingEdges(Vertex v) = 0;
    virtual Vertex insertVertex(string x) = 0;
    virtual Edge insertEdge(Vertex u, Vertex v, char x) = 0;
    virtual void removeVertex(Vertex v) = 0;
    virtual void removeEdge(Edge e) = 0;
};