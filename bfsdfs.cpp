#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include<algorithm>
using namespace std;

class Traversal {
public:
    vector<string> vertex;

    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& ans, int level) {
        visited[node] = 1;
        ans.push_back(node);
        cout << "Level of " << vertex[node] << ": " << level << endl;
        for (int neighbour : adj[node]) {
            if (visited[neighbour] == 0) {
                dfs(neighbour, adj, visited, ans, level + 1); 
            }
        }
    }

    vector<string> bfsOfGraph(vector<vector<int>>& adj, int V) {
        queue<int> q;
        vector<int> visited(V, 0);
        vector<int> level(V, 0);
        vector<int> ans;
        q.push(0);
        visited[0] = 1;
        level[0] = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            cout << "Level of " << vertex[node] << ": " << level[node] << endl;
            for (int neighbour : adj[node]) {
                if (visited[neighbour] == 0) {
                    q.push(neighbour);
                    visited[neighbour] = 1;
                    level[neighbour] = level[node] + 1;
                }
            }
        }
        vector<string> answer;
        for (int i = 0; i < ans.size(); i++) {
            answer.push_back(vertex[ans[i]]);
        }
        return answer;
    }

    vector<vector<int>> adjList(int N, int M) {
        vector<vector<int>> adj(N);
        cout << "Enter all the cities" << endl;
        for (int i = 0; i < N; i++) {
            string city;
            cin >> city;
            vertex.push_back(city);
        }
        cout << "Enter edges" << endl;
        for (int i = 0; i < M; i++) {
            string start, end;
            cin >> start >> end;
            int u = find(vertex.begin(), vertex.end(), start) - vertex.begin();
            int v = find(vertex.begin(), vertex.end(), end) - vertex.begin();
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
};

int main() {
    Traversal obj;
    int V, M;
    
    cout << "Enter the number of cities: ";
    cin >> V;
    cout << "Enter the number of connections between cities: ";
    cin >> M;
    
    vector<vector<int>> lst = obj.adjList(V, M);
    
    cout << "BFS:" << endl;
    vector<string> bfsResult = obj.bfsOfGraph(lst, V);
    for (const auto& city : bfsResult) {
        cout << city << " ";
    }
    cout << endl;
    
    cout << "DFS:" << endl;
    vector<int> visited(V, 0);
    vector<int> dfsResult;
    obj.dfs(0, lst, visited, dfsResult, 0);
    for (int node : dfsResult) {
        cout << obj.vertex[node] << " ";
    }
    cout << endl;

    return 0;
}
