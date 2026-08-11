class Solution {
public:
    int n;
    int off=1001;
    vector<vector<int>> dp;
    // int f(int i,int last,vector<vector<int>>& pairs){
    //     if(i==n) return 0;
    //     if(dp[i][last+off]!=-1) return dp[i][last+off];
    //     int take=INT_MIN;
    //     if(pairs[i][0]>last) take=1+f(i+1,pairs[i][1],pairs);
    //     int nottake=f(i+1,last,pairs);
    //     return dp[i][last+off]=max(take,nottake);
    // }
    int findLongestChain(vector<vector<int>>& pairs) {
        n=pairs.size();
        sort(pairs.begin(),pairs.end());
        dp.assign(n+1,vector<int> (2002,0));
        for(int i=n-1;i>=0;i--){
            for(int j=-1001;j<=1000;j++){
                int take=INT_MIN;
                if(pairs[i][0]>j) take=1+dp[i+1][pairs[i][1]+off];
                int nottake=dp[i+1][j+off];
                dp[i][j+off]=max(take,nottake);
            }
        }
        return dp[0][0];
    }
};