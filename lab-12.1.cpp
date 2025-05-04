#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class Graph {
private:
    int VertexCount;
    vector<list<int>> AdjacencyList;

public:
    // Constructor
    Graph(int Size) {
        VertexCount = Size;
        AdjacencyList.resize(Size);
    }

    // Insert an edge
    void InsertEdge(int Source, int Destination) {
        if (IsValidVertex(Source) && IsValidVertex(Destination)) {
            if (find(AdjacencyList[Source].begin(), AdjacencyList[Source].end(), Destination) == AdjacencyList[Source].end()) {
                AdjacencyList[Source].push_back(Destination);
                AdjacencyList[Destination].push_back(Source); // For undirected graph
                cout << "Edge inserted between " << Source << " and " << Destination << ".\n";
            } else {
                cout << "Edge already exists.\n";
            }
        } else {
            cout << "Invalid vertex indices.\n";
        }
    }

    // Delete an edge
    void DeleteEdge(int Source, int Destination) {
        if (IsValidVertex(Source) && IsValidVertex(Destination)) {
            AdjacencyList[Source].remove(Destination);
            AdjacencyList[Destination].remove(Source);
            cout << "Edge deleted between " << Source << " and " << Destination << ".\n";
        } else {
            cout << "Invalid vertex indices.\n";
        }
    }

    // Search for an edge
    void SearchEdge(int Source, int Destination) {
        if (IsValidVertex(Source) && IsValidVertex(Destination)) {
            auto It = find(AdjacencyList[Source].begin(), AdjacencyList[Source].end(), Destination);
            if (It != AdjacencyList[Source].end()) {
                cout << "Edge exists between " << Source << " and " << Destination << ".\n";
            } else {
                cout << "No edge exists between " << Source << " and " << Destination << ".\n";
            }
        } else {
            cout << "Invalid vertex indices.\n";
        }
    }

    // Display graph
    void Display() {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < VertexCount; ++i) {
            cout << i << " -> ";
            for (int Neighbor : AdjacencyList[i]) {
                cout << Neighbor << " ";
            }
            cout << endl;
        }
    }

private:
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
