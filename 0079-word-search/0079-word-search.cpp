class Solution {
public:
    vector<int> dr1={-1,0,1,0};
    vector<int> dr2={0,-1,0,1};
    int n,m,sz;
    vector<vector<bool>> vis;
    bool f(int i,int j,int k,vector<vector<char>>& board, string word){
        if(board[i][j]!=word[k]) return false;
        if(k==sz-1) return true;
        vis[i][j]=true;
        for(int l=0;l<4;l++){
            int ni=i+dr1[l];
            int nj=j+dr2[l];
            if(ni>=0 && nj>=0 && ni<n && nj<m && !vis[ni][nj]){
                if(f(ni,nj,k+1,board,word)) return true;
            }
        }
        vis[i][j]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        sz=word.size();
        vis.assign(n,vector<bool> (m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(f(i,j,0,board,word)) return true;
                }
            }
        }
        return false;
    }
};