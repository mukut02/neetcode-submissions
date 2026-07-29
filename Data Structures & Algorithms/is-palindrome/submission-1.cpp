class Solution {
public:
    bool isPalindrome(string s) {
        string v;
        for(auto &x : s){
            if(x>='A' && x<='Z'){
                v.push_back(x-'A'+'a');
            }
            else if(x>='a' && x<='z'){
                v.push_back(x);
            }
            else if(x>='0' && x<='9'){
                v.push_back(x);
            }
        }
        int n=v.size();
        int i=0,j=n-1;
        while(i<=j){
            if(v[i]!=v[j]) return false;
            i++;j--;
        }
        return true;
    }
};
