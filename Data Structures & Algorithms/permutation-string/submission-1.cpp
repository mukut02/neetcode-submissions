class Solution {
public:
bool isEqual(map<char,int> &m1, map<char,int> &m2){
    for(char c='a';c<='z';++c){
        if(m1[c]!=m2[c]) return false;
    }
    return true;
}
    bool checkInclusion(string s1, string s2) {
        map<char,int> m1, m2;
        for(auto &x : s1) m1[x]++;
        int l=0, r=0, n=s2.size();
        while(r<n){
            m2[s2[r]]++;
            while(!m2.empty() && m2[s2[r]]>m1[s2[r]]){
                m2[s2[l]]--;
                if(m2[s2[l]]==0) m2.erase(s2[l]);
                
                l++;
            }
            if(isEqual(m1,m2)) return true;
            // cout << l << ' ' << r << '\n';
            r++;
        }
        return false;
    }
};
