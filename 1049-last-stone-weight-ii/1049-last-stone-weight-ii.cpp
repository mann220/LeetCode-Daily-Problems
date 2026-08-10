class Solution {
public:
    int n;
    int offset;
    vector<vector<int>> dp;
    // int f(int i,int sum,vector<int> &stones){
    //     if(i==n) return abs(sum);
    //     if(dp[i][sum+offset]!=-1) return dp[i][sum+offset];
    //     int pos=f(i+1,sum+stones[i],stones);
    //     int neg=f(i+1,sum-stones[i],stones);
    //     return dp[i][sum+offset]=min(pos,neg);
    // }
    int lastStoneWeightII(vector<int>& stones) {
        n=stones.size();
        offset=accumulate(stones.begin(),stones.end(),0);
        dp.assign(n+1,vector<int> (2*offset+1,0));
        for(int i=-offset;i<=offset;i++){
            dp[n][i+offset]=abs(i);
        }
        for(int i=n-1;i>=0;i--){
            for(int j=-offset;j<=offset;j++){
                int pos=INT_MAX,neg=INT_MAX;
                if(j+stones[i]<=offset) pos=dp[i+1][j+offset+stones[i]];
                if(j-stones[i]>=-offset) neg=dp[i+1][j+offset-stones[i]];
                dp[i][j+offset]=min(pos,neg);
            }
        }
        return dp[0][offset];
    }
};