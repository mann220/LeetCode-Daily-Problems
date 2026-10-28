class Solution {
public:
    // we can do it easily by bipartite
    vector<int> par;
    int findupar(int u){
        if(u==par[u]) return u;
        return par[u]=findupar(par[u]);
    }
    void uni(int u,int v){
        int ultp_u=findupar(u);
        int ultp_v=findupar(v);
        if(ultp_u==ultp_v) return;
        else par[ultp_v]=ultp_u;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        par=vector<int> (n+1);
        for(int i=1;i<=n;i++) par[i]=i;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<dislikes.size();i++){
            int u=dislikes[i][0];
            int v=dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=1;i<=n;i++){
            for(auto it:adj[i]){
                if(findupar(i)==findupar(it)) return false;
                uni(adj[i][0],it);
            }
        }
        return true;
    }   
};