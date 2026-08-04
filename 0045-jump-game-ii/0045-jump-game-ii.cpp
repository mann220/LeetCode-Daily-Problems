class Solution {
public:
    // my observations says its dp in which we have to try all possibilities 
    int n;
    vector<int> dp;
    long long f(int i,vector<int> &nums){
        if(i>=n-1) return 0;
        if(dp[i]!=-1) return dp[i];
        long long ans=INT_MAX;
        for(int j=i+1;j<=i+nums[i];j++){
            ans=min(ans,1+f(j,nums));
        }
        return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        n=nums.size();
        dp.assign(n,-1);
        return (int)f(0,nums);
    }
};