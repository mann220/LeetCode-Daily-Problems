class Solution {
public:
    int mod=1e9+7;
    vector<vector<int>> dp;
    int f(int i,int j,vector<vector<int>> &grid){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m) return 0;
        if(i==n-1 && j==m-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(i+1<n && grid[i+1][j]==1){
            int ni=i+1;
            int nj=j;
            bool down=true;
            while(ni<n && nj<m && grid[ni][nj]==1){
                if(down) nj=nj+1;
                else ni=ni+1;
                down=!down;
            }
            ans=(ans+f(ni,nj,grid))%mod;
        }
        if(j+1<m && grid[i][j+1]==1){
            int ni=i;
            int nj=j+1;
            bool down=false;
            while(ni<n && nj<m && grid[ni][nj]==1){
                if(down) nj=nj+1;
                else ni=ni+1;
                down=!down;
            }
            ans=(ans+f(ni,nj,grid))%mod;
        }
        if(i+1<n && grid[i+1][j]==0) ans=(ans+f(i+1,j,grid))%mod;
        if(j+1<m && grid[i][j+1]==0) ans=(ans+f(i,j+1,grid))%mod;
        return dp[i][j]=ans%mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        dp=vector<vector<int>> (n,vector<int> (m,-1));
        return f(0,0,grid)%mod;
    }
};