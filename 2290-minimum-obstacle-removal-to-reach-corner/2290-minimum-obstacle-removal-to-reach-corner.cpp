class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int> (m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
        pq.push({grid[0][0],{0,0}});
        vector<int> dr1={-1,0,1,0};
        vector<int> dr2={0,-1,0,1};
        while(!pq.empty()){
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            int d=pq.top().first;
            pq.pop();
            // if(d>dist[i][j]) continue;
            if(i==n-1 && j==m-1) return d;
            for(int k=0;k<4;k++){
                int ni=i+dr1[k];
                int nj=j+dr2[k];
                if(ni>=0 && nj>=0 && ni<n && nj<m){
                    if(d!=1e9 && d+grid[ni][nj]<dist[ni][nj]){
                        dist[ni][nj]=d+grid[ni][nj];
                        pq.push({dist[ni][nj],{ni,nj}});
                    }
                }
            }
        }
        return -1;
    }
};