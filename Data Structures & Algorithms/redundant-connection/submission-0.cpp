class Solution {
public:
class DSU{
private:
    int n;
    vector<int> par;
    vector<int> size;
public:
    DSU(int n){
        this->n=n;
        par.resize(n);
        size.resize(n, 1);
        for(int i=0;i<n;++i) par[i]=i;
    }

    int find(int u){
        if(par[u]==u) return u;
        return par[u]=find(par[u]);
    }

    bool merge(int u,int v){
        int U=find(u);
        int V=find(v);
        if(U==V) return false;

        if(size[U] < size[V]) swap(U,V);
        par[V]=U;
        size[U]+=size[V];

        return true;
    }
};
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n+1);

        for(auto &e : edges){
            if(!dsu.merge(e[0], e[1])){
                return e;
            }
        }
        return {};      
    }
};