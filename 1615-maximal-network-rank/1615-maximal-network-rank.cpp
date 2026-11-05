class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& road) {
        vector<vector<int>> adj(n);
        if(road.size()==0) return 0;
        for(int i=0;i<road.size();i++){
            adj[road[i][0]].push_back(road[i][1]);
            adj[road[i][1]].push_back(road[i][0]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                set<pair<int,int>> st;
                for(auto it:adj[i]) st.insert({min(it,i),max(it,i)});
                for(auto it:adj[j]) st.insert({min(it,j),max(it,j)});
                ans=max(ans,(int)st.size());
            }
        }
        return ans;
    }
};