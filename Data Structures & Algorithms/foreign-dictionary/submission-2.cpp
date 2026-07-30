class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        map<int,set<int>> adj;
        int n=words.size();
        vector<int> indegree(26, 0);
        
        // --- FIX 1: Track all unique characters present in the words ---
        set<int> unique_chars;
        for (const string& w : words) {
            for (char c : w) unique_chars.insert(c - 'a');
        }

        for(int i=0;i<n-1;++i){
            int n1=words[i].size(),n2=words[i+1].size();
            int j1=0,j2=0;
            
            while(j1<n1 && j2<n2){
                int c1 = words[i][j1]-'a',c2 = words[i+1][j2]-'a';
                if(c1==c2) {
                     j1++;j2++;
                    continue;
                }
                if(!adj[c1].count(c2)) indegree[c2]++;
                adj[c1].insert(c2);
                j1++;j2++;
                break;
            }

            // --- FIX 2: Check for invalid prefix order (e.g., ["abcd", "abc"]) ---
            if (j1 < n1 && j2 == n2) return "";
        }
        
        queue<int> q;
        // --- FIX 3: Iterate through unique_chars instead of just adj keys ---
        for(int c : unique_chars){
            if(indegree[c]==0) q.push(c);
        }

        string ans;
        while(!q.empty()){
            int node = q.front();q.pop();
            ans.push_back(node+'a');
            for(int nxt : adj[node]){
                indegree[nxt]--;
                if(indegree[nxt]==0) q.push(nxt);
            }
        }

        // --- FIX 4: Check if all unique characters were included in topological order ---
        if (ans.size() < unique_chars.size()) return "";

        return ans;
    }
};
