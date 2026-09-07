class Solution {
public:
    int mod=1e9+7;
    int distinctSubseqII(string s) {
        int n=s.size();
        unordered_map<char,int> mpp;
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            dp[i]=(2*dp[i-1])%mod;
            if(mpp.find(s[i-1])!=mpp.end()){
                dp[i]=(dp[i]-dp[mpp[s[i-1]]])%mod;
            }
            mpp[s[i-1]]=i-1;
        }
        return (dp[n]-1+mod)%mod;
    }
};