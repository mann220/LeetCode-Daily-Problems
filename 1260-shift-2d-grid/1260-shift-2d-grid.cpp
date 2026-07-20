class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> ans(n,vector<int> (m));
        deque<int> dq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) dq.push_back(grid[i][j]);
        }
        while(k--){
            int val=dq.back();
            dq.pop_back();
            dq.push_front(val);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=dq.front();
                dq.pop_front();
            }
        }
        return ans;
    }
};