class Solution {
public:
    int f(int i,vector<vector<int>>& items, int m,vector<int> &num,vector<vector<int>> &dp,int mini){
        if(i<0) return m/mini;
        if(m<=0) return 0;
        if(dp[i][m]!=-1) return dp[i][m];
        int ans1=0;
        if(m-items[i][1]>=0) ans1=1+num[i]+f(i-1,items,m-items[i][1],num,dp,mini);
        int ans2=f(i-1,items,m,num,dp,mini);
        return dp[i][m]=max(ans1,ans2);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        int mini=INT_MAX;
        vector<int> num(n);
        vector<vector<int>> dp(n+1,vector<int>(budget+1,-1));
        for(int i=0;i<n;i++){
            int u=items[i][0];
            mini=min(mini,items[i][1]);
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int v=items[j][0];
                if(v%u==0) cnt++;
            }
            num[i]=cnt;
        }
        for(int i=0;i<n;i++) cout<<num[i]<<" ";
        return f(n-1,items,budget,num,dp,mini);
    }
};