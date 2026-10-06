class Solution {
public:
    // according to my observation i think i have to do toposort first and return -1 else dp on DAG
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        vector<int> topo;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(topo.size()!=n) return -1;
        // now we have to traverse according to topo array 
        vector<vector<int>> dp(n,vector<int> (26,0));
        int ans=0;
        for(auto u:topo){
            dp[u][colors[u]-'a']++;
            for(int c=0;c<26;c++) ans=max(ans,dp[u][c]);
            for(auto v:adj[u]){
                for(int c=0;c<26;c++){
                    dp[v][c]=max(dp[u][c],dp[v][c]);
                }
            }
        }
        return ans;
    }
};