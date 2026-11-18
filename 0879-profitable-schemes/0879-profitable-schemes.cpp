class Solution {
public:
    int mod=1e9+7;
    vector<vector<vector<int>>> dp;
    int val=100;
    int f(int i,int n,int minProfit,vector<int> &group,vector<int> &profit){
        if(i==group.size()){
            if(minProfit==0) return 1;
            return 0;
        }
        if(dp[i][n][minProfit]!=-1) return dp[i][n][minProfit];
        int ans=0;
        if(n-group[i]>=0) ans=(ans+f(i+1,n-group[i],max(0,minProfit-profit[i]),group,profit))%mod;
        ans=(ans+f(i+1,n,minProfit,group,profit))%mod;
        return dp[i][n][minProfit]=ans%mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        dp=vector<vector<vector<int>>> (group.size()+1,vector<vector<int>> (n+1,vector<int> (minProfit+1,-1)));
        return f(0,n,minProfit,group,profit);
    }
};