#include<cstring>
class Solution {
public:
int dp[102][2];
int f(int i,int is0th,vector<int>& nums){
    if(dp[i][is0th]!=-1) return dp[i][is0th];
    if(i>=nums.size()) return dp[i][is0th]=0;
    if(i==nums.size()-1){
        if(is0th) return dp[i][is0th]=0;
        return dp[i][is0th]=nums[i];
    }
    int nIs0th=is0th;
    int ans=f(i+1,nIs0th,nums);
    if(i==0) nIs0th=1;
    return dp[i][is0th]=max(ans, f(i+2,nIs0th,nums)+nums[i]);
}
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,nums);
    }
};
