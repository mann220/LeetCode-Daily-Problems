class Solution {
public:
    int mod=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int eve=1;
        int odd=0;
        long long sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum%2==0){
                ans=(ans+odd)%mod;
                eve++;
            }
            else{
                ans=(ans+eve)%mod;
                odd++;
            }
        }
        return ans%mod;
    }
};