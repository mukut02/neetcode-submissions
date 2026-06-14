class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        for(auto &e : prerequisites){
            indegree[e[0]]++;
            adj[e[1]].push_back(e[0]);
        }
        vector<int> ans={};
        queue<int> q;
        for(int i=0;i<numCourses;++i){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();q.pop();
            ans.push_back(node);
            for(int nxt : adj[node]){
                indegree[nxt]--;
                if(indegree[nxt]==0) q.push(nxt);
            }
        }
        if(ans.size()!=numCourses) return {};
        return ans;
    }
};
