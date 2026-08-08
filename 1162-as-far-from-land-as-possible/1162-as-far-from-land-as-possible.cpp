class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int> (m,INT_MAX));
        queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dist[i][j]=0;
                    pq.push({0,{i,j}});
                }
            }
        }
        if(pq.size()==m*n) return -1;
        vector<int> dr1={-1,0,1,0};
        vector<int> dr2={0,-1,0,1};
        int ans=INT_MIN;
        while(!pq.empty()){
            int d=pq.front().first;
            int i=pq.front().second.first;
            int j=pq.front().second.second;
            pq.pop();
            ans=max(ans,d);
            for(int k=0;k<4;k++){
                int ni=i+dr1[k];
                int nj=j+dr2[k];
                if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]==0){
                    if(d+1<dist[ni][nj]){
                        dist[ni][nj]=d+1;
                        pq.push({dist[ni][nj],{ni,nj}});
                    }
                }
            }
        }
        if(ans==INT_MIN) return -1; 
        return ans;
    }
};