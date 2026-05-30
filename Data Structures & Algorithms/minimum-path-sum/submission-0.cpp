#include<cstring>
class Solution {
public:
int m,n;
int dp[205][205];
int f(int i,int j, vector<vector<int>> &grid){
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==m-1 && j==n-1) return dp[i][j]=grid[i][j];
    if(i==m or j==n) return 1e8;
    return dp[i][j]=min(f(i+1,j,grid),f(i,j+1,grid)) + grid[i][j];
}
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return f(0,0,grid);
    }
};