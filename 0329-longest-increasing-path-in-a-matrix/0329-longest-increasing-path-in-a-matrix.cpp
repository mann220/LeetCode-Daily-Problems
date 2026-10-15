class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int i,int j,vector<vector<int>> &matrix){
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> dr1={-1,0,1,0};
        vector<int> dr2={0,-1,0,1};
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=1;
        for(int k=0;k<4;k++){
            int ni=i+dr1[k];
            int nj=j+dr2[k];
            if(ni>=0 && nj>=0 && ni<n && nj<m && matrix[i][j]<matrix[ni][nj]){
                ans=max(ans,1+dfs(ni,nj,matrix));
            }
        }
        return dp[i][j]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        dp=vector<vector<int>> (n,vector<int> (m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) ans=max(ans,dfs(i,j,matrix));
        }
        return ans;
    }
};