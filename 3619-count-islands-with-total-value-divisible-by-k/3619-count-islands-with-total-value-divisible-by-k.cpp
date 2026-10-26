class Solution {
public: 
    #define ll long long
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>> &vis,ll &sum){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || grid[i][j]==0) return;
        vis[i][j]=true;
        sum+=grid[i][j];
        dfs(i+1,j,grid,vis,sum);
        dfs(i,j+1,grid,vis,sum);
        dfs(i-1,j,grid,vis,sum);
        dfs(i,j-1,grid,vis,sum);
        return;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ll sum=0;
                if(grid[i][j]!=0 && !vis[i][j]){
                    dfs(i,j,grid,vis,sum);
                    if(sum!=0 && sum%k==0) ans++;
                }
            }
        }
        return ans;
    }
};