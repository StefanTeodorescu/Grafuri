#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    Graph<int> G;

    G.addEdge(1, 2);
    G.addEdge(2, 3);
    G.addEdge(1, 5);
    G.addEdge(4, 3);
    G.addEdge(1, 3);
    G.addEdge(4, 5);
    G.addEdge(2, 4);

    vector<int> D, B;
    D = G.DFS(1);
    B = G.BFS(1);

    for (auto it : D) {
        cout << it << " ";
    }
    cout << "\n";
    for (auto it : B) {
        cout << it << " ";
    }
    cout << "\n";

    return 0;
}