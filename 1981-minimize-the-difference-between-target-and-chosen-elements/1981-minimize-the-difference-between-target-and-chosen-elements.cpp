class Solution {
public:
    vector<vector<int>> dp;
    int f(int i,int sum,vector<vector<int>>& mat,int target){
        int n=mat.size();
        int m=mat[0].size();
        if(i==n) return abs(sum-target);
        if(dp[i][sum]!=-1) return dp[i][sum];
        int ans=INT_MAX;
        for(int j=0;j<m;j++){
            ans=min(ans,f(i+1,sum+mat[i][j],mat,target));
        }
        return dp[i][sum]=ans;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n=mat.size();
        dp.assign(n,vector<int> (4901,-1));
        int ans=INT_MAX;
        return f(0,0,mat,target);
    }
};