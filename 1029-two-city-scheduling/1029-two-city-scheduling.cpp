class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;
    int f(int i,vector<vector<int>>& costs,int cnta,int cntb){
        if(i==n) return 0;
        if(dp[i][cnta][cntb]!=-1) return dp[i][cnta][cntb];
        int takea=INT_MAX,takeb=INT_MAX;
        if(cnta>0) takea=costs[i][0]+f(i+1,costs,cnta-1,cntb);
        if(cntb>0) takeb=costs[i][1]+f(i+1,costs,cnta,cntb-1);
        return dp[i][cnta][cntb]=min(takea,takeb);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        n=costs.size();
        dp.assign(n,vector<vector<int>>((n/2)+1,vector<int>((n/2)+1,-1)));
        return f(0,costs,n/2,n/2);
    }
};