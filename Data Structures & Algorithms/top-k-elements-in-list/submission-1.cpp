class Solution {
public:
typedef pair<int,int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mpp;
        for(auto &x : nums) mpp[x]++;
        priority_queue<P, vector<P>, greater<P>> pq;
        for(auto &p : mpp){
            if(pq.size() < k){
                pq.push({p.second, p.first});
            }
            else if(pq.top().first < p.second){
                pq.pop();
                pq.push({p.second, p.first});
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
