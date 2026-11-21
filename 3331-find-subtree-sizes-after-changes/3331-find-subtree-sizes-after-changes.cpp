class Solution {
public:
    // we can do it in one go
    void dfs(int i,vector<vector<int>> &adj,vector<int> &hash,vector<int> &par,vector<int> &ans,string &s){
        int prev=hash[s[i]-'a'];
        hash[s[i]-'a']=i;
        for(auto it:adj[i]){
            dfs(it,adj,hash,par,ans,s);
        }
        if(i!=0){
            int newpar=(prev==-1)? par[i]:prev;
            ans[newpar]+=ans[i];
        }
        hash[s[i]-'a']=prev;
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=s.size();
        vector<vector<int>> adj(n);
        for(int i=1;i<n;i++) adj[parent[i]].push_back(i);
        vector<int> hash(26,-1);
        vector<int> ans(n,1);
        dfs(0,adj,hash,parent,ans,s);
        return ans;
    }
};