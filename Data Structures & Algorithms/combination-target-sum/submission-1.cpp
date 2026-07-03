class Solution {
public:
set<vector<int>> ans;
void f(int i,int sum,vector<int>&sub,vector<int>&v){
    if(sum==0){
        ans.insert(sub);
        return;
    }
    if(i==v.size()) return;
    f(i+1,sum,sub,v);
    if(sum-v[i]>=0){
        sub.push_back(v[i]);
        f(i,sum-v[i],sub,v);
        sub.pop_back();
        f(i+1,sum,sub,v);
    }
}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> sub;
        f(0,target,sub,nums);
        vector<vector<int>> v;
        for(auto &x : ans) v.push_back(x);
        return v;
    }
};
