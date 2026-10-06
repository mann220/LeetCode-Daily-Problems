class Solution {
public:
    vector<vector<int>> coprime;
    vector<int> ans;
    vector<vector<pair<int,int>>> state; // store depth and node
    void dfs(int node,int par,int depth,vector<vector<int>> &adj,vector<int> &nums){
        int best_depth=-1;
        int best_node=-1;
        int val=nums[node];
        // first we have check the closest ancestor i.e. best ancestor for that val as we store in state
        for(auto i:coprime[val]){
            if(!state[i].empty()){
                int d=state[i].back().first;
                int id=state[i].back().second;
                if(d>best_depth){
                    best_depth=d;
                    best_node=id;
                }
            }
        }
        ans[node]=best_node;
        // add current node and depth to the state
        state[val].push_back({depth,node});
        // now we have to go to childs of that node
        for(auto it:adj[node]){
            if(it!=par) dfs(it,node,depth+1,adj,nums); //here depth increases by 1 unit
        }
        // we hve to do backtrack becz this best depth is for this subtree and it is going back so we have to remove it from that val;
        state[val].pop_back();
    }
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        state.assign(51,vector<pair<int,int>>());
        ans.assign(n,-1);
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        coprime.assign(51,vector<int>());
        for(int i=1;i<=50;i++){
            for(int j=1;j<=50;j++){
                if(__gcd(i,j)==1) coprime[i].push_back(j);
            }
        }
        dfs(0,-1,0,adj,nums);
        return ans;
    }
};