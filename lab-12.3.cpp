#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();

class Graph {
private:
    int VertexCount;
    vector<vector<pair<int, int>>> AdjacencyList; // (destination, weight)

public:
    Graph(int Size) {
        VertexCount = Size;
        AdjacencyList.resize(Size);
    }

    void AddEdge(int Source, int Destination, int Weight, bool Undirected = true) {
        if (IsValidVertex(Source) && IsValidVertex(Destination)) {
            AdjacencyList[Source].emplace_back(Destination, Weight);
            if (Undirected)
                AdjacencyList[Destination].emplace_back(Source, Weight);
        } else {
            cout << "Invalid vertex indices.\n";
        }
    }

    void Display() {
        cout << "\nGraph (Adjacency List):\n";
        for (int i = 0; i < VertexCount; ++i) {
            cout << i << " -> ";
            for (auto [Dest, Wt] : AdjacencyList[i]) {
                cout << "(" << Dest << ", " << Wt << ") ";
            }
            cout << endl;
        }
    }

    void Dijkstra(int Start) {
        vector<int> Distance(VertexCount, INF);
        Distance[Start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> PQ;
        PQ.emplace(0, Start);

        while (!PQ.empty()) {
            auto [Dist, U] = PQ.top(); PQ.pop();

            for (auto [V, Weight] : AdjacencyList[U]) {
                if (Distance[U] + Weight < Distance[V]) {
                    Distance[V] = Distance[U] + Weight;
                    PQ.emplace(Distance[V], V);
                }
            }
        }

        cout << "\nDijkstra's Shortest Paths from vertex " << Start << ":\n";
        for (int i = 0; i < VertexCount; ++i) {
            cout << "To " << i << ": ";
            if (Distance[i] == INF)
                cout << "INF\n";
            else
                cout << Distance[i] << endl;
        }
    }

    void Prims() {
        vector<int> Key(VertexCount, INF);
        vector<bool> InMST(VertexCount, false);
        vector<int> Parent(VertexCount, -1);
        Key[0] = 0;

        for (int count = 0; count < VertexCount - 1; ++count) {
            int U = -1;
            for (int v = 0; v < VertexCount; ++v)
                if (!InMST[v] && (U == -1 || Key[v] < Key[U]))
                    U = v;

            InMST[U] = true;
            for (auto [V, Weight] : AdjacencyList[U]) {
                if (!InMST[V] && Weight < Key[V]) {
                    Key[V] = Weight;
                    Parent[V] = U;
                }
            }
        }

        cout << "\nPrim's MST:\n";
        for (int i = 1; i < VertexCount; ++i) {
            cout << Parent[i] << " - " << i << endl;
        }
    }

    void Kruskals() {
        vector<tuple<int, int, int>> Edges;
        for (int U = 0; U < VertexCount; ++U) {
            for (auto [V, W] : AdjacencyList[U]) {
                if (U < V) Edges.emplace_back(W, U, V);
            }
        }

        sort(Edges.begin(), Edges.end());

        vector<int> Parent(VertexCount);
        for (int i = 0; i < VertexCount; ++i) Parent[i] = i;

        function<int(int)> Find = [&](int x) {
            return (Parent[x] == x) ? x : Parent[x] = Find(Parent[x]);
        };

        cout << "\nKruskal's MST:\n";
        for (auto [W, U, V] : Edges) {
            int RootU = Find(U), RootV = Find(V);
            if (RootU != RootV) {
                cout << U << " - " << V << " (" << W << ")\n";
                Parent[RootU] = RootV;
            }
        }
    }

private:
    bool IsValidVertex(int V) {
        return V >= 0 && V < VertexCount;
    }
};

int main() {
    int Size, Choice, Src, Dest, Weight;
    cout << "Enter number of vertices: ";
    cin >> Size;

    Graph G(Size);

    do {
        cout << "\n----- Graph Algorithm Menu -----\n";
        cout << "1. Add Edge\n";
        cout << "2. Display Graph\n";
        cout << "3. Dijkstra's Algorithm\n";
        cout << "4. Prim's Algorithm\n";
        cout << "5. Kruskal's Algorithm\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> Choice;

        switch (Choice) {
            case 1:
                cout << "Enter source, destination, and weight: ";
                cin >> Src >> Dest >> Weight;
                G.AddEdge(Src, Dest, Weight);
                break;
            case 2:
                G.Display();
                break;
            case 3:
                cout << "Enter source vertex: ";
                cin >> Src;
                G.Dijkstra(Src);
                break;
            case 4:
                G.Prims();
                break;
            case 5:
                G.Kruskals();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (Choice != 6);

    return 0;
}
