class Solution {
public:
    #define ll long long 
    int dp[201][201][201];
    int mod=1e9+7;
    int f(int i,int gcd1,int gcd2,vector<int> &nums){
        int n=nums.size();
        if(i==n) return (gcd1>0 && gcd1==gcd2);
        if(dp[i][gcd1][gcd2]!=-1) return dp[i][gcd1][gcd2];
        ll res=0;
        res+=f(i+1,gcd1,gcd2,nums);
        res+=f(i+1,__gcd(gcd1,nums[i]),gcd2,nums);
        res+=f(i+1,gcd1,__gcd(gcd2,nums[i]),nums);
        return dp[i][gcd1][gcd2]=res%mod;
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,0,nums);
    }
};