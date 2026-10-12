class Solution {
public:
    int mod=1e9+7;
    int maxSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> cnt(32,0);
        for(int i=0;i<32;i++){
            for(int j=0;j<nums.size();j++){
                if(nums[j]&(1<<i)) cnt[i]++;
            }
        }
        long long ans=0;
        while(k>0){
            int num=0;
            for(int i=0;i<32;i++){
                if(cnt[i]>0){
                    num+=(1<<i);
                    cnt[i]--;
                }
            }
            ans=(ans+(1LL*num*num)%mod)%mod;
            k--;
        }
        return (int)ans;
    }
};