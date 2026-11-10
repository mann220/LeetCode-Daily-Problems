class Solution {
public:
    vector<int> dp;
    int f(int i,vector<int> &costs){
        int n=costs.size();
        if(i>=n) return 1e9;
        if(i==n-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=1e9;
        for(int j=i+1;j<=min(i+3,n-1);j++) ans=min(ans,costs[j]+(j-i)*(j-i)+f(j,costs));
        return dp[i]=ans;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> val(n+1,0);
        for(int i=1;i<=n;i++) val[i]=costs[i-1];
        dp=vector<int> (n+1,-1);
        return f(0,val);
    }
};