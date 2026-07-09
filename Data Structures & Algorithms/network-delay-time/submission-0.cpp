class Solution {
public:
typedef pair<int,int> P;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<P>> adj(n+1);
        for(int i=0;i<times.size();++i){
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        pq.push({0, k});
        vector<int> dist(n+1, INT_MAX);
        dist[k]=0;
        int ans=0;
        while(!pq.empty()){
            int node = pq.top().second;
            int t = pq.top().first;
            pq.pop();
            if(dist[node]!=t) continue;

            for(auto info : adj[node]){
                int nxt = info.first;
                int w = info.second;
                if((w + t)<dist[nxt]){
                    dist[nxt]=w + t;
                    pq.push({dist[nxt], nxt});
                }
            }
        }
        for(int i=1;i<=n;++i) ans=max(ans, dist[i]);
        if(ans==INT_MAX) ans=-1;
        return ans;
    }
};