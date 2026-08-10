#include<cstring>
class Solution {
public:
int dp[30005][2];
int f(int i,int state,vector<int>&v){
    if(dp[i][state]!=-1) return dp[i][state];
    if(i==v.size()) return dp[i][state]=0;
    int ans = f(i+1, state, v);
    if(state==1) ans=max(ans, f(i+1,0,v)+v[i]);
    if(state==0) ans=max(ans, f(i+1,1,v)-v[i]);
    return dp[i][state]=ans;
}
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,prices);
    }
};