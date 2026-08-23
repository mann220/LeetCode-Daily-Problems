class Solution {
public:
    #define ll long long
    set<vector<int>> st;
    int n;
    vector<vector<int>> dp;
    bool check(long long n) {
        if(n<0) return false;
        ll val=sqrt(n);
        return (val*val==n);
    }
    int f(int mask,int last,vector<int> &nums){
        if(mask==((1<<n)-1)) return 1;
        if(dp[mask][last+1]!=-1) return dp[mask][last+1];
        int ans=0;
        for(int j=0;j<n;j++){
            if(mask & (1<<j)) continue;
            if(j>0 && nums[j]==nums[j-1] && !(mask & (1<<(j-1)))) continue;
            ll sum=-1;
            if(last!=-1) sum=nums[last]+nums[j]; 
            if(last==-1 || (check(sum))){
                ans+=f(mask | (1<<j),j,nums);
            }
        }
        return dp[mask][last+1]=ans;
    }
    int numSquarefulPerms(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        int sz=(1<<n);
        dp.assign(sz,vector<int>(n+1,-1));
        return f(0,-1,nums);
    }
};