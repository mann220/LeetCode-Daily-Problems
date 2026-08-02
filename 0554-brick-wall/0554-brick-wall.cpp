class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n=wall.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            long long sum=0;
            for(int j=0;j<wall[i].size()-1;j++){
                sum+=wall[i][j];
                mpp[sum]++;
            }
        }
        int ans=0;
        for(auto it:mpp){
            ans=max(ans,it.second);
        }
        return n-ans;
    }
};