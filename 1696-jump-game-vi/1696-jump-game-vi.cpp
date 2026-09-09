class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int,int>> pq;
        vector<int> dp(n,0);
        dp[n-1]=nums[n-1];
        pq.push({dp[n-1],n-1});
        for(int i=n-2;i>=0;i--){
            while(!pq.empty() && pq.top().second>i+k) pq.pop();
            auto [val,ind]=pq.top();
            dp[i]=nums[i]+dp[ind];
            pq.push({dp[i],i});
        }
        return dp[0];
    }
};