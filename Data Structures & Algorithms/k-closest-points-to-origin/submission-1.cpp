class Solution {
public:
typedef pair<int, pair<int,int>> P;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<P > pq;


        for(auto &pt : points){
            int d = pt[0]*pt[0] + pt[1]*pt[1];

            if(pq.size()<k){
                pq.push({d, {pt[0], pt[1]}});
            } 
            else{
                if(pq.top().first > d){
                    pq.pop();
                    pq.push({d, {pt[0], pt[1]}});
                }
            }
        }
        while(!pq.empty()){
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};
