class TreeAncestor {
public:
    vector<vector<int>> dp;
    int lo=32;
    TreeAncestor(int n, vector<int>& parent) {
        dp.assign(n,vector<int> (lo,-1));
        for(int i=0;i<n;i++) dp[i][0]=parent[i];
        for(int j=1;j<lo;j++){
            for(int i=0;i<n;i++){
                if(dp[i][j-1]>=0){
                    dp[i][j]=dp[dp[i][j-1]][j-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int cur=node;
        for(int j=0;j<lo;j++){
            if(k & (1<<j)){
                if(cur==-1) return -1;
                cur=dp[cur][j];
            }
        }
        return cur;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */