#include<cstring>
int dp[1005][1005];
class Solution {
public:
int f(int i,int j,string&s1, string &s2){
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==s1.size() or j==s2.size()) return dp[i][j]= 0;
    if(s1[i]==s2[j]){
        return dp[i][j]=f(i+1,j+1,s1,s2)+1;
    }
    return dp[i][j]=max(f(i+1,j,s1,s2), f(i,j+1,s1,s2));
}
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1,sizeof(dp));
        return f(0,0,text1,text2);
    }
};
