class Solution {
public:
    // my first instinct say we just have to apply dfs and calulate the number of pathvis count ig
    int ans;
    bool dfs(int i,int cnt,vector<int> &pathvis,vector<bool> &vis,vector<vector<int>> &adj){
        vis[i]=true;
        pathvis[i]=cnt;
        // cout<<i<<" "<<cnt<<"\n";
        for(auto it:adj[i]){
            if(!vis[it]){
                if(dfs(it,cnt+1,pathvis,vis,adj)) return true;
            }
            else if(pathvis[it]){
                ans=max(ans,cnt-pathvis[it]+1);
                // cout<<it<<" "<<cnt<<" "<<pathvis[it]<<" "<<ans<<"\n";
                // return true;  --> my error dut to which i get wrong answer
            }
        }
        pathvis[i]=0;
        return false;
    }
    int longestCycle(vector<int>& edges) {
        ans=0;
        int n=edges.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            int u=i;
            int v=edges[i];
            if(v==-1) continue;
            adj[u].push_back(v);
        }
        vector<int> pathvis(n,0);
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,1,pathvis,vis,adj);
            }
        }
        return ans==0 ? -1:ans;
    }
};