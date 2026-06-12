class Solution {
public:
typedef pair<int, pair<int,int>> P;
typedef pair<int,int> p;
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        dist[0][0]=grid[0][0];
        pq.push({grid[0][0], {0,0}});
        while(!pq.empty()){
            auto info = pq.top();
            pq.pop();

            int val = info.first;
            int x = info.second.first;
            int y = info.second.second;

            if(x==n-1 && y==n-1) return val;
            if(dist[x][y]!=val) continue;

            for(int t=0;t<4;++t){
                int nx = x + dx[t];
                int ny = y + dy[t];

                if(nx>=0 && nx<n && ny>=0 && ny<n){
                    int wt = max(grid[nx][ny], val);
                    if(wt < dist[nx][ny]){
                        dist[nx][ny] = wt;
                        pq.push({wt, {nx, ny}});
                    }
                }
            }
        }
        return -1;
    }
};
