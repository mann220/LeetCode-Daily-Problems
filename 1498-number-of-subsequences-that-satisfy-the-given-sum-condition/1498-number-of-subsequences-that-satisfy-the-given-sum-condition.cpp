class Solution {
public:
    int mod=1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        long long ans=0;
        sort(nums.begin(),nums.end());
        while(i<=j){
            int mini=nums[i];
            int maxi=nums[j];
            vector<int> power(n,1);
            for(int i=1;i<n;++i) power[i]=(power[i-1]*2)%mod;
            if(mini+maxi<=target){
                ans+=power[j-i];
                i++;
            }
            else j--;
        }
        return ans%mod;
    }
};