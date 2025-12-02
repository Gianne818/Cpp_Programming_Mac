#include <iostream>
#include <stdexcept>
#include <string>
#include "graph.hpp"
using namespace std;

    // virtual int numVertices() = 0;
    // virtual Vertex* vertices() = 0;            // array of vertex labels (chars). Caller must not assume null-termination.
    // virtual int numEdges() = 0;
    // virtual Edge* edges() = 0;                // array of edge labels (ints). Caller deletes returned array.
    // virtual Edge getEdge(char u, char v) = 0; // returns edge label or -1 if none
    // virtual Vertex* endVertices(int e) = 0;    // returns two-char array (caller deletes) or nullptr
    // virtual Vertex getOpposite(char v, int e) = 0;
    // virtual int outDegree(char v) = 0;
    // virtual Edge* outgoingEdges(char v) = 0;  // caller deletes returned array
    // virtual int inDegree(char v) = 0;
    // virtual Edge* incomingEdges(char v) = 0;  // caller deletes returned array
    // virtual Vertex insertVertex(char x) = 0;   // insert vertex label
    // virtual Edge insertEdge(char u, char v, int x) = 0; // insert edge with int label
    // virtual void removeVertex(char v) = 0;
    // virtual void removeEdge(int e) = 0;
    // virtual void print() = 0;                // print graph representation

class EdgeList : public Graph{
    Vertex* m_vert;
    Edge* m_edges;
    int num_edges;
    int num_vert;
    int cap = 10;

public:
    EdgeList(){
        num_edges = 0;
        num_vert = 0;
    }

    int numVertices(){
        return num_vert;
    }

    Vertex* vertices(){
        return m_vert;
    }

    int numEdges(){
        return num_edges;
    }

    Edge* edges(){
        return m_edges;
    }

    Edge getEdge(Vertex u, Vertex v){
        for (int i = 0; i<num_edges; i++){
            if(m_edges[i].u->data == u->data && m_edges[i].v->data == v->data)
        }
    }

    Vertex* endVertices(Edge e){
        Vertex* arr = new Vertex[2];
        
        for (int i = 0; i<num_edges; i++){
            if(m_edge[i] == e){
                arr[0] = e.u;
                arr[1] = e.v;
                return arr;
            }
        }
        return nullptr;
    }

    Vertex getOpposite(Vertex v, Edge e){
        if(e.u == v) return e.v;
        for (int i = 0; i<num_edges; i++){
            if(m_edges[i]==e){
                if(m_edges[i].u->data == v->data) return m_edges[i].v;
                if(m_edges[i].v->data == v->data) return m_edges[i].u;
            }
        }
        return nullptr;
    }

    int outDegree(Vertex v){
        int count = 0;
        for (int i = 0; i<num_edges; i++){
            if(m_edges[i].u->data == v->data) count++;
        }
        return count;
    }

    int inDegree(Vertex v){
        int count = 0;
        for(int i = 0; i<num_edges; i++){
            if(m_edges[i].v->data == v->data) count++;
        }
        return count;
    }

    Edge* outgoingEdges(Vertex v){
        int count = outDegree(v);
        if(count == 0) return nullptr;

        Edge* arr = new Edge[count];
        int j = 0;
        for (int i = 0; i<num_edges; i++){
            if(m_edges[i].u->data == v->data){
                arr[j++] = m_edges[i];
            }
        }
        return arr;
    }

    Edge* incomingEdges(Vertex v){
        int count = inDegree(v);
        if(count == 0) return nullptr;

        Edge* arr = new Edge[count];
        int j = 0;
        for (int i = 0; i<num_edges; i++){
            if(m_edges[i].v->data == v->data){
                arr[j++] = m_edges[i];
            }
        }
        return arr;
    }
};