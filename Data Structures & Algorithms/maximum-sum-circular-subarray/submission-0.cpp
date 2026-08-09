class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum=-1e9,sum=0,tsum=0;
        for(auto &x : nums){
            tsum+=x;
            sum=max(sum+x, x);
            maxSum=max(maxSum, sum);
        }
        sum=0;
        int minSum=1e9;
        for(auto &x : nums){
            sum=min(sum+x, x);
            minSum=min(minSum, sum);
        }
        if(maxSum<0) return maxSum;
        return max(maxSum, tsum-minSum);
    }
};