class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int w=roads[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        queue<int> q;
        vector<int> vis(n+1,false);
        vector<int> nd;
        vis[1]=true;
        int mini=INT_MAX;
        q.push(1);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                int v=it.first;
                if(!vis[v]){
                    vis[v]=true;
                    nd.push_back(v);
                    q.push(v);
                }
            }
        }
        for(int i=0;i<nd.size();i++){
            for(auto it:adj[nd[i]]) mini=min(mini,it.second);
        }
        return mini;
    }
};