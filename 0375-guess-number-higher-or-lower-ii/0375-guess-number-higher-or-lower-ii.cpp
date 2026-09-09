class Solution {
public:
    // vector<vector<int>> dp;
    // int f(int st,int end){
    //     if(st>=end) return 0;
    //     if(dp[st][end]!=-1) return dp[st][end];
    //     int ans=INT_MAX;
    //     for(int i=st;i<=end;i++) ans=min(ans,i+max(f(st,i-1),f(i+1,end)));
    //     return dp[st][end]=ans;
    // }
    int getMoneyAmount(int n) {
        // if(n==1) return 0;
        // if(n==2) return 1;
        vector<vector<int>> dp(n+2,vector<int> (n+2,0));
        for(int st=n;st>=1;st--){
            for(int end=st+1;end<=n;end++){
                int ans=1e9;
                for(int i=st;i<=end;i++){
                    ans=min(ans,i+max(dp[st][i-1],dp[i+1][end]));
                }
                dp[st][end]=ans;
            }
        }
        return dp[1][n];
    }
};