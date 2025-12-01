class Graph {
public:
    virtual int numVertices() = 0;
    virtual char* vertices() = 0;            // array of vertex labels (chars). Caller must not assume null-termination.
    virtual int numEdges() = 0;
    virtual int* edges() = 0;                // array of edge labels (ints). Caller deletes returned array.
    virtual int getEdge(char u, char v) = 0; // returns edge label or -1 if none
    virtual char* endVertices(int e) = 0;    // returns two-char array (caller deletes) or nullptr
    virtual char getOpposite(char v, int e) = 0;
    virtual int outDegree(char v) = 0;
    virtual int* outgoingEdges(char v) = 0;  // caller deletes returned array
    virtual int inDegree(char v) = 0;
    virtual int* incomingEdges(char v) = 0;  // caller deletes returned array
    virtual char insertVertex(char x) = 0;   // insert vertex label
    virtual int insertEdge(char u, char v, int x) = 0; // insert edge with int label
    virtual void removeVertex(char v) = 0;
    virtual void removeEdge(int e) = 0;
    virtual void print() = 0;                // print graph representation
};

