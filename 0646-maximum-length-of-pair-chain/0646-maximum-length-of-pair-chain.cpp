class Solution {
public:
    int n;
    int off=1001;
    vector<vector<int>> dp;
    int f(int i,int last,vector<vector<int>>& pairs){
        if(i==n) return 0;
        if(dp[i][last+off]!=-1) return dp[i][last+off];
        int take=INT_MIN;
        if(pairs[i][0]>last) take=1+f(i+1,pairs[i][1],pairs);
        int nottake=f(i+1,last,pairs);
        return dp[i][last+off]=max(take,nottake);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        n=pairs.size();
        sort(pairs.begin(),pairs.end());
        dp.assign(n+1,vector<int> (2002,-1));
        return f(0,-1001,pairs);
    }
};