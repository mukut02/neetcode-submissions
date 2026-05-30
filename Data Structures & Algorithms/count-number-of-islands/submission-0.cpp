class Solution {
public:
    int n,m;
    vector<int> dx, dy;
    void bfs(int i,int j,vector<vector<char>>& grid, vector<vector<bool>> &vis){
        dx ={-1, 0, 1, 0};
        dy = {0, 1, 0, -1};
        queue<pair<int,int>> q;
        q.push({i, j});
        vis[i][j]=true;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int t=0;t<4;++t){
                int nx = x + dx[t];
                int ny = y + dy[t];

                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]=='1' && !vis[nx][ny]){
                    q.push({nx, ny});
                    vis[nx][ny]=true;
                }
            }
        }
        

    }
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int ans=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(!vis[i][j] && grid[i][j]=='1'){
                    bfs(i, j, grid, vis);
                    cout << i << ' ' << j << '\n';
                    ans++;
                }
            }
        }
        return ans;
    }
};
