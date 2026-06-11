class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mpp;
        int l=0,r=0,n=s.size();
        int ans=0;
        while(r<n){
            mpp[s[r]]++;
            while(mpp[s[r]]>1){
                mpp[s[l]]--;
                l++;
            }
            ans=max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};
