class Solution {
public:
    // i think in this question i have to make a graph of prerequisites and for each prerequisite i have to check that can it reach that node as the value is <=100 so i think i can do it that in simple way
    bool dfs(int node1,int node2,vector<vector<int>> & adj,vector<int> &vis){
        if(node1==node2) return true;
        vis[node1]=true;
        for(auto it:adj[node1]){
            if(!vis[it]){
                if(dfs(it,node2,adj,vis)) return true;
            }
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& v, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(auto it:v) adj[it[0]].push_back(it[1]);
        vector<bool> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            int node1=queries[i][0];
            int node2=queries[i][1];
            vector<int> vis(n,0);
            ans[i]=dfs(node1,node2,adj,vis);
        }
        return ans;
    }
};