class Solution {
public:
    vector<int> dr1={-1,0,1,0};
    vector<int> dr2={0,-1,0,1};
    vector<int> vis;
    vector<int> parent;
    int n,m;
    bool dfs(int i,int j,vector<vector<char>> &grid){
        vis[m*i+j]=1;
        for(int k=0;k<4;k++){
            int ni=i+dr1[k];
            int nj=j+dr2[k];
            if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]==grid[i][j]){
                if(!vis[ni*m+nj]){
                    parent[ni*m+nj]=m*i+j;
                    if(dfs(ni,nj,grid)) return true;
                }
                else if(ni*m+nj!=parent[m*i+j]){
                    return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vis.assign(m*n,0);
        parent.assign(m*n,-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[m*i+j]){
                    if(dfs(i,j,grid)) return true;
                }
            }
        }
        return false;
    }
};