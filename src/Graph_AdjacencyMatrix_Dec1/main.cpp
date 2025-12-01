#include <iostream>
#include <string>
#include "adjacencyMatrix.hpp"
using namespace std;

int main() {
    Graph* graph = new AdjacencyMatrix();
    char op;
    do {
        cout << "Op: ";
        cin >> op;
        switch(op) {
            case 'v': {
                string name;
                cin >> name;
                Vertex u = graph->insertVertex(name);
                cout << "Inserted vertex " << u.data << endl;
                break;
            }
            case 'e': {
                string uName, vName;
                char label;
                cin >> uName >> vName >> label;
                Vertex* vertices = graph->vertices();
                Vertex u, v;
                for(int i=0;i<graph->numVertices();i++){
                    if(vertices[i].data==uName) u=vertices[i];
                    if(vertices[i].data==vName) v=vertices[i];
                }
                Edge edge = graph->insertEdge(u,v,label);
                cout << "Inserted edge " << edge.data << " from " << u.data << " to " << v.data << endl;
                break;
            }
            case 'n':
                cout << "Number of vertices: " << graph->numVertices() << endl;
                break;
            case 'm':
                cout << "Number of edges: " << graph->numEdges() << endl;
                break;
            case 'p': {
                cout << "(";
                for(int i=0;i<graph->numVertices();i++){
                    cout << graph->vertices()[i].data;
                    if(i != graph->numVertices()-1) cout << ", ";
                }
                cout << ")" << endl;
                break;
            }
            case 'q': {
                int m = graph->numEdges();
                Edge* allEdges = graph->edges();
                cout << "(";
                for(int i=0;i<m;i++){
                    cout << allEdges[i].data;
                    if(i != m-1) cout << ", ";
                }
                cout << ")" << endl;
                delete[] allEdges;
                break;
            }
            case 'g': {
                string uName, vName;
                cin >> uName >> vName;
                Vertex* vertices = graph->vertices();
                Vertex u, v;
                for(int i=0;i<graph->numVertices();i++){
                    if(vertices[i].data==uName) u=vertices[i];
                    if(vertices[i].data==vName) v=vertices[i];
                }
                Edge e = graph->getEdge(u,v);
                cout << "Edge between " << u.data << " and " << v.data << ": " << e.data << endl;
                break;
            }
            case 'f': {
                char label;
                cin >> label;
                Edge e{label};
                Vertex* ends = graph->endVertices(e);
                if(ends){
                    cout << "Edge " << label << " connects (" << ends[0].data << ", " << ends[1].data << ")" << endl;
                    delete[] ends;
                } else cout << "Edge not found" << endl;
                break;
            }
            case 't': {
                string vName;
                char label;
                cin >> vName >> label;
                Vertex* vertices = graph->vertices();
                Vertex v;
                for(int i=0;i<graph->numVertices();i++)
                    if(vertices[i].data==vName) v=vertices[i];
                Edge e{label};
                Vertex opp = graph->getOpposite(v,e);
                cout << "Opposite of " << v.data << " on edge " << label << ": " << opp.data << endl;
                break;
            }
            case 'o': {
                string name;
                cin >> name;
                Vertex* vertices = graph->vertices();
                Vertex v;
                for(int i=0;i<graph->numVertices();i++)
                    if(vertices[i].data==name) v=vertices[i];
                cout << "Out degree of " << v.data << ": " << graph->outDegree(v) << endl;
                break;
            }
            case 'i': {
                string name;
                cin >> name;
                Vertex* vertices = graph->vertices();
                Vertex v;
                for(int i=0;i<graph->numVertices();i++)
                    if(vertices[i].data==name) v=vertices[i];
                cout << "In degree of " << v.data << ": " << graph->inDegree(v) << endl;
                break;
            }
            case 'O': {
                string name;
                cin >> name;
                Vertex* vertices = graph->vertices();
                Vertex v;
                for(int i=0;i<graph->numVertices();i++)
                    if(vertices[i].data==name) v=vertices[i];
                int deg = graph->outDegree(v);
                Edge* edges = graph->outgoingEdges(v);
                cout << "(";
                for(int i=0;i<deg;i++){
                    cout << edges[i].data;
                    if(i != deg-1) cout << ", ";
                }
                cout << ")" << endl;
                delete[] edges;
                break;
            }
            case 'I': {
                string name;
                cin >> name;
                Vertex* vertices = graph->vertices();
                Vertex v;
                for(int i=0;i<graph->numVertices();i++)
                    if(vertices[i].data==name) v=vertices[i];
                int deg = graph->inDegree(v);
                Edge* edges = graph->incomingEdges(v);
                cout << "(";
                for(int i=0;i<deg;i++){
                    cout << edges[i].data;
                    if(i != deg-1) cout << ", ";
                }
                cout << ")" << endl;
                delete[] edges;
                break;
            }
            case 'r': {
                char label;
                cin >> label;
                Edge e{label};
                graph->removeEdge(e);
                cout << "Removed edge " << label << endl;
                break;
            }
            case 'd': {
                string name;
                cin >> name;
                Vertex* vertices = graph->vertices();
                Vertex v;
                for(int i=0;i<graph->numVertices();i++)
                    if(vertices[i].data==name) v=vertices[i];
                graph->removeVertex(v);
                cout << "Removed vertex " << name << endl;
                break;
            }
            case 'x':
                cout << "Exiting" << endl;
                break;
            default:
                cout << "Invalid operation" << endl;
                break;
        }
    } while(op != 'x');

    delete graph;
    return 0;
}