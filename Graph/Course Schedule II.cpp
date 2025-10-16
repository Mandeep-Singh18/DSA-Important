✅ Short Approach
      Use Kahn’s Algorithm (Topological Sort) — build graph, track indegrees, and process nodes with 0 indegree to get course order.
      🕒 Time: O(V + E)
      💾 Space: O(V + E)
        
💻 Code (with short comments)

vector<int> findOrder(int num, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(num);   // adjacency list
    vector<int> indegree(num, 0);     // track indegrees

    for(auto &p : prerequisites){
        graph[p[1]].push_back(p[0]);  // build graph
        indegree[p[0]]++;             // increase indegree
    }

    queue<int> q;
    for(int i=0; i<num; i++)
        if(indegree[i]==0) q.push(i); // push nodes with 0 indegree

    vector<int> ans;
    int visited = 0;

    while(!q.empty()){
        int u = q.front(); q.pop();
        ans.push_back(u); visited++;   // add to order
        for(int v : graph[u]){
            indegree[v]--;             // decrease indegree
            if(indegree[v]==0) q.push(v);
        }
    }

    return (visited==num) ? ans : vector<int>(); // return if all visited
}
