class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int mini=nums[0],maxi=nums[n-1];
        int l=-1,r=-1;
        for(int i=1;i<n;i++){
            mini=max(mini,nums[i]);
            if(nums[i]<mini){
                r=i;
            }
        }
        for(int i=n-2;i>=0;i--){
            maxi=min(maxi,nums[i]);
            if(nums[i]>maxi){
                l=i;
            }
        }
        if(r==-1) return 0;
        return r-l+1;
    }
};