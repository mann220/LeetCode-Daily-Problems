class Solution {
public:
    /*
        here i am applying priority queue but this is wrong because it doesn't work,
        so my first observation is wrong so i can't do like this
        now the second approach is -->
        first we have to store all points which are greater than 1 and then apply dfs from each 
        node and we will add all see the code
    */
    int bfs(int i,int j,int tgti,int tgtj,vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        vector<vector<int>> dist(n,vector<int> (m,INT_MAX));
        dist[i][j]=0;
        vector<int> dr1={-1,0,1,0};
        vector<int> dr2={0,1,0,-1};
        while(!q.empty()){
            auto [rw,cl]=q.front();
            q.pop();
            if(rw==tgti && cl==tgtj) return dist[rw][cl];
            for(int k=0;k<4;k++){
                int ni=rw+dr1[k];
                int nj=cl+dr2[k];
                if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]!=0){
                    if(dist[rw][cl]!=INT_MAX && dist[rw][cl]+1<dist[ni][nj]){
                        dist[ni][nj]=1+dist[rw][cl];
                        q.push({ni,nj});
                    }
                }
            }
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        int n=forest.size();
        int m=forest[0].size();
        vector<vector<int>> v; // this will stores points which has value>1 those we have to go on
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(forest[i][j]>1){
                    v.push_back({forest[i][j],i,j});
                }
            }
        }
        sort(v.begin(),v.end());
        int sti=0,stj=0;
        int ans=0;
        for(int i=0;i<v.size();i++){
            int tgti=v[i][1];
            int tgtj=v[i][2];
            int cnt=bfs(sti,stj,tgti,tgtj,forest);
            // cout<<cnt<<"\n";
            if(cnt==-1) return -1;
            sti=tgti;
            stj=tgtj;
            ans+=cnt;
        } 
        return ans;
    }
};