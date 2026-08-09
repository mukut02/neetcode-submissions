class Solution {
public:
    int calPoints(vector<string>& operations) {
        int ans=0;
        stack<string> st;
        for(auto &x : operations){
            if(x=="C"){
                st.pop();
            }
            else if(x=="+"){
                int val1 = stoi(st.top());st.pop();
                int val2 = stoi(st.top());st.pop();
                st.push(to_string(val2));
                st.push(to_string(val1));
                st.push(to_string(val1+val2));
            }
            else if(x=="D"){
                int val = stoi(st.top());st.pop();
                st.push(to_string(val));
                st.push(to_string(2*val));
            }
            else{
                st.push(x);
            }
        }
        while(!st.empty()){
            ans+=stoi(st.top());
            st.pop();
        }
        return ans;
    }
};