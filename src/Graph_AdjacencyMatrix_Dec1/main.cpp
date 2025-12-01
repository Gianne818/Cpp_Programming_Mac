#include <iostream>
#include "adjacencyMatrix.hpp"
using namespace std;

int main() {
    Graph* graph = new GraphMatrix();
    char op;
    do {
        cout << "Op: ";
        cin >> op;
        switch(op) {
            case 'v': {
                char name;
                cin >> name;
                try {
                    char u = graph->insertVertex(name);
                    cout << "Inserted vertex " << u << endl;
                } catch (const std::logic_error &ex) {
                    cout << "Error: " << ex.what() << endl;
                }
                break;
            }
            case 'e': {
                char uName, vName;
                int label;
                cin >> uName >> vName >> label;
                try {
                    int edge = graph->insertEdge(uName, vName, label);
                    if (edge == -1) cout << "Failed to insert edge (missing vertex)" << endl;
                    else cout << "Inserted edge " << edge << " from " << uName << " to " << vName << endl;
                } catch (const logic_error &ex) {
                    cout << "Error: " << ex.what() << endl;
                }
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
                graph->print();
                break;
            }
            case 'q': {
                int m = graph->numEdges();
                int* allEdges = graph->edges();
                cout << "(";
                for(int i=0;i<m;i++){
                    cout << allEdges[i];
                    if(i != m-1) cout << ", ";
                }
                cout << ")" << endl;
                delete[] allEdges;
                break;
            }
            case 'g': {
                char uName, vName;
                cin >> uName >> vName;
                int e = graph->getEdge(uName, vName);
                if (e == -1) cout << "No edge between " << uName << " and " << vName << endl;
                else cout << "Edge between " << uName << " and " << vName << ": " << e << endl;
                break;
            }
            case 'f': {
                int label;
                cin >> label;
                char* ends = graph->endVertices(label);
                if(ends){
                    cout << "Edge " << label << " connects (" << ends[0] << ", " << ends[1] << ")" << endl;
                    delete[] ends;
                } else cout << "Edge not found" << endl;
                break;
            }
            case 't': {
                char vName;
                int label;
                cin >> vName >> label;
                char opp = graph->getOpposite(vName, label);
                if (opp == '\0') cout << "No opposite found" << endl;
                else cout << "Opposite of " << vName << " on edge " << label << ": " << opp << endl;
                break;
            }
            case 'o': {
                char name;
                cin >> name;
                cout << "Out degree of " << name << ": " << graph->outDegree(name) << endl;
                break;
            }
            case 'i': {
                char name;
                cin >> name;
                cout << "In degree of " << name << ": " << graph->inDegree(name) << endl;
                break;
            }
            case 'O': {
                char name;
                cin >> name;
                int deg = graph->outDegree(name);
                int* edges = graph->outgoingEdges(name);
                cout << "(";
                for(int i=0;i<deg;i++){
                    cout << edges[i];
                    if(i != deg-1) cout << ", ";
                }
                cout << ")" << endl;
                delete[] edges;
                break;
            }
            case 'I': {
                char name;
                cin >> name;
                int deg = graph->inDegree(name);
                int* edges = graph->incomingEdges(name);
                cout << "(";
                for(int i=0;i<deg;i++){
                    cout << edges[i];
                    if(i != deg-1) cout << ", ";
                }
                cout << ")" << endl;
                delete[] edges;
                break;
            }
            case 'r': {
                int label;
                cin >> label;
                graph->removeEdge(label);
                cout << "Removed edge " << label << endl;
                break;
            }
            case 'd': {
                char name;
                cin >> name;
                graph->removeVertex(name);
                cout << "Removed vertex " << name << endl;
                break;
            }
            case 'P': {
                graph->print();
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

    // delete via derived pointer to avoid undefined behavior (Graph has no virtual destructor)
    GraphMatrix* gm = static_cast<GraphMatrix*>(graph);
    delete gm;
    return 0;
}