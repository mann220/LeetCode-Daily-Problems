class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<costs.size();i++){
            pq.push({costs[i][0]-costs[i][1],i});
        }
        int sum=0;
        int half=n/2;
        while(half--){
            int i=pq.top().second;
            pq.pop();
            sum+=(costs[i][1]);
        }
        while(!pq.empty()){
            int i=pq.top().second;
            pq.pop();
            sum+=(costs[i][0]);
        }
        return sum;
    }
};