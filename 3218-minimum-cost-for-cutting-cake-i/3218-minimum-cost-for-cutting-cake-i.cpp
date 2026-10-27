class Solution {
public:
    int dp[21][21][21][21];
    int f(int r1,int r2,int c1,int c2,vector<int>&h,vector<int>& v){
        if((r2-r1)==1 && (c2-c1)==1) return 0;
        if(dp[r1][r2][c1][c2]!=-1) return dp[r1][r2][c1][c2];
        int ans=INT_MAX;
        // lets take horizontal cut
        for(int i=r1+1;i<r2;i++) ans=min(ans,h[i-1]+f(r1,i,c1,c2,h,v)+f(i,r2,c1,c2,h,v));
        for(int j=c1+1;j<c2;j++) ans=min(ans,v[j-1]+f(r1,r2,c1,j,h,v)+f(r1,r2,j,c2,h,v));
        return dp[r1][r2][c1][c2]=ans;
    }
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        // first by lets do it by dp
        memset(dp,-1,sizeof(dp));
        return f(0,m,0,n,horizontalCut,verticalCut);
    }
};