class Solution {
public:
vector<int> dx,dy;
int n,m;
int bfs(int i,int j,vector<vector<int>>& grid, vector<vector<bool>> &vis){
    queue<pair<int,int>> q;
    q.push({i, j});
    vis[i][j]=1;
    int cnt=1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int t=0;t<4;++t){
            int nx = x + dx[t];
            int ny = y + dy[t];

            if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]==1){
                q.push({nx, ny});
                vis[nx][ny]=1;
                cnt++;
            }
        }
    }
    return cnt;
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        dx = {-1, 0, 1, 0};
        dy = {0, 1, 0, -1};
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int ans=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(!vis[i][j] && grid[i][j]==1){
                    ans=max(ans, bfs(i,j,grid,vis));
                }
            }
        }

        return ans;
    }
};
