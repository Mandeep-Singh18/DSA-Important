🧠 Short Approach
    Treat points as a complete graph with Manhattan distances as edge weights.
    Use Prim’s algorithm: start from any node, iteratively add the nearest unvisited node.
    Sum the distances to get minimum cost to connect all points.

⏱️ Time & Space Complexity
    Time: O(N²) → each iteration checks all unvisited nodes.
    Space: O(N) → distance array + visited array.

💡 In short:
    Prim’s MST using Manhattan distance → sum edges for minimum connection cost.

💻 Code (With Short Comments)
  
int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size(), node = 0;
    vector<int> dist(n, 1e8);   // min distance to MST
    vector<bool> visit(n, false);
    int edges = 0, res = 0;

    while(edges < n - 1){
        visit[node] = true;      // mark current node
        int nextNode = -1;

        for(int i = 0; i < n; i++){
            if(visit[i]) continue;
            int curDist = abs(points[i][0] - points[node][0]) +
                           abs(points[i][1] - points[node][1]); // Manhattan
            dist[i] = min(dist[i], curDist);  // update distance
            if(nextNode == -1 || dist[i] < dist[nextNode])
                nextNode = i;                 // pick nearest unvisited
        }

        res += dist[nextNode];    // add to total cost
        node = nextNode;
        edges++;
    }

    return res;
}
