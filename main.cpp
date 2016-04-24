#include <iostream>
#include "Graph.h"
#include "BinaryTree.h"

using namespace std;

int main() {
    Graph<int> G;
    G.addEdge(1, 2);
    G.addEdge(2, 5);
    G.addEdge(1, 3);
    G.addEdge(4, 6);
    G.addEdge(2, 6);
    G.addEdge(5, 4);
    G.addEdge(3, 7);

    vector<int> V = G.DFS(1);
    for (auto it : V) {
        cout << it << " ";
    }
    cout << "\n";
    V = G.BFS(1);
    for (auto it : V) {
        cout << it << " ";
    }
    cout << "\n";

    BinaryTree<int> B;

    B.insert(1);
    B.insert(6);
    B.insert(3);
    B.insert(12);
    B.insert(213);
    B.insert(10);
    B.insert(1231);
    B.insert(2);
    cout << B.find(12) << " " << B.find(1) << " " << B.find(6) << " " << B.find(213) << "\n";

    V = B.inOrder();
    for (auto it : V) {
        cout << it << " ";
    }
    cout << "\n";

    BinaryTree<int> A(B);
    A.insert(5);

    vector<int> V2 = A.inOrder();
    for (auto it : V2) {
        cout << it << " ";
    }
    cout << "\n";

    return 0;
}