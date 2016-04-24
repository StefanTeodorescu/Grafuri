#include <iostream>
#include "Graph.h"
#include "BinaryTree.h"

using namespace std;

int main() {
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

    vector<int> V = B.inOrder();
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