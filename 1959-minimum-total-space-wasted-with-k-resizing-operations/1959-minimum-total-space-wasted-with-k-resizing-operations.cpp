class Solution {
public:
    // my observation is saying that i have to check for every instance and this can only be done with the help of dp, i have to store sizes of the array in ascending order and then start the dp checking from first index and changes until the value of k becomes 0 or we reach at end -- no this is worng becoause if we have to change the value then how we find whats the next value;
    int dp[201][201];
    int f(int i,int k,vector<int> &nums){
        int n=nums.size();
        if(i==n) return 0;
        if(k<0) return 1e9;
        if(dp[i][k]!=-1) return dp[i][k];
        int mx=0;
        int sum=0;
        int ans=1e9;
        for(int j=i;j<n;j++){
            mx=max(mx,nums[j]);
            sum+=nums[j];
            int wasted=(j-i+1)*mx-sum;
            ans=min(ans,wasted+f(j+1,k-1,nums));
        }
        return dp[i][k]=ans;
    }
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        return f(0,k,nums);
    }
};