class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        for(auto &e : prerequisites){
            indegree[e[0]]++;
            adj[e[1]].push_back(e[0]);
        }

        queue<int> q;
        vector<bool> vis(numCourses, false);
        for(int i=0;i<numCourses;++i){
            if(indegree[i]==0) {
                q.push(i);
                vis[i]=true;
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int nxt : adj[node]){
                indegree[nxt]--;
                if(indegree[nxt]==0) {
                    q.push(nxt);
                    vis[nxt]=true;
                }
            }
        }

        for(int i=0;i<numCourses;++i){
            if(vis[i]==false) return false;
        }

        return true;
        
    }
};
