class Solution {
public:
    #define ll long long
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<ll>> dp(m+1,vector<ll> (n+1,0)); // this will store the height which we can cut 
        for(auto it:prices){
            int h=it[0];
            int w=it[1];
            int price=it[2];
            dp[h][w]=price;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                // horizontal division
                for(int k=1;k<i;k++) dp[i][j]=max(dp[i][j],dp[i-k][j]+dp[k][j]);
                // vertical division
                for(int k=1;k<j;k++) dp[i][j]=max(dp[i][j],dp[i][j-k]+dp[i][k]);
            }
        }
        return dp[m][n];
    }
};