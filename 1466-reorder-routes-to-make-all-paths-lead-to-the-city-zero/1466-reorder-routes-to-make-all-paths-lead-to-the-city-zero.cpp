class Solution {
public:
    int dfs(int i,vector<vector<pair<int,int>>> &adj,vector<int> &vis){
        vis[i]=1;
        int ans=0;
        for(auto it:adj[i]){
            int v=it.first;
            int wt=it.second;
            if(!vis[v]){
                ans+=(wt+dfs(v,adj,vis));
            }
        }
        return ans;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back({connections[i][1],1});
            adj[connections[i][1]].push_back({connections[i][0],0});
        }
        vector<int> vis(n,0);
        return dfs(0,adj,vis);
    }
};