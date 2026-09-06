class Solution {
public:
    // dir=0 -> left , dir=1-> right, dir=2-> up, dir=3-> down
    int dp[75][75][75][5];
    int f(int i,int j,int k,int dir,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m) return 1e9;
        if(i==n-1 && j==m-1) return grid[i][j];
        if(dp[i][j][k][dir]!=-1) return dp[i][j][k][dir];
        int ans=1e9;
        if(dir==4 || dir==0){
            ans=min(ans,grid[i][j]+f(i,j-1,k,0,grid));
            if(k>0) ans=min(ans,grid[i][j]+f(i,j+1,k-1,1,grid));
            if(k>0) ans=min(ans,grid[i][j]+f(i-1,j,k-1,2,grid));
            if(k>0) ans=min(ans,grid[i][j]+f(i+1,j,k-1,3,grid));
        }
        if(dir==4 || dir==1){
            if(k>0) ans=min(ans,grid[i][j]+f(i,j-1,k-1,0,grid));
            ans=min(ans,grid[i][j]+f(i,j+1,k,1,grid));
            if(k>0) ans=min(ans,grid[i][j]+f(i-1,j,k-1,2,grid));
            if(k>0) ans=min(ans,grid[i][j]+f(i+1,j,k-1,3,grid));
        }
        if(dir==4 || dir==2){
            if(k>0) ans=min(ans,grid[i][j]+f(i,j-1,k-1,0,grid));
            if(k>0) ans=min(ans,grid[i][j]+f(i,j+1,k-1,1,grid));
            ans=min(ans,grid[i][j]+f(i-1,j,k,2,grid));
            if(k>0) ans=min(ans,grid[i][j]+f(i+1,j,k-1,3,grid));
        }
        if(dir==4 || dir==3){
            if(k>0) ans=min(ans,grid[i][j]+f(i,j-1,k-1,0,grid));
            if(k>0) ans=min(ans,grid[i][j]+f(i,j+1,k-1,1,grid));
            if(k>0) ans=min(ans,grid[i][j]+f(i-1,j,k-1,2,grid));
            ans=min(ans,grid[i][j]+f(i+1,j,k,3,grid));
        }
        return dp[i][j][k][dir]=ans;
    }
    int minCost(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        int ans=f(0,0,k,4,grid);
        if(ans==1e9) return -1;
        return ans;
    }
};