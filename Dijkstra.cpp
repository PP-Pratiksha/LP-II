#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <string>
#include <utility>
#include <sstream>

using namespace std;

class DijkstraPriorityQueue {
public:
    vector<string> vertex;

    vector<int> dijkstra(int V, vector<vector<pair<int, int>>>& adj, int S) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, INT_MAX);

        pq.push({0, S});
        dist[S] = 0;

        while (!pq.empty()) {
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (const auto& curr : adj[node]) {
                int edgeWeight = curr.second;
                int adjNode = curr.first;

                int newDist = edgeWeight + distance;

                if (dist[adjNode] > newDist) {
                    pq.push({newDist, adjNode});
                    dist[adjNode] = newDist;
                }
            }
        }

        string start = vertex[S];
        for (int i = 0; i < V; i++) {
            cout << start << "->" << vertex[i] << " = " << dist[i] << endl;
        }

        return dist;
    }

    vector<vector<pair<int, int>>> adjList(int n, int m) {
        vector<vector<pair<int, int>>> adj(n);
        cout << "Enter all the cities" << endl;
        for (int i = 0; i < n; i++) {
            string city;
            cin >> city;
            vertex.push_back(city);
        }

        cout << "Enter edges and weight: " << endl;
        for (int i = 0; i < m; i++) {
            string start, end;
            int w;
            cin >> start >> end >> w;

            int u = find(vertex.begin(), vertex.end(), start) - vertex.begin();
            int v = find(vertex.begin(), vertex.end(), end) - vertex.begin();

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        return adj;
    }
};

int main() {
    DijkstraPriorityQueue dj;
    int V, E;
    cout << "Enter the number of cities: ";
    cin >> V;
    cout << "Enter the number of connections between cities: ";
    cin >> E;
    vector<vector<pair<int, int>>> adj = dj.adjList(V, E);
    
    // Take source city from the user
    string sourceCity;
    cout << "Enter the name of the source city: ";
    cin >> sourceCity;
    
    // Find the index of the source city
    auto it = find(dj.vertex.begin(), dj.vertex.end(), sourceCity);
    if (it == dj.vertex.end()) {
        cout << "Source city not found. Exiting..." << endl;
        return 1; // Exit with error code
    }
    int sourceIndex = distance(dj.vertex.begin(), it);

    dj.dijkstra(V, adj, sourceIndex);
    return 0;
}
