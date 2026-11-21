class Solution {
public:
    void dfs(int i,vector<vector<int>> &adj,vector<vector<int>> &hash,vector<int> &par,string &s){
        if(hash[s[i]-'a'].size()==0) hash[s[i]-'a'].push_back(i);
        else{
            par[i]=hash[s[i]-'a'].back();
            hash[s[i]-'a'].push_back(i);
        }
        for(auto it:adj[i]){
            dfs(it,adj,hash,par,s);
        }
        hash[s[i]-'a'].pop_back();
    }
    int dfs1(int i,vector<vector<int>> &adj,vector<int>&ans){
        int cnt=1;
        for(auto it:adj[i]){
            cnt+=dfs1(it,adj,ans);
        }
        return ans[i]=cnt;
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=s.size();
        vector<vector<int>> adj(n);
        for(int i=1;i<n;i++) adj[parent[i]].push_back(i);
        vector<vector<int>> hash(26);
        dfs(0,adj,hash,parent,s);
        vector<vector<int>> adj1(n);
        for(int i=0;i<n;i++) cout<<parent[i]<<" ";
        for(int i=1;i<n;i++) adj1[parent[i]].push_back(i);
        vector<int> ans(n);
        dfs1(0,adj1,ans);
        return ans;
    }
};