#include <iostream>
#include <stdexcept>
#include <string>
#include "graph.hpp"
using namespace std;

class GraphMatrix : public Graph {
    int cap = 10;
    int matrix[10][10];   // 0 means no edge, otherwise stores the edge label (int)
    char s_vertices[10];  // labels for vertices
    int num_vert;
    int s_edges[100];     // list of edge labels (max 100 for 10x10)
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
    GraphMatrix(){
        num_vert = 0;
        num_edge = 0;
    }

    int numVertices(){
        return num_vert;
    }

    char* vertices(){
        return s_vertices;
    }

    int numEdges(){
        return num_edge;
    }

    int* edges(){
        if(num_edge == 0) return nullptr;
        int* tempArr = new int[num_edge];
        for (int i = 0 ; i<num_edge; i++){
            tempArr[i] = s_edges[i];
        }
        return tempArr;
    }

    int getEdge(char u, char v){
        int uIndex = indexOf(u);
        int vIndex = indexOf(v);

        if(uIndex == -1 || vIndex == -1){
            return -1;
        }
        return matrix[uIndex][vIndex];
    }

   char* endVertices(int e){
    char* tempArr = new char[2];
        for (int i = 0; i<num_vert; i++){
            for (int j = 0; j<num_vert; j++){
                if(matrix[i][j] == e){
                    tempArr[0] = s_vertices[i];
                    tempArr[1] = s_vertices[j];
                    return tempArr;
                }
            }
        }
    return nullptr;
   }

   char getOpposite(char v, int e){
        for (int i = 0; i<num_vert; i++){
            for (int j = 0; j<num_vert; j++){
                if(matrix[i][j] == e){
                    if(s_vertices[i] == v) return s_vertices[j];
                    if(s_vertices[j] == v) return s_vertices[i];
                }
            }
        }
        return '\0';
   }

   // this version compares the indices
    // char getOpposite(char v, int e) {
    //     int vi = indexOf(v);
    //     if (vi == -1) return '\0';
    //     for (int i = 0; i < num_vert; i++)
    //         for (int j = 0; j < num_vert; j++)
    //             if (matrix[i][j] == e) {
    //                 if (vi == i) return s_vertices[j];
    //                 if (vi == j) return s_vertices[i];
    //             }
    //     return '\0';
    // }

    int outDegree(char v){
        int vIndex = indexOf(v);
        if(vIndex == -1) return 0;
        int deg = 0;
        for (int i = 0; i<num_vert; i++){
            if(matrix[vIndex][i] != 0) deg++;
        }
        return deg;
        
    }

    int* outgoingEdges(char v){
        int deg = outDegree(v);
        if(deg == 0) return nullptr;
        int* arr = new int[deg];
        int vIndex = indexOf(v);
        int arrCount = 0;

        for (int i = 0; i<num_vert; i++){
            if(matrix[vIndex][i] != 0){
                arr[arrCount++] = matrix[vIndex][i];
            }
        }
        return arr;
    }

    int inDegree(char v){
        int vIndex = indexOf(v);
        if(vIndex == -1) return 0;
        int deg = 0;
        for (int i = 0; i<num_vert; i++){
            if(matrix[i][vIndex] != 0) deg++;
        }
        return deg;
    }

    int* incomingEdges(char v){
        int deg = inDegree(v);
        if(deg == 0) return nullptr;
        int* arr = new int[deg];
        int vIndex = indexOf(v);
        int arrCount = 0;
        for (int i = 0; i<num_vert; i++){
            if(matrix[i][vIndex] != 0){
                arr[arrCount++] = matrix[i][vIndex];
            }
        }
        return arr;
    }

    // int outDegree(char v) {
    //     int vi = indexOf(v);
    //     if (vi == -1) return 0;
    //     int deg = 0;
    //     for (int j = 0; j < num_vert; j++)
    //         if (matrix[vi][j] != 0) deg++;
    //     return deg;
    // }
    // int* outgoingEdges(char v) {
    //     int deg = outDegree(v);
    //     if (deg == 0) return nullptr;
    //     int* outEdges = new int[deg];
    //     int vi = indexOf(v), k = 0;
    //     for (int j = 0; j < num_vert; j++)
    //         if (matrix[vi][j] != 0)
    //             outEdges[k++] = matrix[vi][j];
    //     return outEdges;
    // }
    // int inDegree(char v) {
    //     int vi = indexOf(v);
    //     if (vi == -1) return 0;
    //     int deg = 0;
    //     for (int i = 0; i < num_vert; i++)
    //         if (matrix[i][vi] != 0) deg++;
    //     return deg;
    // }

    // int* incomingEdges(char v) override {
    //     int deg = inDegree(v);
    //     if (deg == 0) return nullptr;
    //     int* inEdges = new int[deg];
    //     int vi = indexOf(v), k = 0;
    //     for (int i = 0; i < num_vert; i++)
    //         if (matrix[i][vi] != 0)
    //             inEdges[k++] = matrix[i][vi];
    //     return inEdges;
    // }

    char insertVertex(char x){
        if(indexOf(x) != -1){
            throw logic_error("Already has vertex: " + x);
        }

        if(num_vert < cap){
            s_vertices[num_vert++] = x;
        }
        return x;
    }

    // char insertVertex(char x) {
    //     if (indexOf(x) != -1) {
    //         string msg = string("already has vertex: ") + x;
    //         throw logic_error(msg);
    //     }
    //     if (num_vert < cap) s_vertices[num_vert++] = x;
    //     return x;
    // }

    int insertEdge(char u, char v, int x){
        int uInd = indexOf(u);
        int vInd = indexOf(v);

        if(uInd == -1 || vInd == -1) return -1;
        if(matrix[uInd][vInd] != 0){
            throw logic_error(string(1,u) + " to " + v + " already has vertex: " + to_string(matrix[uInd][vInd]));
        }

        matrix[uInd][vInd] = x;
        if (num_edge < 100) s_edges[num_edge++] = x;
        return x;
    }

    // int insertEdge(char u, char v, int x) {
    //     int ui = indexOf(u), vi = indexOf(v);
    //     if (ui == -1 || vi == -1) return -1;
    //     if (matrix[ui][vi] != 0) {
    //         int existing = matrix[ui][vi];
    //         string msg = string("already has edge from ") + u + " to " + v + ": " + to_string(existing);
    //         throw logic_error(msg);
    //     }
    //     matrix[ui][vi] = x;
    //     if (num_edge < 100) s_edges[num_edge++] = x;
    //     return x;
    // }

    void removeVertex(char v){
        int vInd = indexOf(v);
        if(vInd == -1) return;

        //remove all edges connecting v
        //iterate through the vertices
        for (int i = 0; i<num_vert; i++){
            //iterate through the columns in row vInd
            if(matrix[vInd][i] != 0){
                int val = matrix[vInd][i];
                //iterate through s_edges to remove the edge
                for (int j = 0; j<num_edge-1; j++){
                    if(s_edges[j] == val){
                        s_edges[j] = s_edges[j+1];
                        num_edge--;
                        break;
                    }
                }
                matrix[vInd][i] = 0;
            }
            //iterate through the rows from column vInd
            if(matrix[i][vInd] != 0){
                int val = matrix[i][vInd];
                for (int j = 0; j<num_edge-1; j++){
                    if(s_edges[j] == val){
                        s_edges[j] = s_edges[j+1];
                        num_edge--;
                        break;
                    }
                }
            }
            matrix[i][vInd] = 0;
        }
        
        //remove vertex from s_vert
        for (int i = vInd; i<num_vert-1; i++){
            s_vertices[i] = s_vertices[i+1];
        }
        
        //shift row upwards
        for (int i = vInd; i<num_vert-1; i++){ //iterate through columns of row vInd
            for (int j = 0; j<num_vert; j++){
                matrix[i][j] = matrix[i+1][j]; //shift the row
            }
        }

        //shift column to the left
        for (int i = vInd; i<num_vert-1; i++){ 
            for (int j = 0; j<num_vert; j++){
                matrix[j][i] = matrix[j][i+1]; //shift the column
            }
        }

        num_vert--;
    }

    // void removeVertex(char v) {
    //     int vi = indexOf(v);
    //     if (vi == -1) return;

    //     // Remove edges incident to the vertex and remove their records from s_edges
    //     for (int i = 0; i < num_vert; i++) {
    //         if (matrix[vi][i] != 0) {
    //             int val = matrix[vi][i];
    //             for (int k = 0; k < num_edge; k++) {
    //                 if (s_edges[k] == val) {
    //                     for (int t = k; t < num_edge - 1; t++) s_edges[t] = s_edges[t + 1];
    //                     num_edge--; break;
    //                 }
    //             }
    //             matrix[vi][i] = 0;
    //         }
    //         if (matrix[i][vi] != 0) {
    //             int val = matrix[i][vi];
    //             for (int k = 0; k < num_edge; k++) {
    //                 if (s_edges[k] == val) {
    //                     for (int t = k; t < num_edge - 1; t++) s_edges[t] = s_edges[t + 1];
    //                     num_edge--; break;
    //                 }
    //             }
    //             matrix[i][vi] = 0;
    //         }
    //     }

    //     // Shift vertex labels left
    //     for (int i = vi; i < num_vert - 1; i++) s_vertices[i] = s_vertices[i + 1];

    //     // Shift matrix rows up
    //     for (int i = vi; i < num_vert - 1; i++)
    //         for (int j = 0; j < num_vert; j++)
    //             matrix[i][j] = matrix[i + 1][j];

    //     // Shift matrix columns left
    //     for (int j = vi; j < num_vert - 1; j++)
    //         for (int i = 0; i < num_vert; i++)
    //             matrix[i][j] = matrix[i][j + 1];

    //     // zero out the now-unused last row/column
    //     for (int j = 0; j < num_vert; j++) matrix[num_vert - 1][j] = 0;
    //     for (int i = 0; i < num_vert; i++) matrix[i][num_vert - 1] = 0;

    //     num_vert--;
    // }

    void removeEdge(int e){
        for (int i = 0; i<num_vert; i++){
            for (int j = 0; j<num_vert; j++){
                if(matrix[i][j] == e){ //we found it in the matrix, and we make it 0
                    matrix[i][j] = 0;
                
                    //shift the elements of s_edges
                    for (int k = 0; k<num_edge-1; k++){
                        if(s_edges[k] == e){
                            s_edges[k] = s_edges[k+1];
                            num_edge--;
                            break;
                        }
                    }
                    return;
                }
            }
        }
    }

    // void removeEdge(int e) {
    //     for (int i = 0; i < num_vert; i++)
    //         for (int j = 0; j < num_vert; j++)
    //             if (matrix[i][j] == e) {
    //                 matrix[i][j] = 0;
    //                 for (int k = 0; k < num_edge; k++) {
    //                     if (s_edges[k] == e) {
    //                         for (int t = k; t < num_edge - 1; t++) s_edges[t] = s_edges[t + 1];
    //                         num_edge--; break;
    //                     }
    //                 }
    //                 return;
    //             }
    // }
    
    void print() {
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