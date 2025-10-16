🧠 Short Approach
    Treat the grid as a graph with edges between adjacent cells, weight = max of the two cells’ heights.
    Sort edges by weight and use Union-Find to connect cells.
    The first time start (0,0) and end (n-1,n-1) are connected → answer = current edge weight.

⏱️ Time & Space Complexity
    Time: O(N² log N) → sorting all edges.
    Space: O(N²) → parent array for Union-Find + edges list.

💡 In short:
    Kruskal’s MST style → union cells by increasing water level → first connection from start to end = minimum time.

💻 Code (With Short Comments)
  
int swimInWater(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<tuple<int,int,int>> edges;

    // Build edges between adjacent cells with weight = max(height)
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i > 0) edges.push_back({max(grid[i][j], grid[i-1][j]), i*n+j, (i-1)*n+j});
            if(j > 0) edges.push_back({max(grid[i][j], grid[i][j-1]), i*n+j, i*n+j-1});
        }
    }

    sort(edges.begin(), edges.end());         // sort edges by water level
    vector<int> parent(m*n);
    iota(parent.begin(), parent.end(), 0);   // init Union-Find

    function<int(int)> find = [&](int x){    // path compression
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    };

    auto unite = [&](int x, int y){          // union sets
        parent[find(x)] = find(y);
    };

    for(auto [cost, u, v] : edges){
        unite(u, v);                          // connect cells
        if(find(0) == find(m*n-1))            // start and end connected
            return cost;
    }
    return grid[0][0];
}
