#include<cstring>
class Solution {
public:
int m,n;
int dp[105][105];
int f(int i,int j){
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==m-1 && j==n-1) return dp[i][j]=1;
    if(i==m or j==n) return dp[i][j]=0;

    return dp[i][j]=f(i+1,j) + f(i,j+1);
}
    int uniquePaths(int m, int n) {
        this->m=m;
        this->n=n;
        memset(dp, -1, sizeof(dp));
        return f(0,0);
    }
};
