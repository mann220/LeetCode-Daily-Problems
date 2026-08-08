class Solution {
public:
    int mod=1e9+7;
    long long power(long long n,long long k){
        if(k<=0) return 1;
        long long ans=1;
        while(k){
            if(k&1) ans=(n*ans)%mod;
            n=(n*n)%mod;
            k>>=1;
        }
        return ans;
    }
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        long long ans=0;
        sort(nums.begin(),nums.end());
        while(i<=j){
            int mini=nums[i];
            int maxi=nums[j];
            if(mini+maxi<=target){
                ans+=power(2,j-i);
                i++;
            }
            else j--;
        }
        return ans%mod;
    }
};