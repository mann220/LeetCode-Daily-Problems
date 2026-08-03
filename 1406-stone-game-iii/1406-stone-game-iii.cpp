class Solution {
public:
    vector<int> dp;
    // int f(int i,vector<int>& nums){
    //     int n=nums.size();
    //     if(i>=n) return 0;
    //     if(dp[i]!=INT_MIN) return dp[i];
    //     int take1=nums[i]-f(i+1,nums);
    //     int take2=INT_MIN;
    //     int take3=INT_MIN;
    //     if(i+1<n) take2=nums[i]+nums[i+1]-f(i+2,nums);
    //     if(i+2<n) take3=nums[i]+nums[i+1]+nums[i+2]-f(i+3,nums);
    //     return dp[i]=max({take1,take2,take3});
    // }
    string stoneGameIII(vector<int>& nums) {
        int n=nums.size();
        dp.assign(n+1,0);
        for(int i=n-1;i>=0;i--){
            int take1=nums[i]-dp[i+1];
            int take2=INT_MIN,take3=INT_MIN;
            if(i+1<n) take2=nums[i]+nums[i+1]-dp[i+2];
            if(i+2<n) take3=nums[i]+nums[i+1]+nums[i+2]-dp[i+3];
            dp[i]=max({take1,take2,take3});
        }
        if(dp[0]==0) return "Tie";
        return dp[0]>0 ? "Alice":"Bob";
    }
};