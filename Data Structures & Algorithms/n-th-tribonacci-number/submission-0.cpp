#include<cstring>
class Solution {
public:
int dp[38];
int f(int i){
    if(dp[i]!=-1) return dp[i];
    if(i<=2) return dp[i]=(i+2)/3;
    return dp[i] = f(i-1) + f(i-2) + f(i-3);
}
    int tribonacci(int n) {
        memset(dp, -1 ,sizeof(dp));
        return f(n);
    }
};