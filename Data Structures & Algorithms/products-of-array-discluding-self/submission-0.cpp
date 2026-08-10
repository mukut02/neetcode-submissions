class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> pf(n,1), sf(n,1);
        pf[0]=nums[0];
        sf[n-1]=nums[n-1];
        for(int i=1;i<n;++i){
            pf[i]=nums[i]*pf[i-1];
        }
        for(int i=n-2;i>=0;--i){
            sf[i]=sf[i+1]*nums[i];
        }
        vector<int> ans;
        for(int i=0;i<n;++i){
            int val = 1;
            if(i!=0) val=pf[i-1];
            if(i!=n-1) val*=sf[i+1];
            ans.push_back(val);
        }
        return ans;
    }
};
