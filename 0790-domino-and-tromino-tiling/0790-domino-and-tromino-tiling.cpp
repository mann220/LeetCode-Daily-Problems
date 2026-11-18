class Solution {
public:
    #define ll long long
    int mod=1e9+7;
    int dp[1001][1001];
    int f(int r1,int r2){
        if(r1==0 && r2==0) return 1;
        if(r1<=0 || r2<=0) return 0;
        if(dp[r1][r2]!=-1) return dp[r1][r2];
        ll ans=0;
        if(r1==r2){
            ans+=f(r1-1,r2-1); // vertical tile 
            ans+=f(r1-2,r2-2); // horizontal tile on both r1 and r2 
            ans+=f(r1-2,r2-1); // this type of shape=> |`
            ans+=f(r1-1,r2-2); // this type of shape=> _|
        }
        else if(r1>r2){
            ans+=f(r1-2,r2);
            ans+=f(r1-2,r2-1);
        }
        else{
            ans+=f(r1,r2-2); 
            ans+=f(r1-1,r2-2);
        }
        return dp[r1][r2]=ans%mod;
    }
    int numTilings(int n) {
        memset(dp,-1,sizeof(dp));
        return f(n,n);
    }
};