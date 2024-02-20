#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int v, int w) {
    adj[v].push_back(w);
}

bool DLS(vector<int> adj[], int v, int target, int depth) {
    if (depth == 0 && v == target)
        return true;
    if (depth > 0) {
        for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
            if (DLS(adj, *i, target, depth - 1))
                return true;
    }
    return false;
}

bool IDS(vector<int> adj[], int src, int target, int max_depth) {
    for (int i = 0; i <= max_depth; i++)
        if (DLS(adj, src, target, i))
            return true;
    return false;
}

int main() {
    const int V = 7; // Total 7 vertices in the graph
    vector<int> adj[V];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 2, 6);

    int target = 6; // Target vertex to search
    int max_depth = 3; // Maximum depth to search
    int src = 0; // Source vertex

    if (IDS(adj, src, target, max_depth))
        cout << "Target is reachable within max depth.\n";
    else
        cout << "Target is not reachable within max depth.\n";

    return 0;
}
/*
Depth Limitation:
IDS introduces a depth parameter (depth) to control the depth of exploration.
BFS explores all nodes at a given depth level before moving to the next level, while IDS applies depth-first search with depth limitations.

Iterative Deepening Search (IDS):
IDS function iterates over increasing depth limits, calling DLS with each depth limit.
This iterative approach allows IDS to gradually explore deeper levels of the graph while maintaining space efficiency.

Main Function:
The main function calls IDS with the source vertex, target vertex, and maximum depth to initiate the search.
This approach ensures that the search terminates when the target is found within the specified maximum depth.
*/
// What is the difference between BFS and IDS?
// But, the difference is that ID successively processes the nodes at incremental depths, whereas BFS conducts the search level by level. Also,
// BFS visits each node once, whereas ID visits some nodes multiple times since it restarts DLDFS
