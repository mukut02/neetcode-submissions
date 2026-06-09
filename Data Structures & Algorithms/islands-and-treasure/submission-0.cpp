class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int INF = 2147483647;
        int n=grid.size();
        int m=grid[0].size();
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int,int>> q;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==0){
                    q.push({i, j});
                    vis[i][j]=1;
                }
            }
        }
        int d=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                cout << x << ' ' << y << '\n';
                for(int t=0;t<4;++t){
                    int nx = x + dx[t];
                    int ny = y + dy[t];

                    if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]==INF){
                       grid[nx][ny]=d;
                       vis[nx][ny]=1;
                       q.push({nx, ny});
                    }
                }
            }
            d++;
        }
    }
};
