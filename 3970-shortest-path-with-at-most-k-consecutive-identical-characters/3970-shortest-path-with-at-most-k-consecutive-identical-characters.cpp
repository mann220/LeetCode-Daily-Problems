class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
            // adj[v].push_back({u,wt});
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>> dist(n,vector<int> (k,INT_MAX));
        while(!pq.empty()){
            int d=pq.top().first;
            int u=pq.top().second.first;
            int cnt=pq.top().second.second;
            pq.pop();
            if(cnt<k && u==n-1) return d;
            for(auto it:adj[u]){
                int v=it.first;
                int wt=it.second;
                int ncnt;
                if(labels[u]==labels[v]) ncnt=cnt+1;
                else ncnt=0;
                if(ncnt<k && d+wt<dist[v][ncnt]){
                    dist[v][ncnt]=d+wt;
                    pq.push({dist[v][ncnt],{v,ncnt}});
                }
            }
        }
        return -1;
    }
};