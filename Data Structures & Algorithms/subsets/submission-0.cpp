class Solution {
public:
vector<vector<int>> ans;
void f(int i,vector<int>&sub,vector<int>&v){
    if(i==v.size()){
        ans.push_back(sub);
        return;
    }

    sub.push_back(v[i]);
    f(i+1,sub,v);
    sub.pop_back();
    f(i+1,sub,v);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub;
        f(0,sub,nums);
        return ans;
    }
};
