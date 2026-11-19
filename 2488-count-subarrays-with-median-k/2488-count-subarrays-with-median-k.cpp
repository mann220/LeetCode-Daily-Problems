class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        int ind=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==k){
                ind=i;
                break;
            }
        }
        int diff=0;
        for(int i=ind+1;i<n;i++){
            if(nums[i]>k) diff++;
            else diff--;
            mpp[diff]++;
        }
        mpp[0]++;
        diff=0;
        int ans=0;
        for(int i=ind;i>=0;i--){
            if(nums[i]>k) diff++;
            else if(nums[i]<k) diff--;
            ans+=mpp[1-diff];
            ans+=mpp[0-diff];
        }
        return ans;
    }
};