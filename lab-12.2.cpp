#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Graph {
private:
    int VertexCount;
    vector<vector<int>> AdjacencyMatrix;

public:
    // Constructor
    Graph(int size) {
        VertexCount = size;
        AdjacencyMatrix.resize(size, vector<int>(size, 0));
    }

    // Insert an edge from source to destination
    void InsertEdge(int Source, int Destination) {
        if (IsValidVertex(Source) && IsValidVertex(Destination)) {
            AdjacencyMatrix[Source][Destination] = 1;
            AdjacencyMatrix[Destination][Source] = 1; // For undirected graph
            cout << "Edge inserted between " << Source << " and " << Destination << ".\n";
        } else {
            cout << "Invalid vertex indices.\n";
        }
    }

    // Delete an edge
    void DeleteEdge(int Source, int Destination) {
        if (IsValidVertex(Source) && IsValidVertex(Destination)) {
            AdjacencyMatrix[Source][Destination] = 0;
            AdjacencyMatrix[Destination][Source] = 0;
            cout << "Edge deleted between " << Source << " and " << Destination << ".\n";
        } else {
            cout << "Invalid vertex indices.\n";
        }
    }

    // Search for an edge
    void SearchEdge(int Source, int Destination) {
        if (IsValidVertex(Source) && IsValidVertex(Destination)) {
            if (AdjacencyMatrix[Source][Destination] == 1) {
                cout << "Edge exists between " << Source << " and " << Destination << ".\n";
            } else {
                cout << "No edge exists between " << Source << " and " << Destination << ".\n";
            }
        } else {
            cout << "Invalid vertex indices.\n";
        }
    }

    // Display the adjacency matrix
    void Display() {
        cout << "\nAdjacency Matrix:\n";
        cout << setw(4) << " ";
        for (int i = 0; i < VertexCount; ++i)
            cout << setw(4) << i;
        cout << endl;

        for (int i = 0; i < VertexCount; ++i) {
            cout << setw(4) << i;
            for (int j = 0; j < VertexCount; ++j) {
                cout << setw(4) << AdjacencyMatrix[i][j];
            }
            cout << endl;
        }
    }

private:
    // Utility to check if a vertex is within bounds
    bool IsValidVertex(int Vertex) {
        return Vertex >= 0 && Vertex < VertexCount;
    }
};

// Main menu
int main() {
    int Size, Choice, Src, Dest;
    cout << "Enter number of vertices: ";
    cin >> Size;

    Graph G(Size);

    do {
        cout << "\n----- Graph Menu -----\n";
        cout << "1. Insert Edge\n";
        cout << "2. Delete Edge\n";
        cout << "3. Search Edge\n";
        cout << "4. Display Graph\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> Choice;

        switch (Choice) {
            case 1:
                cout << "Enter source and destination: ";
                cin >> Src >> Dest;
                G.InsertEdge(Src, Dest);
                break;
            case 2:
                cout << "Enter source and destination: ";
                cin >> Src >> Dest;
                G.DeleteEdge(Src, Dest);
                break;
            case 3:
                cout << "Enter source and destination: ";
                cin >> Src >> Dest;
                G.SearchEdge(Src, Dest);
                break;
            case 4:
                G.Display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (Choice != 5);

    return 0;
}
