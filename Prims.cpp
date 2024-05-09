#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <climits>
using namespace std;
struct Edge {
    string dest;
    int weight;
    Edge(string dest, int weight) : dest(dest), weight(weight) {}
};
class MinimumSpanningTree {
public:
    int solve(map<string, vector<Edge>>& graph) {
        map<string, string> parent;
        map<string, int> key;
        set<string> visited;
        for (const auto& vertex : graph) {
            key[vertex.first] = INT_MAX;
        }
        key[graph.begin()->first] = 0;
        parent[graph.begin()->first] = "";
        int minDistance = 0;
        for (int count = 0; count < graph.size() - 1; count++) {
            string u = findMinKey(key, visited);
            visited.insert(u);
            for (const auto& edge : graph[u]) {
                string v = edge.dest;
                int weight = edge.weight;
                if (!visited.count(v) && weight < key[v]) {
                    parent[v] = u;
                    key[v] = weight;
                }
            }
        }
        cout << "Edges of Minimum Spanning Tree:" << endl;
        for (const auto& entry : parent) {
            string vertex = entry.first;
            string parentVertex = entry.second;
            if (!parentVertex.empty()) {
                for (const auto& edge : graph[vertex]) {
                    if (edge.dest == parentVertex) {
                        cout << parentVertex << " - " << vertex << " --> " << edge.weight << endl;
                        minDistance += edge.weight;
                    }
                }
            }
        }       
        return minDistance;
    }
private:
    string findMinKey(map<string, int>& key, set<string>& visited) {
        int min = INT_MAX;
        string minVertex;
        for (const auto& entry : key) {
            string vertex = entry.first;
            int keyValue = entry.second;
            if (!visited.count(vertex) && keyValue < min) {
                min = keyValue;
                minVertex = vertex;
            }
        }
        return minVertex;
    }
};
int main() {
    MinimumSpanningTree mst;
    map<string, vector<Edge>> graph;
    cout << "Enter the number of edges: ";
    int numEdges;
    cin >> numEdges;
    cout << "Enter edges in the format 'src dest weight':" << endl;
    for (int i = 0; i < numEdges; i++) {
        string src, dest;
        int weight;
        cin >> src >> dest >> weight;        
        graph[src].push_back(Edge(dest, weight));
        graph[dest].push_back(Edge(src, weight));
    }
    int minDistance = mst.solve(graph);
    cout << "Minimum Distance: " << minDistance << endl;
    return 0;
}

