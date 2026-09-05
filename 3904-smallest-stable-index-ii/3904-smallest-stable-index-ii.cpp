class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pre(n,-1),suf(n,-1);
        int mini=1e9,maxi=-1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            pre[i]=maxi;
        }
        for(int i=n-1;i>=0;i--){
            mini=min(mini,nums[i]);
            suf[i]=mini;
        }
        for(int i=0;i<n;i++){
            if(pre[i]-suf[i]<=k) return i;
        }
        return -1;
    }
};