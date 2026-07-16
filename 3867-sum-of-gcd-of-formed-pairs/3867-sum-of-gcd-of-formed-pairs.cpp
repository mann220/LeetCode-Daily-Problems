class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n);
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(nums[i],maxi);
            pre[i]=__gcd(nums[i],maxi);
        }
        sort(pre.begin(),pre.end());
        long long sum=0;
        for(int i=0;i<n/2;i++) sum+=__gcd(pre[i],pre[n-1-i]);
        return sum;
    }
};