🧠 Short Approach
    Model the network as a weighted directed graph.
    Use Dijkstra’s algorithm with a min-heap to find shortest paths from node k to all nodes.
    Return the maximum distance; if any node is unreachable → return -1.

⏱️ Time &Space Complexity
    Time: O(E log V) → E edges, V nodes, priority queue operations.
    Space: O(V + E) → adjacency list + distance array + priority queue.

💡 In short:
    Use Dijkstra from source → maximum shortest path = network delay.

💻 Code (With Short Comments)
  
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int,int>>> adj(n+1); // adjacency list

    for(auto &edge : times)
        adj[edge[0]].push_back({edge[1], edge[2]}); // build graph

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, k});                    // {distance, node}

    vector<int> dist(n+1, 1e9);         // initialize distances
    dist[k] = 0;

    while(!pq.empty()){
        auto [currDist, node] = pq.top(); pq.pop();
        if(currDist > dist[node]) continue;

        for(auto &[adjNode, weight] : adj[node]){
            if(currDist + weight < dist[adjNode]){
                dist[adjNode] = currDist + weight; // update shortest path
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    int maxDist = 0;
    for(int i = 1; i <= n; i++){
        if(dist[i] == 1e9) return -1;  // unreachable node
        maxDist = max(maxDist, dist[i]);
    }

    return maxDist;
}
