#include <cstdlib>
#include <iostream>
#include "graph.hpp"
using namespace std;

class GraphMatrix : public Graph {
    int matrix[10][10];
    char s_vertices[10];
    int num_vert;
    int s_edges[100];
    int num_edge;
    
    int indexOf(char v){
        for (int i = 0; i<num_vert; i++){
            if(s_vertices[i] == v){
                return i;
            }
        }
        return -1;
    }

    public:
    GraphMatrix() {
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
        return s_edges;
    }

    int getEdge(char u, char v)  {
        int uInd = indexOf(u);
        int vInd = indexOf(v);
        if(uInd == -1 || vInd == -1) return 0;
        return matrix[uInd][vInd];
    }

    char* endVertices(int e) {
        char* temp = new char[2];
        for (int i = 0; i<num_vert; i++){
            for (int j = 0; j<num_vert; j++){
                if(matrix[i][j] == e){
                    temp[0] = s_vertices[i];
                    temp[1] = s_vertices[j];
                    return temp;
                }
            }
        }
        temp[0] = '-';
        temp[1] = '-';
        return temp;
    }

    char opposite(char v, int e)  {
        int vInd = indexOf(v);
        if(vInd == -1) return '-';
        
        for (int i = 0; i<num_vert; i++){
            for (int j = 0; j<num_vert; j++){
                if(matrix[i][j] == e){
                    if(v == s_vertices[i]) return s_vertices[j];
                    if(v == s_vertices[j]) return s_vertices[i];
                }
            }
        }
        
        return '-';
    }

    int outDegree(char v)  {
        int vInd = indexOf(v);
        if(vInd == 0) return 0;
        
        int count = 0;
        for (int i = 0; i<num_vert; i++){
            if(matrix[vInd][i] != 0){
                count++;
            }
        }
        return count;
    }

    int inDegree(char v)  {
        int vInd = indexOf(v);
        if(vInd == 0) return 0;
        
        int count = 0;
        for (int i = 0; i<num_vert; i++){
            if(matrix[i][vInd] != 0){
                count++;
            }
        }
        
        return count;
    }

    int* outgoingEdges(char v) {
        int deg = outDegree(v);
        if(deg == 0) return nullptr;
        
        int* temp = new int[deg];
        int vInd = indexOf(v);
        int count = 0;
        for (int i = 0; i<num_vert; i++){
            if(matrix[vInd][i] != 0){
                temp[count++] = matrix[vInd][i];
            }
        }
        return temp;
    }

    int* incomingEdges(char v) {
        int deg = inDegree(v);
        if(deg == 0) return nullptr;
        
        int* temp = new int[deg];
        int vInd = indexOf(v);
        int count = 0;
        for (int i = 0; i<num_vert; i++){
            if(matrix[i][vInd] != 0){
                temp[count++] = matrix[i][vInd];
            }
        }
        return temp;
    }

    bool insertVertex(char x)  {
        if(indexOf(x)!=-1) return false;
        s_vertices[num_vert++] = x;
        return true;
    }

    bool insertEdge(char u, char v, int x)  {
        int uInd = indexOf(u);
        int vInd = indexOf(v);
        
        if(uInd == -1 || vInd == -1) return false;
        matrix[uInd][vInd] = x;
        s_edges[num_edge++] = x;
        return true;
    }

    int removeVertex(char v) {
        int vInd = indexOf(v);
        int count = 0;
        
       
        //remove connected edges from s_edges and the matrix
        for (int i = 0; i<num_vert; i++){
            if(matrix[vInd][i] != 0){ //if v's column has value
                matrix[vInd][i] = 0;
                for (int j = i; j<num_edge-1; j++){
                    s_edges[j] = s_edges[j+1];
                    
                }
                num_edge--;
                count++;
            }
           
            
            if(matrix[i][vInd] != 0){ //if v's row has value
                matrix[i][vInd] = 0;
                for (int k = i; k<num_edge-1; k++){
                    s_edges[k] = s_edges[k+1]; 
                }
                num_edge--;
                count++;
            }
           
        }
        
        //shift array of s_vertices
        for (int i = vInd; i<num_vert; i++){ //correct
            s_vertices[i] = s_vertices[i+1];
        }
        
        //shift rows up 
        for (int i = vInd; i<num_vert; i++){
            for(int j = 0; j<num_vert; j++){
                matrix[i][j] = matrix[i+1][j];
            }
        }
        
        //shift columns to the left
        for (int j = vInd; j<num_vert; j++){
            for(int i = 0; i<num_vert; i++){
                matrix[i][j] = matrix[i][j+1];
            }
        }
         //matrix[num_vert-1][num_vert-1] = 0;
        
        num_vert--;
        return count;
    }

    bool removeEdge(int e)  {
        for(int i = 0; i<num_edge; i++){
            if(s_edges[i] == e){
                for (int j = i; j<num_edge-1; j++){
                    s_edges[i] = s_edges[j+1];
                }
                
            }
        }
        
        for (int i = 0; i<num_vert; i++){
            for (int j = 0; j<num_vert; j++){
                if(matrix[i][j]==e){
                    matrix[i][j] = 0;
                    num_edge--;
                    return true;
                }
            }
        }
        return false;
    }

    void print() {
        cout << "\t";
        for (int i = 0; i < num_vert; i++) {
            cout << s_vertices[i] << "\t";
        }
        cout << endl;
        for (int i = 0; i < num_vert; i++) {
            cout << s_vertices[i] << "\t";
            for (int j = 0; j < num_vert; j++) {
                if (matrix[i][j] != 0) {
                    cout << matrix[i][j];
                }
                cout << "\t";
            }
            cout << endl;
        }
    }
};