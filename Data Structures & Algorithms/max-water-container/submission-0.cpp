class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans=0,n=heights.size();
        int l=0, r=n-1;
        while(l<=r){
            int h = min(heights[l], heights[r]);
            ans=max(ans,h*(r-l));
            if(heights[l] < heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return ans;

    }
};
