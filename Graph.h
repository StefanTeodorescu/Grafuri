//
// Created by Stefan Teodorescu on 24/04/16.
//

#ifndef GRAFURI_GRAPH_H
#define GRAFURI_GRAPH_H

#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

template <typename T>
class Graph {
private:
    unordered_map<T, vector<T>> G;
    vector<T> Depth;
    vector<T> Breadth;
    unordered_set<T> Visited;

    void _DFS(const T& node) {
        Visited.insert(node);
        Depth.push_back(node);

        for (auto it : G[node]) {
            if (!Visited.count(it)) {
                _DFS(it);
            }
        }
    }

    void _BFS(const T& node) {
        queue<T> Q;

        Q.push(node);
        Visited.insert(node);
        T now;

        while (!Q.empty()) {
            now = Q.front();
            Q.pop();

            Breadth.push_back(now);

            for (auto it : G[now]) {
                if (!Visited.count(it)) {
                    Q.push(it);
                    Visited.insert(it);
                }
            }
        }
    }

public:
    Graph() {};
    Graph(const Graph& other) : G(other.G) {};

    void addEdge(const T& A, const T& B) {
        G[A].push_back(B);
    }

    void removeEdge(const T& A, const T& B) {
        typename vector<T> :: iterator it;
        it = find(G[A].begin(), G[A].end(), B);
        G[A].remove(it);
    }

    vector<T> DFS(const T& source) {
        Depth.clear();
        Visited.clear();
        _DFS(source);

        return Depth;
    }

    vector<T> BFS(const T& source) {
        Breadth.clear();
        Visited.clear();
        _BFS(source);

        return Breadth;
    }
};

#endif //GRAFURI_GRAPH_H
