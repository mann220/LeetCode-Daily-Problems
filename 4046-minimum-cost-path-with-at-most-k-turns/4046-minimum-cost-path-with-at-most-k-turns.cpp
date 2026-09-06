class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        vector<vector<vector<int>>> vis(n,vector<vector<int>> (m,vector<int> (4,-1)));
        for(int d=0;d<4;d++){
            pq.push({grid[0][0],k,d,0,0});
            vis[0][0][d]=k;
        }
        vector<int> dr1={0,0,-1,1};
        vector<int> dr2={-1,1,0,0};
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int d=curr[0];
            int val=curr[1];
            int cnt=curr[2];
            int i=curr[3];
            int j=curr[4];
            if(i==n-1 && j==m-1) return d;
            for(int l=0;l<4;l++){
                int ni=i+dr1[l];
                int nj=j+dr2[l];
                if(ni>=0 && nj>=0 && ni<n && nj<m){
                    int nxtval;
                    if(cnt==l) nxtval=val;
                    else nxtval=val-1;
                    if(nxtval>=0 && nxtval>vis[ni][nj][l]){
                        vis[ni][nj][l]=nxtval;
                        pq.push({d+grid[ni][nj],nxtval,l,ni,nj});
                    }
                }
            }
        }
        return -1;
    }
};