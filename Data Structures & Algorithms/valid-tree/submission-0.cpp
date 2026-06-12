class Solution {
public:
void dfs(int node,vector<vector<int>> &adj, vector<bool> &vis){
    vis[node]=true;

    for(int nxt : adj[node]){
        if(!vis[nxt]) dfs(nxt, adj, vis);
    }
}
    bool validTree(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        if(m!=n-1) return false;
        vector<bool> vis(n, false);
        vector<vector<int>> adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);            
        }
        int cc=0;
        for(int i=0;i<n;++i){
            if(!vis[i]) {
                dfs(i, adj, vis);
                cc++;
            }
            if(cc>1) return false;
        }
        return true;
    }
};
