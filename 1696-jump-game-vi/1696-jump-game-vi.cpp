class Solution {
public:
    //Priority_queue solution of O(nlogn)
    //     int n=nums.size();
    //     priority_queue<pair<int,int>> pq;
    //     vector<int> dp(n,0);
    //     dp[n-1]=nums[n-1];
    //     pq.push({dp[n-1],n-1});
    //     for(int i=n-2;i>=0;i--){
    //         while(!pq.empty() && pq.top().second>i+k) pq.pop();
    //         auto [val,ind]=pq.top();
    //         dp[i]=nums[i]+val;
    //         pq.push({dp[i],i});
    //     }
    //     return dp[0];

    // this priority queue solution has T.C=> O(nlogn) so we have to change it to O(n) by using Deque  
    int maxResult(vector<int>& nums, int k) {
        // BY DEQUE IN O(N)
        int n=nums.size();
        deque<int> dq;
        dq.push_back(n-1);
        vector<int> dp(n,0);
        dp[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            while(!dq.empty() && dq.front()>i+k) dq.pop_front();
            dp[i]=nums[i]+dp[dq.front()];
            while(!dq.empty() && dp[dq.back()]<=dp[i]) dq.pop_back();
            dq.push_back(i);
        }
        return dp[0];
    }
};