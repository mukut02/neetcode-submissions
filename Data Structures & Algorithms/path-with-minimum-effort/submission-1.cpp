class Solution {
public:
typedef pair<int, pair<int,int>> P;
typedef pair<int,int> p;
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<P, vector<P>, greater<P>> pq;
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        vector<int> dx = { -1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        pq.push({0, {0,0,}});
        dist[0][0]=0;
        while(!pq.empty()){
            auto info = pq.top();
            int val = info.first;
            int x = info.second.first;
            int y = info.second.second;
            pq.pop();

            if(dist[x][y]!=val) continue;

            if(x==n-1 && y==m-1) return val;

            for(int t=0;t<4;++t){
                int nx = x + dx[t];
                int ny = y + dy[t];
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    int wt = max(val, abs(heights[nx][ny] - heights[x][y]) );

                    if(dist[nx][ny] > wt){
                        pq.push({wt, {nx, ny}});
                        dist[nx][ny] = wt;
                    }
                }
            }
        }
        return -1;
    }
};