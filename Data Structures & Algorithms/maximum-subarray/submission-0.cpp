class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        int sum=0;
        for(auto &x : nums){
            sum=max(x, sum+x);
            ans=max(ans, sum);
        }
        return ans;
    }
};
