class Solution {
public:
    // this question is using fibonacci as the observation here is the lenght i in bits of the number having non-consecutive one is given by dp[i]=dp[i-1]+dp[i-2] same as fibonacci this tell that it gives the number containing non consecutive ones upto length i;
    int findIntegers(int n) {
        vector<int> dp(31);
        dp[0]=1;
        dp[1]=2;
        for(int i=2;i<31;i++) dp[i]=dp[i-1]+dp[i-2];
        int ans=0;
        for(int i=30;i>=0;i--){
            if(n & (1<<i)){
                ans+=dp[i];
                if(i<30 && (n & (1<<(i+1)))) return ans;
            }
        }
        return ans+1;
    }
};