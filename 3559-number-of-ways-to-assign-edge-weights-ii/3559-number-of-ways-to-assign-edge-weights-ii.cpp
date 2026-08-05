class Solution {
public:
    vector<vector<int>> dp;
    int lo=20; 
    int mod=(1e9+7);
    long long power(long long base, long long exp) {
        if (exp < 0) return 0; // Handle edge case if distance is 0
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }
    int f(int u,int k){
        int curr=u;
        for(int j=0;j<lo;j++){
            if(k & (1<<j)){
                if(curr==-1) return -1;
                curr=dp[curr][j];
            }
        }
        return curr;
    }
    void dfs(int i,int p,vector<vector<int>> &adj,vector<int> &dist,vector<int> &parent){
        parent[i]=p;
        for(auto it:adj[i]){
            if(it==p) continue;
            dist[it]=dist[i]+1;
            dfs(it,i,adj,dist,parent);
        }
    }

    int lca(int u,int v,vector<vector<int>> &adj){
        if(u==v) return u;
        for(int j=lo-1;j>=0;j--){
            if(dp[u][j]==-1) continue;
            if(dp[u][j]!=dp[v][j]){
                u=dp[u][j];
                v=dp[v][j];
            }
        }
        return dp[u][0];
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n=edges.size()+1;
        vector<vector<int>>adj(n);
        dp.assign(n+1,vector<int> (lo,-1));
        vector<int> parent(n+1,-1);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        vector<int> dist(n+1,INT_MAX);
        vector<int> vis(n+1,0);
        dist[0]=0;
        dfs(0,-1,adj,dist,parent);
        for(int i=0;i<n;i++) dp[i][0]=parent[i];
        for(int j=1;j<lo;j++){
            for(int i=0;i<n;i++){
                if(dp[i][j-1]>=0){
                    dp[i][j]=dp[dp[i][j-1]][j-1];
                }
            }
        }
        vector<int> ans;
        for(auto it:queries){
            int u=it[0]-1;
            int v=it[1]-1;
            int u1=u,v1=v;
            if(dist[u]>dist[v]) u1=f(u,dist[u]-dist[v]);
            else v1=f(v,dist[v]-dist[u]);
            int val=lca(u1,v1,adj);
            long long d=1LL*dist[u]+1LL*dist[v]-2LL*dist[val];
            int ans1=(int)power(2,d-1);
            ans.push_back(ans1);
        }
        return ans;
    }
};