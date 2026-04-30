#include <bits/stdc++.h>
#include <chrono>
#include <thread>
using namespace std;

#define INF INT_MAX

class Graph {
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        if (u >= V || v >= V) {
            cout << "Invalid nodes!\n";
            return;
        }
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        cout << "Edge added successfully!\n";
    }

    void showGraph() {
        cout << "\n--- Network Graph ---\n";
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << " -> ";
            for (auto &edge : adj[i]) {
                cout << "(" << edge.first << ", w=" << edge.second << ") ";
            }
            cout << endl;
        }
    }

    void printPath(vector<int>& parent, int j) {
        if (j == -1) return;
        printPath(parent, parent[j]);
        cout << j << " ";
    }

    void dijkstra(int src) {
        vector<int> dist(V, INF);
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);

        dist[src] = 0;

        cout << "\n🚀 Starting Packet Routing Simulation...\n";

        for (int i = 0; i < V - 1; i++) {
            int u = -1;

            for (int j = 0; j < V; j++) {
                if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                    u = j;
                }
            }

            visited[u] = true;

            cout << "\n📍 Visiting Node: " << u << endl;
            this_thread::sleep_for(chrono::milliseconds(800));

            for (auto &it : adj[u]) {
                int v = it.first;
                int weight = it.second;

                if (!visited[v] && dist[u] != INF &&
                    dist[u] + weight < dist[v]) {

                    dist[v] = dist[u] + weight;
                    parent[v] = u;

                    cout << "   🔄 Updating Node " << v
                         << " → New Distance: " << dist[v] << endl;

                    this_thread::sleep_for(chrono::milliseconds(500));
                }
            }
        }

        cout << "\n✅ Final Shortest Distances:\n";
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << " → " << dist[i] << endl;
        }

        cout << "\n📡 Packet Routes from Source:\n";
        for (int i = 0; i < V; i++) {
            cout << "To Node " << i << ": ";
            printPath(parent, i);
            cout << "(Cost: " << dist[i] << ")\n";
        }
    }
};

int main() {
    int V;
    cout << "Enter number of nodes: ";
    cin >> V;

    Graph g(V);

    int choice;

    while (true) {
        cout << "\n====== Network Packet Router ======\n";
        cout << "1. Add Edge\n";
        cout << "2. Show Graph\n";
        cout << "3. Run Dijkstra (Route Packets)\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int u, v, w;
            cout << "Enter (u v weight): ";
            cin >> u >> v >> w;
            g.addEdge(u, v, w);
        }
        else if (choice == 2) {
            g.showGraph();
        }
        else if (choice == 3) {
            int src;
            cout << "Enter source node: ";
            cin >> src;
            g.dijkstra(src);
        }
        else if (choice == 4) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}