class Solution {
public:
    int n;
    int offset;
    vector<vector<int>> dp;
    int f(int i,int sum,vector<int> &stones){
        if(i==n) return abs(sum);
        if(dp[i][sum+offset]!=-1) return dp[i][sum+offset];
        int pos=f(i+1,sum+stones[i],stones);
        int neg=f(i+1,sum-stones[i],stones);
        return dp[i][sum+offset]=min(pos,neg);
    }
    int lastStoneWeightII(vector<int>& stones) {
        n=stones.size();
        offset=accumulate(stones.begin(),stones.end(),0);
        dp.assign(n,vector<int> (2*offset+1,-1));
        return f(0,0,stones);
    }
};