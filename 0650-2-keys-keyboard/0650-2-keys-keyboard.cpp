class Solution {
public:
    int n;
    vector<vector<int>> dp;
    // int f(int curr,int clip){
    //     if(curr==n) return 0;
    //     if(curr>n) return 1e9;
    //     if(dp[curr][clip]!=-1) return dp[curr][clip];
    //     // option 1 is copy all
    //     int copy=1e9;
    //     if(curr!=clip) copy=1+f(curr,curr);
    //     // option 2 is paste them
    //     int paste=1e9;
    //     if(clip>0){
    //         paste=1+f(curr+clip,clip);
    //     }
    //     return dp[curr][clip]=min(copy,paste);
    // }
    int minSteps(int n) {
        this->n=n;
        dp.assign(n+1,vector<int> (n+1,0));
        for(int i=n-1;i>=1;i--){
            for(int j=n-1;j>=0;j--){
                int copy=1e9,paste=1e9;
                if(i!=j) copy=1+dp[i][i];
                if(j>0 && i+j<=n) paste=1+dp[i+j][j];
                dp[i][j]=min(copy,paste);
            }
        }
        return dp[1][0];
    }
};