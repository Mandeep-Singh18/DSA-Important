🧠 Short Aproach
    Map emails to account indices.
    Use Disjoint Set (Union by Size) to merge accounts sharing emails.
    Group emails by parent account, sort them, and prepend the account name.

⏱️ Time & Space Complexity
    Time: O(A × E × log E) → A = #accounts, E = #emails per account (sorting emails).
    Space: O(A ×E) → disjoint set + email mapping + result.

💡 In short:
    Union accounts by shared emails → group emails by parent → sort → add names → merged accounts.

💻 Code (With Short Comments)
  
class Disjoint {
    vector<int> size, parent;

public:
    Disjoint(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i; // init parent
    }

    int findultparent(int node){
        if(parent[node]==node) return node;
        return parent[node] = findultparent(parent[node]); // path compression
    }

    void unionbysize(int u, int v){
        int ult_u = findultparent(u), ult_v = findultparent(v);
        if(ult_u==ult_v) return;
        if(size[ult_u]<size[ult_v]){
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        } else {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts){
        unordered_map<string,int> mp;  // map email -> account index
        int n = accounts.size();
        Disjoint ds(n);

        // union accounts sharing emails
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mp.find(mail)==mp.end()) mp[mail]=i;
                else ds.unionbysize(i, mp[mail]);
            }
        }

        vector<string> maillist[n];
        for(auto it : mp){
            string mail = it.first;
            int node = ds.findultparent(it.second);
            maillist[node].push_back(mail);  // group emails by parent
        }

        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(maillist[i].empty()) continue;
            sort(maillist[i].begin(), maillist[i].end());
            vector<string> temp = {accounts[i][0]}; // add name
            temp.insert(temp.end(), maillist[i].begin(), maillist[i].end());
            ans.push_back(temp);
        }

        return ans;
    }
};
