class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<vector<int>> comp;
        vector<int> vis(n,0);
        queue<int> q;
        int ans=0;
        for(int i=0;i<n;i++){
            int vertex=0;
            int edge=0;
            if(!vis[i]){
                q.push(i);
                vis[i]=1;
                while(!q.empty()){
                    int node=q.front();
                    vertex++;
                    q.pop();
                    for(auto it:adj[node]){
                        edge++;
                        if(!vis[it]){
                            q.push(it);
                            vis[it]=1;
                        }
                    }
                }
                if(edge==(vertex*(vertex-1))) ans++;
            }
        }
        return ans;
    }
};