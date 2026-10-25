class Solution {
public:
    void dfs(int i,int j,vector<vector<bool>>& vis,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==1 || vis[i][j]) return;
        vis[i][j]=true;
        grid[i][j]=1;
        dfs(i+1,j,vis,grid);
        dfs(i,j+1,vis,grid);
        dfs(i-1,j,vis,grid);
        dfs(i,j-1,vis,grid);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && !vis[i][j] && grid[i][j]==0){
                    dfs(i,j,vis,grid);
                }
            }
        }
        vis=vector<vector<bool>> (n,vector<bool> (m,false));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && !vis[i][j]){
                    cnt++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};