class Solution {
public:
    #define ll long long
    long long maxPairStrength(vector<int>& nums) {
        int n=nums.size();
        ll ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ll val=1LL*nums[i]*nums[j];
                ll div=1LL*__gcd(nums[i],nums[j]);
                ll rdiv=1LL*div*div;
                ll val2=val/rdiv;
                ans=max(ans,val2);
            }
        }
        return ans;
    }
};