class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int f(int curr,int clip){
        if(curr==n) return 0;
        if(curr>n) return 1e9;
        if(dp[curr][clip]!=-1) return dp[curr][clip];
        // option 1 is copy all
        int copy=1e9;
        if(curr!=clip) copy=1+f(curr,curr);
        // option 2 is paste them
        int paste=1e9;
        if(clip>0){
            paste=1+f(curr+clip,clip);
        }
        return dp[curr][clip]=min(copy,paste);
    }
    int minSteps(int n) {
        this->n=n;
        dp.assign(n,vector<int> (n,-1));
        return f(1,0);
    }
};