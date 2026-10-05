#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, cost;
};

bool compare(Edge a, Edge b) {
    return a.cost < b.cost;
}

int parent[100];

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    parent[a] = b;
}

int main() {
    int n, e;

    cout << "Enter number of locations: ";
    cin >> n;

    cout << "Enter number of pipelines: ";
    cin >> e;

    vector<Edge> edges(e);

    cout << "Enter source, destination and cost:\n";
    for (int i = 0; i < e; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].cost;
    }

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    sort(edges.begin(), edges.end(), compare);

    int totalCost = 0;

    cout << "\nSelected Pipelines:\n";

    for (Edge edge : edges) {
        if (find(edge.u) != find(edge.v)) {
            unite(edge.u, edge.v);

            cout << edge.u << " - "
                 << edge.v << " : "
                 << edge.cost << endl;

            totalCost += edge.cost;
        }
    }

    cout << "\nMinimum Total Cost = " << totalCost << endl;

    return 0;
}