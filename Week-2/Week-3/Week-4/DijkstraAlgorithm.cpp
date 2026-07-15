#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void dijkstra(int source, vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();
    vector<int> distance(n, INT_MAX);

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist > distance[node])
            continue;

        for (auto edge : graph[node]) {
            int neighbor = edge.first;
            int weight = edge.second;

            if (distance[node] + weight < distance[neighbor]) {
                distance[neighbor] = distance[node] + weight;
                pq.push({distance[neighbor], neighbor});
            }
        }
    }

    cout << "Shortest distances:\n";

    for (int i = 0; i < n; i++)
        cout << source << " -> " << i << " = " << distance[i] << endl;
}

int main() {
    vector<vector<pair<int, int>>> graph(5);

    graph[0].push_back({1, 4});
    graph[0].push_back({2, 1});
    graph[2].push_back({1, 2});
    graph[1].push_back({3, 1});
    graph[2].push_back({3, 5});
    graph[3].push_back({4, 3});

    dijkstra(0, graph);

    return 0;
}
