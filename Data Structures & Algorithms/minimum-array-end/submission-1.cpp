class Solution {
public:
typedef long long ll;
    long long minEnd(int n, int x) {
        ll ans=x;
        int j=0;
        n--;
        for(int i=0;i<63;++i){
            if((1LL<<i)&x) continue;
            if(((1LL<<j)&n)){
                ans|=(1LL<<i);
            }
            
            j++;
        }
        return ans;
    }
};