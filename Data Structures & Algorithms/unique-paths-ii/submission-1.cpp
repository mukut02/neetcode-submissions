#include<cstring>
class Solution {
public:
int dp[105][105];
int m,n;
int f(int i,int j,vector<vector<int>> &v){
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==m-1 && j==n-1){
        return 1;
    }
    int ans=0;
    if(i+1<m && v[i+1][j]==0){
        ans=f(i+1,j,v);
    }
    if(j+1<n && v[i][j+1]==0){
        ans+=f(i,j+1,v);
    }
    return dp[i][j]=ans;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m=obstacleGrid.size();
        n=obstacleGrid[0].size();
        memset(dp, -1, sizeof(dp));
        if(obstacleGrid[0][0]==1) return 0;
        return f(0,0,obstacleGrid);
    }
};