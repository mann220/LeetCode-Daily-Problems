class Solution {
public:
    // see video https://www.youtube.com/watch?v=7i-RfOxv5Kc if u have doubt
    // the approach here is this, we delete first all the leaf node which doesn't contain any coin as we are deleting nodes then if we delete both child of a node then the node also become leaf node so we also delete it, hence in this we have to delete nodes until we delete all nodes.
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n=coins.size();
        vector<vector<int>> adj(n);
        int ans=n; // this is the total nodes
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> leafNodes; // this will store leaf node
        for(int i=0;i<n;i++){
            if(adj[i].size()==1) leafNodes.push(i);
        }
        queue<int> leafNodeWithCoins; // this will store leaf node with coins
        while(!leafNodes.empty()){
            int node=leafNodes.front();
            leafNodes.pop();
            if(coins[node]==1){
                leafNodeWithCoins.push(node);  // this will push those leaf node which has coin
                continue;
            }
            ans--; // the nodes which are we removing
            for(auto x:adj[node]){
                auto itnode=find(adj[node].begin(),adj[node].end(),x);
                auto itadjnode=find(adj[x].begin(),adj[x].end(),node);
                adj[node].erase(itnode);
                adj[x].erase(itadjnode);
                if(adj[x].size()==1) leafNodes.push(x); // this will push nodes if someone become leafnode
            }
        }
        // now we are doing bfs to remove the node having coin and one more node as the distance is 2 and we only left with nodes from which we can access all coins so the 2*(remaining nodes-1) is the answer because we have to travel till the full graph and then comes back so if there are 3 nodes then edges are 2 so we have to tarvel 2 distance and then back which gives total distance of 4.
        for(int i=0;i<2;i++){
            int sz=leafNodeWithCoins.size();
            for(int j=0;j<sz;j++){
                int node=leafNodeWithCoins.front();
                leafNodeWithCoins.pop();
                ans--; // nodes which we are removing
                for(auto x:adj[node]){
                    auto itnode=find(adj[node].begin(),adj[node].end(),x);
                    auto itadjnode=find(adj[x].begin(),adj[x].end(),node);
                    adj[node].erase(itnode);
                    adj[x].erase(itadjnode);
                    if(adj[x].size()==1) leafNodeWithCoins.push(x);
                }
            }
        } 
        return ans==0 ? 0 : 2*(ans-1);
    }   
};