class Solution {
public:
    int dp[501][501];
    int f(int i,int j,vector<int> &piles){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take1=piles[i]-f(i+1,j,piles);
        int take2=piles[j]-f(i,j-1,piles);
        return dp[i][j]=max(take1,take2);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        memset(dp,-1,sizeof(dp));
        return f(0,n-1,piles)>=0;
    }
};