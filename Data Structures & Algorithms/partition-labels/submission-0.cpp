class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> v(26,-1);
        int n=s.size();
        for(int i=0;i<n;++i){
            v[s[i]-'a']=i;
        }
        vector<int> ans;
        int start=0,end=0;
        for(int i=0;i<n;++i){
            end=max(end, v[s[i]-'a']);
            if(end==i) {
                ans.push_back(end-start+1);
                start=i+1;
            }
        }
        return ans;
    }
};
