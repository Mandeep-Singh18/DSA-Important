🧠 Short Approach
    Model flights as a weighted directed graph.
    Use BFS with stops tracking to explore paths from src.
    Update distance only if cheaper and within k stops.
    Return cost to dst, or -1 if unreachable.

⏱️ Time &Space Complexity
    Time: O(E × K) → E edges, K max stops (each node may be visited multiple times).
    Space: O(N + E) → adjacency list + queue + distance array.

💡 In short:
    BFS over flights → track stops → update minimum cost → result = cost to destination within K stops.

💻 Code (With Short Comments)
  
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>> adj(n);       // adjacency list
    for(auto flight : flights)
        adj[flight[0]].push_back({flight[1], flight[2]}); // build graph

    vector<int> dist(n, 1e8);                   // min cost to node
    dist[src] = 0;
    queue<pair<int,pair<int,int>>> q;           // {stops, {node, cost}}
    q.push({0, {src, 0}});

    while(!q.empty()){
        auto it = q.front(); q.pop();
        int stop = it.first;
        int node = it.second.first;
        int cost = it.second.second;

        if(stop > k) continue;                  // exceed max stops
        for(auto flight : adj[node]){
            int adjN = flight.first;
            int adjCost = flight.second;

            if(cost + adjCost < dist[adjN] && stop <= k){
                dist[adjN] = cost + adjCost;    // update cheaper cost
                q.push({stop + 1, {adjN, cost + adjCost}});
            }
        }
    }

    return dist[dst] == 1e8 ? -1 : dist[dst];  // unreachable check
}
