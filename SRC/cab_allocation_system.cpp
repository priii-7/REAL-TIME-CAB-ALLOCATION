#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX

class Graph{
public:
    int V; 
    vector<vector<pair<int, int>>> adj;

    Graph(int v){
        V=v;
        adj.resize(V);
    }

    void addEdge(int u,int v, int w){
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    int dijkstra(int source, int destination) {
        vector<int> dist(V, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        dist[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (node == destination)
                return d;

            for (auto &edge : adj[node]) {
                int next = edge.first;
                int weight = edge.second;

                if (dist[next] > d + weight) {
                    dist[next] = d + weight;
                    pq.push({dist[next], next});
                }
            }
        }
        return INF;
    }
};

struct Driver {
    int id;
    int location;
    bool available;
};

int main(){

    Graph city(20);

    int trafficMultiplier = 2;

    city.addEdge(0, 1, 4 * trafficMultiplier);
    city.addEdge(0, 2, 6);
    city.addEdge(1, 3, 5);
    city.addEdge(2, 3, 2);
    city.addEdge(2, 4, 3);
    city.addEdge(3, 5, 7 * trafficMultiplier);
    city.addEdge(4, 5, 4);
    city.addEdge(4, 6, 6);
    city.addEdge(5, 7, 3);
    city.addEdge(6, 7, 2);
    city.addEdge(6, 8, 5);
    city.addEdge(7, 9, 4);
    city.addEdge(8, 9, 6);
    city.addEdge(8, 10, 3);
    city.addEdge(9, 11, 5 * trafficMultiplier);
    city.addEdge(10, 11, 2);
    city.addEdge(10, 12, 6);
    city.addEdge(11, 13, 4);
    city.addEdge(12, 13, 3);
    city.addEdge(12, 14, 7);
    city.addEdge(13, 15, 5);
    city.addEdge(14, 15, 2);
    city.addEdge(14, 16, 6);
    city.addEdge(15, 17, 4);
    city.addEdge(16, 17, 3);
    city.addEdge(16, 18, 5);
    city.addEdge(17, 19, 6);
    city.addEdge(18, 19, 4);

    vector<Driver> drivers = {
        {1, 0, true},
        {2, 2, true},
        {3, 4, true},
        {4, 6, true},
        {5, 8, true},
        {6, 10, true},
        {7, 12, true},
        {8, 14, true},
        {9, 16, true},
        {10, 18, true}
    };

    vector<int> riderRequests = {11, 3, 15, 7};

    for (int riderLocation : riderRequests) {

        cout << "\nRider pickup location: Area " << riderLocation << endl;

        bool anyAvailable = false;
        for (auto &d : drivers) {
            if (d.available) {
                anyAvailable = true;
                break;
            }
        }

        if (!anyAvailable) {
            cout << "All drivers are busy. Please wait.\n";
            break;
        }

        int minDistance = INF;

        int chosenDriverIndex=-1;

        for (int i = 0; i < drivers.size(); i++) {
            if (drivers[i].available) {
                int dist = city.dijkstra(drivers[i].location, riderLocation);
                if (dist < minDistance) {
                    minDistance = dist;
                    chosenDriverIndex = i;
                }
            }
        }
        if (chosenDriverIndex != -1) {
            drivers[chosenDriverIndex].available = false; 
            cout << "Assigned Driver ID: " << drivers[chosenDriverIndex].id << endl;
            cout << "Estimated pickup distance: " << minDistance << " units\n";
        }
    }

    return 0;
}