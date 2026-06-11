class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int l=0,r=0,n=nums.size();
        map<int,int> mpp;
        while(r<n){
            mpp[nums[r]]++;
            if((r-l)>k){
                mpp[nums[l]]--;
                l++;
            }
            if(mpp[nums[r]]>1) return true;
            r++;
        }
        return false;
    }
};