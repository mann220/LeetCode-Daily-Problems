class Solution {
public:
    int dp[21][21];
    int f(int i,int j,vector<int> &nums){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take1=nums[i]-f(i+1,j,nums);
        int take2=nums[j]-f(i,j-1,nums);
        return dp[i][j]=max(take1,take2);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return f(0,n-1,nums)>=0;
    }
};