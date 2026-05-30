class Solution {
public:
vector<vector<int>> adj;
void dfs(int node,vector<bool> &vis){
    vis[node]=1;

    for(int nxt : adj[node]){
        if(!vis[nxt])   dfs(nxt, vis);
    }
}
    int countComponents(int n, vector<vector<int>>& edges) {
        adj.resize(n);

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n, false);
        int ans=0;
        for(int i=0;i<n;++i){
            if(!vis[i]) {
                dfs(i, vis);
                ans++;
            }
        }
        return ans;
    }
};
