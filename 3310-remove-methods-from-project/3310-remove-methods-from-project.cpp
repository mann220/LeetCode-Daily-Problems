class Solution {
public:
    void dfs(int i,vector<int> &vis,vector<vector<int>> &adj){
        vis[i]=1;
        for(auto it:adj[i]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& v) {
        vector<vector<int>> adj(n);
        for(int i=0;i<v.size();i++){
            adj[v[i][0]].push_back(v[i][1]);
        }
        vector<int> vis1(n,0);
        dfs(k,vis1,adj);
        // for(int i=0;i<n;i++) cout<<vis1[i]<<" ";
        // cout<<endl;
        vector<int> vis2(n,0);
        for(int i=0;i<n;i++){
            if(vis1[i]==0) dfs(i,vis2,adj);
        }
        // for(int i=0;i<n;i++) cout<<vis2[i]<<" ";
        // cout<<endl;
        vector<int> ans;
        bool flag=false;
        for(int i=0;i<n;i++){
            if(vis2[i]==1 && vis1[i]==1){
                flag=true;
            }
        }
        for(int i=0;i<n;i++){
            if(flag) ans.push_back(i);
            else{
                if(vis2[i]==1) ans.push_back(i);
            }
        }
        return ans;
    }
};