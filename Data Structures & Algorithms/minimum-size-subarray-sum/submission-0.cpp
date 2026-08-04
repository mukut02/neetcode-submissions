class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r=0,n=nums.size();
        int ans=n+1;
        int sum=0;
        while(r<n){
            sum+=nums[r];
            while(sum>=target){
                ans=min(ans,r-l+1);
                sum-=nums[l];
                l++;
            }
            
            r++;
        }
        if(ans==n+1) ans=0;
        return ans;
    }
};