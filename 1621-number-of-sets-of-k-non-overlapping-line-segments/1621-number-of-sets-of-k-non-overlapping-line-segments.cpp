class Solution {
public:
    int mod=1e9+7;
    int sz;
    // we are taking here points in which it is open means line start and close
    // vector<vector<int>> dp;
    // int f(int n,int k,int i){
    //     if(i>=n) return 0;
    //     if(k==0) return 1;
    //     int take=0;
    //     for(int j=i+1;j<n;j++) take=(take+f(n,k-1,j))%mod;
    //     int skip=f(n,k,i+1)%mod;
    //     return take+skip;
    // }
    #define ll long long
    int numberOfSets(int n, int k) {
        vector<vector<ll>> dp(n+1,vector<ll>(k+1,0));
        for(int i=0;i<n;i++) dp[i][0]=1;
        for(int j=1;j<=k;j++){
            vector<ll> pre(n+1,0);
            for(int x=n-1;x>=0;x--) pre[x]=(pre[x+1]+dp[x][j-1])%mod;
            for(int i=n-1;i>=0;i--){
                ll nttk=dp[i+1][j];
                ll tk=0;   
                tk=(tk+pre[i+1])%mod;
                dp[i][j]=(tk+nttk)%mod;
            }
        }
        return dp[0][k];
    }
};