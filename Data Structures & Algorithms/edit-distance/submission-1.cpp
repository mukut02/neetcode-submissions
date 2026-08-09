#include<cstring>
int dp[105][105];
class Solution {
public:
int f(int i,int j,string &s1, string &s2){
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==s1.size() && j==s2.size()) return dp[i][j]=0;
    if(i==s1.size() or j==s2.size()) return dp[i][j]=(s1.size()-i) + (s2.size()-j);

    if(s1[i]==s2[j]){
        return dp[i][j]=f(i+1,j+1,s1,s2);
    }
    return dp[i][j]=min(f(i+1,j+1,s1,s2), min(f(i+1,j,s1,s2), f(i,j+1,s1,s2)) ) + 1;
}
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,word1,word2);
    }
};
