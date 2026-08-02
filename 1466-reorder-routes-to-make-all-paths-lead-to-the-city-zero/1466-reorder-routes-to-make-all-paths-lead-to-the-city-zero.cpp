class Solution {
public:
    void bfs(int i,vector<vector<pair<int,int>>> &adj,vector<int> &vis,int &dist){
        queue<int> q;
        q.push(i);
        vis[i]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                int v=it.first;
                int wt=it.second;
                if(!vis[v]){
                    dist+=wt;
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back({connections[i][1],1});
            adj[connections[i][1]].push_back({connections[i][0],0});
        }
        vector<int> vis(n,0);
        int ans=0;
        bfs(0,adj,vis,ans);
        return ans;
    }
};