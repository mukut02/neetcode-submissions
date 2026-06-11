class Solution {
public:
int maxe(map<char,int> &mpp){
    int maxe=0;
    for(auto &p : mpp){
        maxe = max(maxe, p.second);
    }

    return maxe;
}
    int characterReplacement(string s, int k) {
        map<char,int> mpp;
        int l=0,r=0,n=s.size(),ans=0;

        while(r<n){
            mpp[s[r]]++;
            while( ( (r-l+1)-maxe(mpp) ) > k){
                mpp[s[l]]--;
                l++;
            }
            ans=max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};
