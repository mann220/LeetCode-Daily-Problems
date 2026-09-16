class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n=tasks.size();
        vector<pair<int,int>> dp(1<<n,{1e9,1e9});
        dp[0]={1,0};
        for(int mask=0;mask<(1<<n);mask++){
            int sessions=dp[mask].first;
            int time=dp[mask].second;
            for(int i=0;i<n;i++){
                if(mask & (1<<i)) continue;
                int newmask=(mask | (1<<i));
                if(time+tasks[i]<=sessionTime) dp[newmask]=min(dp[newmask],{sessions,time+tasks[i]});
                else dp[newmask]=min(dp[newmask],{sessions+1,tasks[i]});
            }
        }
        return dp[(1<<n)-1].first;
    }
};