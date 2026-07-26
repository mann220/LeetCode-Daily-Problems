class Solution {
public:
#define ll long long
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        priority_queue<pair<pair<ll, int>, pair<int, int>>,vector<pair<pair<ll, int>, pair<int, int>>>,greater<>>pq;
        pq.push({{1, 0}, {0, 0}});
        vector<vector<vector<ll>>> dist(m,vector<vector<ll>>(n, vector<ll>(2, LLONG_MAX)));
        dist[0][0][0] = 1;
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!pq.empty()) {
            ll d = pq.top().first.first;
            int p = pq.top().first.second;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            if (d != dist[i][j][p]) continue;
            if (d!=LLONG_MAX && d+penalty[i][j] < dist[i][j][!p]) {
                dist[i][j][!p] = d+penalty[i][j];
                pq.push({{dist[i][j][!p], !p}, {i, j}});
            }
            for(auto [dx,dy]: dir){
                int nx=i+dx;
                int ny=j+dy;
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                ll cost=d+1LL*(nx+1)*(ny+1);
                bool valid;
                if(p==0) valid=(dx==1 || dy==1);
                else valid=(dx==-1 || dy==-1);
                if(!valid) cost+=penalty[i][j];
                if(cost<dist[nx][ny][!p]){
                    dist[nx][ny][!p]=cost;
                    pq.push({{dist[nx][ny][!p],!p},{nx,ny}});
                }
            }
        }
        return min(dist[m - 1][n - 1][0], dist[m - 1][n - 1][1]);
    }
};