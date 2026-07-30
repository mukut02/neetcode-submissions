class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=1,curr=1,n=nums.size();
        if(n<=1) return n;
        sort(nums.begin(), nums.end());
        for(int i=1;i<n;++i){
            if(nums[i]==nums[i-1]+1) curr++;
            else if(nums[i]!=nums[i-1]){
                curr=1;
            }
            ans=max(ans, curr);
        }
        
        return ans;
    }
};
