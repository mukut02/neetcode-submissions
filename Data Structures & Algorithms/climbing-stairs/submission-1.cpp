#include<cstring>
class Solution {
public:
int dp[46];
int f(int i){
    // Base Case
    if(dp[i]!=-1) return dp[i];
    if(i<=1) return dp[i]=1;
    // Transition
    return dp[i]=f(i-1) + f(i-2);;
}
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return f(n);
    }
};
