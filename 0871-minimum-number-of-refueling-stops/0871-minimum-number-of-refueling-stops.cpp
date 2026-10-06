class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int maxi=startFuel;
        int ans=0;
        int n=stations.size();
        int i=0;
        while(maxi<target){
            while(i<n && stations[i][0]<=maxi){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty()) return -1;
            maxi+=pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};