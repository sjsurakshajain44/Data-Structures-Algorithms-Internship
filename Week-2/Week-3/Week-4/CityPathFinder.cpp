#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<string> cities = {
        "Delhi",
        "Meerut",
        "Muzaffarnagar",
        "Haridwar",
        "Dehradun"
    };

    int n = cities.size();

    vector<vector<pair<int, int>>> graph(n);

    graph[0].push_back({1, 70});
    graph[1].push_back({0, 70});

    graph[1].push_back({2, 60});
    graph[2].push_back({1, 60});

    graph[2].push_back({3, 90});
    graph[3].push_back({2, 90});

    graph[3].push_back({4, 55});
    graph[4].push_back({3, 55});

    graph[1].push_back({4, 180});
    graph[4].push_back({1, 180});

    int source = 0;
    int destination = 4;

    vector<int> distance(n, INT_MAX);
    vector<int> parent(n, -1);

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
                parent[neighbor] = node;

                pq.push({
                    distance[neighbor],
                    neighbor
                });
            }
        }
    }

    vector<int> path;

    for (int current = destination;
         current != -1;
         current = parent[current]) {

        path.push_back(current);
    }

    reverse(path.begin(), path.end());

    cout << "Shortest Route: ";

    for (int city : path)
        cout << cities[city] << " ";

    cout << "\nTotal Distance: "
         << distance[destination]
         << " km";

    return 0;
}
