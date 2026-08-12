class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        unordered_map<int,int> mpp;
        int i=0,j=0;
        int maxi=0;
        while(j<n){
            mpp[nums[j]]++;
            if(mpp[nums[j]]>k){
                while(nums[i]!=nums[j]){
                    mpp[nums[i]]--;
                    i++;
                }
                mpp[nums[i]]--;
                maxi=mpp[nums[i]];
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};