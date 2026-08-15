class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        bool flg=false;
        int xr=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0) flg=true;
            xr^=nums[i];
        }
        if(flg==false) return 0;
        if(xr!=0) return n;
        return n-1;
    }
};