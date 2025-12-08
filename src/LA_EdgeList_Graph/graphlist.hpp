#include <cstdlib>
#include <iostream>
#include "graph.hpp"
#include "edge.hpp"
using namespace std;

class GraphList : public Graph {
    Edge** s_edges;
    int num_edge;
    char s_vertices[10];
    int num_vert;

    public:
    GraphList() {
        s_edges = (Edge**) malloc( 100 * sizeof(Edge*) );
        num_vert = 0;
        num_edge = 0;
    }

    int numVertices() {
        return num_vert;
    }

    char* vertices() {
        return s_vertices;
    }

    int numEdges() {
        return num_edge;
    }

    int* edges() {
        int* tempArr = new int[num_edge];
        int count = 0;
        
        for (int i = 0; i<num_edge; i++){
            tempArr[i] = s_edges[i]->getName();
        }
        return tempArr;
    }

    int getEdge(char u, char v)  {
        for (int i = 0; i<num_edge; i++){
            if(s_edges[i]->getOrigin() == u && s_edges[i]->getDestination()==v){
                return s_edges[i]->getName();
            }
        }
        return 0;
    }

    char* endVertices(int e)  {
        char* temp = new char[2];
        for (int i = 0; i<num_edge; i++){
            if(s_edges[i]->getName() == e){
                temp[0] = s_edges[i]->getOrigin();
                temp[1] = s_edges[i]->getDestination();
                return temp;
            }
        }
        temp[0] = '-';
        temp[1] = '-';
        return temp;
    }

    char opposite(char v, int e)  {
        for(int i = 0; i<num_edge; i++){
            if(s_edges[i]->getName()==e){
                if(s_edges[i]->getOrigin()==v) return s_edges[i]->getDestination();
                if(s_edges[i]->getDestination()==v) return s_edges[i]->getOrigin();
            }
        }
        return '-';
    }

    int outDegree(char v)  {
        int count = 0;
        for (int i = 0; i<num_edge; i++){
            if(s_edges[i]->getOrigin() == v){
                count++;
            }
        }
        return count;
    }

    int inDegree(char v)  {
        int count = 0;
        for (int i = 0; i<num_edge; i++){
            if(s_edges[i]->getDestination() == v){
                count++;
            }
        }
        return count;
    }

    int* outgoingEdges(char v) {
        int deg = outDegree(v);
        if(deg == 0) return nullptr;
        int* temp = new int[deg];
        int count = 0;
        for (int i = 0; i<num_edge; i++){
            if(s_edges[i]->getOrigin() == v){
                temp[count++] = s_edges[i]->getName();
               // cout << "Origin: " << count-1 << " " << temp[count-1] << endl; 
            }
        }
        
        return temp;
    }

    int* incomingEdges(char v) {
       int deg = inDegree(v);
        if(deg == 0) return nullptr;
        int* temp = new int[deg];
        int count = 0;
        for (int i = 0; i<num_edge; i++){
            if(s_edges[i]->getDestination() == v){
                temp[count++] = s_edges[i]->getName();
            }
        }
        
        return temp;
    }

    bool insertVertex(char x)  {
        s_vertices[num_vert++] = x;
        return true;
    }

    bool insertEdge(char u, char v, int x)  {
        Edge* e = new Edge(x, u, v);
        s_edges[num_edge++] = e;
        return true;
    }

    int removeVertex(char v) {
        int count = 0;
        for (int i = 0; i<num_edge; i++){
            if(s_edges[i]->getOrigin() == v || s_edges[i]->getDestination() == v){
                for (int j = i; j<num_edge-1; j++){
                    s_edges[j] = s_edges[j+1];
                    
                }
                num_edge--;
                i--;
                count++;
            }  
        }
        
        for (int i = 0; i<num_vert; i++){
            if(s_vertices[i]==v){
                for (int j = i; j<num_vert-1; j++){
                    s_vertices[j] = s_vertices[j+1];
                }
                break;
            }
            
        }
        num_vert--;
        return count;
    }

    bool removeEdge(int e)  {
        for (int i = 0; i<num_edge; i++){
            if(s_edges[i]->getName() == e){
                for (int j = i; j<num_edge; j++){
                    s_edges[j] = s_edges[j+1];
                }
                num_edge--;
                return true;
            }
        }
        return false;
    }

    // DO NOT MODIFY
    void print() {
        cout << "Vertices: ";
        for (int i = 0; i < num_vert; i++) {
            cout << s_vertices[i] << " ";
        }
        cout << endl << "Edges: " << endl;
        for (int i = 0; i < num_edge; i++) {
            s_edges[i]->toString();
            cout << endl;
        }
    }
};