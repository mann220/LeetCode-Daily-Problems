class Solution {
public:
    int dp[51][51][51];
    // to convert this 4 state to three state we do an optimisation as both move equal steps so total steps
    // is i1+j1 and for getting j2=i1+j1-i2;
    int f(int i1,int j1,int i2,vector<vector<int>> &grid){
        int n=grid.size();
        int m=grid[0].size();
        int j2=i1+j1-i2;
        if(i1>=n || j1>=m || i2>=n || j2>=m || grid[i1][j1]==-1 || grid[i2][j2]==-1) return -1e9;
        if(i1==n-1 && j1==m-1 && i2==n-1 && j2==m-1) return grid[i1][j1];
        if(dp[i1][j1][i2]!=-1) return dp[i1][j1][i2];
        int ans=-1e9;
        int opt1=f(i1+1,j1,i2+1,grid);  // both down
        int opt2=f(i1+1,j1,i2,grid);    // one down two rght
        int opt3=f(i1,j1+1,i2,grid);    // both rght
        int opt4=f(i1,j1+1,i2+1,grid);  // one rght two down
        if(opt1==-1e9 && opt2==-1e9 && opt3==-1e9 && opt4==-1e9) return dp[i1][j1][i2]=-1e9;
        int val=0;
        if(i1==i2 && j1==j2) val+=grid[i1][j1];
        else val+=(grid[i1][j1]+grid[i2][j2]); 
        ans=val+max({opt1,opt2,opt3,opt4});
        return dp[i1][j1][i2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int ans=f(0,0,0,grid);
        if(ans==-1e9) return 0;
        return ans;
    }
};