class Solution {
public:
vector<vector<int>> dp;
int f(int i,int t,vector<int> &v){
    if(dp[i][t]!=-105) return -1;
    if(i==v.size()) return 0;
    int ans=f(i+1,t,v);
    if(t==2) return ans;
    if(t==0) ans=max(ans, f(i+1,1,v) - v[i]);
    if(t==1) ans=max(ans, f(i+1,2,v) + v[i]);
    return ans;
}
    int maxProfit(vector<int>& prices) {
        dp.resize(105, vector<int>(3, -105));
        return f(0,0,prices);
    }
};
