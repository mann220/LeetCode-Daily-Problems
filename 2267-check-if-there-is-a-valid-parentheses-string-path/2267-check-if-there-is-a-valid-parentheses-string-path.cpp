class Solution {
public:
    int dp[101][101][201];
    bool f(int i,int j,int opn,vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if(i>=n || j>=m || opn<0) return false;
        if(i==n-1 && j==m-1){
            if(grid[i][j]==')' && opn==1) return true;
            return false;
        }
        if(dp[i][j][opn]!=-1)  return dp[i][j][opn]; 
        bool ans=false;
        if(grid[i][j]=='('){
            ans=ans | f(i+1,j,opn+1,grid);
            ans=ans | f(i,j+1,opn+1,grid);
        }
        else{
            ans=ans | f(i+1,j,opn-1,grid);
            ans=ans | f(i,j+1,opn-1,grid);
        }
        return dp[i][j][opn]=ans;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,0,grid);
    }
};