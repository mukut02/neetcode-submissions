class Solution {
public:
vector<int> dp;
int f(int i,vector<int> &v){
    if(dp[i]!=-1) return dp[i];
    if(i>=v.size()) return dp[i]=0;
    return dp[i]=max(f(i+1,v), f(i+2,v)+v[i]);
}
    int rob(vector<int>& nums) {
        dp.resize(nums.size()+2, -1);
        return f(0,nums);
    }
};
