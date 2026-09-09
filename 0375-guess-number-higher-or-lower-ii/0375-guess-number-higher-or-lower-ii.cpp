class Solution {
public:
    vector<vector<int>> dp;
    int f(int st,int end){
        if(st>=end) return 0;
        if(dp[st][end]!=-1) return dp[st][end];
        int ans=INT_MAX;
        for(int i=st;i<=end;i++) ans=min(ans,i+max(f(st,i-1),f(i+1,end)));
        return dp[st][end]=ans;
    }
    int getMoneyAmount(int n) {
        // if(n==1) return 0;
        // if(n==2) return 1;
        dp=vector<vector<int>> (n+1,vector<int> (n+1,-1));
        return f(1,n);
    }
};