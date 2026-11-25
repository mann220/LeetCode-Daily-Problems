class Solution {
public:
    #define ll long long
    bool rollHash(vector<int> &nums,int len){
        int n=nums.size();
        ll base=1e5+7;
        ll mod=1e9+7;
        unordered_map<ll,int> mpp;
        ll maxi=1;
        for(int i=0;i<len;i++) maxi=(maxi*base)%mod;
        ll val=0;
        ll factor=1;
        for(int i=len-1;i>=0;i--){
            val=(val+(nums[i]*factor))%mod;
            factor=(factor*base)%mod;
        }
        mpp[val]++;
        for(int i=1;i<=(n-len);i++){
            val=((val*base)%mod-(nums[i-1]*maxi)%mod+nums[i+len-1]+mod)%mod;
            mpp[val]++;
        }
        for(auto it:mpp){
            if(it.second==1) return true;
        }
        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int lo=1;
        int hi=nums.size();
        int ans=nums.size();
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(rollHash(nums,mid)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};