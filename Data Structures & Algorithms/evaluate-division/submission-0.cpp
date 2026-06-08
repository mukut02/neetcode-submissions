class Solution {
public:
typedef pair<string, double> P;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size();
        map<string, vector<P>> adj;

        for(int i=0;i<n;++i){
            string x = equations[i][0];
            string y = equations[i][1];
            adj[x].push_back({y, values[i]});
            adj[y].push_back({x, 1.0/values[i]});
        }
        vector<double> ans;
        for(auto &query : queries){
            string start=query[0];
            string end =  query[1];
            queue<P> q;
            map<string,bool> vis;
            if(!adj[start].empty()){
                vis[start]=1;
                q.push({start, 1.0});
            }
            
            while(!q.empty()){
                auto node = q.front().first;
                auto val = q.front().second;
                q.pop();

                if(node==end){
                    ans.push_back(val);
                    break;
                }
                for(auto &info : adj[node]){
                    if(!vis[info.first]){
                        q.push({info.first, val*info.second});
                        vis[info.first]=true;
                    }
                }
            }
            if(!vis[end]) ans.push_back(-1.0);
        }
        return ans;
    }
};