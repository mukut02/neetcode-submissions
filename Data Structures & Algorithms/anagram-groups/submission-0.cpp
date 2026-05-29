class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mpp;
        for(auto &w : strs){
            string key=w;
            sort(key.begin(), key.end());
            mpp[key].push_back(w);
        }
        vector<vector<string>> ans;
        for(auto &p : mpp){
            vector<string> v;
            for(auto &x : p.second){
                v.push_back(x);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
