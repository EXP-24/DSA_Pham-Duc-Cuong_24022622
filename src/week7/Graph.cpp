#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct Graph {
    vector<vector<int>> adj;
    int V;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int v, int u) {
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << i << ":";
            for(int x : adj[i]) {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS: ";

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            cout << u << " ";

            sort(adj[u].begin(), adj[u].end());
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        stack<int> s;

        s.push(start);

        cout << "DFS: ";

        while(!s.empty()) {
            int u = s.top();
            s.pop();

            if (!visited[u]) {
                visited[u] = true;
                cout << u << " ";

                sort(adj[u].begin(), adj[u].end());
                for (int i = adj[u].size() - 1; i >= 0; --i) {
                    int v = adj[u][i];
                    if (!visited[v]) {
                        s.push(v);
                    }
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.printGraph();

    g.BFS(0);
    g.DFS(0);
}
