class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // by simple dp
        vector<int> dp(n+1,1e9);
        dp[0]=0;
        for(int i=0;i<=n;i++){
            int lft=max(0,i-ranges[i]);
            int rgt=min(i+ranges[i],n);
            for(int j=lft;j<=rgt;j++){
                dp[j]=min(dp[j],1+dp[lft]);
            }
        }
        return dp[n]==1e9 ? -1:dp[n];
    }
};