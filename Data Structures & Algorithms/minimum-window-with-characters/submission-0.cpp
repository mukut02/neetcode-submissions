class Solution {
public:
bool check(unordered_map<char,int> &m1,unordered_map<char,int> &m2){
    for(auto &p : m2){
        if(m1[p.first]<p.second) return false;
    }
    return true;
}
    string minWindow(string s, string t) {
        unordered_map<char,int> m1,m2;
        for(auto &x : t) m2[x]++;
        int l=0,r=0,n=s.size();
        int ans=n+1;
        vector<int> indx;
        while(r<n){
            m1[s[r]]++;
            while(check(m1,m2)){
                if((r-l+1)<ans){
                    indx={l,r};
                    ans=r-l+1;
                }
                m1[s[l]]--;
                ++l;
            }
            r++;
        }
        string sans;
        if(ans==n+1) return sans;
        for(int i=indx[0];i<=indx[1];++i){
            sans.push_back(s[i]);
        }
        return sans;
    }
};