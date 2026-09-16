class Solution {
public:
    int mod=1e9+7;
    int sz;
    vector<vector<int>> dp;
    int f(int n,int k){
        if(k>n || k<0) return 0;
        if(n==0){
            if(k==0) return 1;
            return 0;
        }
        if(dp[n][k]!=-1) return dp[n][k];
        int opt1=f(n-1,k); // we skipped that length
        int opt2=f(n-1,k-1); // we draw a line on that length
        return dp[n][k]=(opt1+opt2)%mod;
    }
    int numberOfSets(int n, int k) {
        dp=vector<vector<int>> (n+k+1,vector<int> (2*k+1,-1));
        return f(n+k-1,2*k)%mod;
    }
};