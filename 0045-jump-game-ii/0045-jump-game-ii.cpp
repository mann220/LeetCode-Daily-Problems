class Solution {
public:
    // my observations says its dp in which we have to try all possibilities 
    int n;
    // vector<long long> dp;
    // long long f(int i,vector<int> &nums){
    //     if(i>=n-1) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     long long ans=INT_MAX;
    //     for(int j=i+1;j<=i+nums[i];j++){
    //         ans=min(ans,1+f(j,nums));
    //     }
    //     return dp[i]=ans;
    // }
    int jump(vector<int>& nums) {
        n=nums.size();
        vector<long long> dp(n,INT_MAX);
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--){
            long long ans=INT_MAX;
            for(int j=i+1;j<=min(n-1,i+nums[i]);j++){
                dp[i]=min(dp[i],1+dp[j]);
            }
        }
        return (int)dp[0];
    }
};