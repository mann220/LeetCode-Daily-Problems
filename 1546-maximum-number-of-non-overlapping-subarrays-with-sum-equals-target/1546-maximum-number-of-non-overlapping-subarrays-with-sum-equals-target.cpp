class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        mpp[0]=1;
        int ans=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mpp.count(sum-target)){
                ans++;
                sum=0;
                mpp.clear();
                mpp[0]=1;
            }
            else{
                mpp[sum]=1;
            }
        }
        return ans;

    }
};