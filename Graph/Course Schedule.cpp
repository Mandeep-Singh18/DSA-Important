✅ Short Approach
    Use Kahn’s Algorithm (Topological Sort) — if all courses can be sorted (i.e., no cycle), return true.
    
    🕒 Time: O(V + E)
    💾 Space: O(V + E)
    
💻 Code (with short comments)

bool canFinish(int n, vector<vector<int>>& prerequisites) {
    vector<int> adj[n], indegree(n, 0), ans; // adjacency & indegree

    for(auto &x: prerequisites){ 
        adj[x[0]].push_back(x[1]); // build graph
        indegree[x[1]]++;          // count indegree
    }

    queue<int> q;
    for(int i = 0; i < n; i++)
        if(indegree[i] == 0) q.push(i); // push nodes with 0 indegree

    while(!q.empty()){
        int t = q.front(); q.pop();
        ans.push_back(t);               // add to topo order
        for(int x: adj[t]){
            indegree[x]--;              // reduce indegree
            if(indegree[x] == 0) q.push(x); 
        }
    }

    return ans.size() == n; // if all visited => no cycle
}
