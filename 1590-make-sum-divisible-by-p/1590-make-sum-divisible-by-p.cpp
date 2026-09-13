class Solution {
public:
    #define ll long long
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        ll sum=0;
        for(int i=0;i<n;i++) sum=(sum+nums[i]%p);
        int target=sum%p;
        if(target==0) return 0;
        int curr=0;
        int mini=n;
        mpp[0]=-1;
        for(int i=0;i<nums.size();i++){
            curr=(curr+nums[i])%p;
            int need=(curr-target+p)%p;
            if(mpp.find(need)!=mpp.end()) mini=min(mini,i-mpp[need]);
            mpp[curr%p]=i;
        }
        return mini==n? -1:mini;
    }
};