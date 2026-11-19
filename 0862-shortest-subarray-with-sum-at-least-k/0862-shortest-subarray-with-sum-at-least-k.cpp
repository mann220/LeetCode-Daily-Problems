class Solution {
public:
    #define ll long long
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=n+1;
        ll sum=0;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> pq;
        pq.push({0,-1});
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(!pq.empty() && (sum-pq.top().first)>=k){
                ans=min(1LL*ans,1LL*i-pq.top().second);
                pq.pop();
            }
            pq.push({sum,i});
        }
        return ans==n+1 ? -1:ans;
    }
};