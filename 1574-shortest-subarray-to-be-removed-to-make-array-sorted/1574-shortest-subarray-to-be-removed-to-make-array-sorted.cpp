class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        while(l+1<n && nums[l]<=nums[l+1]) l++;
        if(l==n-1) return 0;
        int r=n-1;
        while(r-2>=0 && nums[r]>=nums[r-1]) r--;
        int i=0;
        int j=r;
        int ans=n-l-1;
        ans=min(ans,r);
        while(i<=l && j<n){
            if(nums[i]<=nums[j]){
                ans=min(ans,j-i-1);
                i++;
            } else{
                j++;
            }
        }
        return ans;
    }
};