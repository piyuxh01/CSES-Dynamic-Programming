#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& component) {
    visited[node] = true;
    component.push_back(node);

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, component);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    vector<vector<int>> components;

    for (int node = 1; node <= n; ++node) {
        if (!visited[node]) {
            vector<int> component;
            dfs(node, adj, visited, component);
            components.push_back(component);
        }
    }

    int numComponents = components.size();
    vector<pair<int, int>> newRoads;

    for (int i = 1; i < numComponents; ++i) {
        newRoads.push_back(make_pair(components[i - 1][0], components[i][0]));
    }

    cout << numComponents - 1 << endl;
    for (const auto& road : newRoads) {
        cout << road.first << " " << road.second << endl;
    }

    return 0;
}
