class Solution {
public:
    int mod=1e9+7;
    #define ll long long
    int numTilings(int n) {
        vector<ll> dp(1001);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        for(int i=4;i<=n;i++){
            dp[i]=(2LL*dp[i-1]+dp[i-3])%mod;
        }
        return dp[n];
    }
};